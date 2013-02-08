#include <engine/content.h>
#include <engine/shader.h>
#include <engine/game.h>

#include <freeimage/FreeImage.h>

#include <nv_dds/nv_dds.h>
using namespace nv_dds;

using namespace std;

cub::Content::Content()
{
    _path = "./";
}

cub::Content::Content(string path)
{
    _path = path + "/";
}

cub::Content::~Content()
{
    for (map<string, ShaderProgram*>::iterator it = _cachedShaders.begin(); it != _cachedShaders.end(); ++it)
    {
        delete it->second;
    }
}

std::string cub::Content::GetPath() const
{
    return _path;
}

int cub::Content::LoadDDSTexture(string filename)
{
    filename = _path + filename;
    
    if (_cachedTextures.find(filename) != _cachedTextures.end())
        return _cachedTextures[filename];

    CDDSImage image;
    bool b = image.load(filename);
    (void)b;

    GLuint gl_texID = -1;
    gl::GenTextures(1, &gl_texID);
    gl::BindTexture(gl::TEXTURE_2D, gl_texID);

    gl::CompressedTexImage2D(gl::TEXTURE_2D, 0, image.get_format(), 
        image.get_width(), image.get_height(), 0, image.get_size(), 
        image);

    for (unsigned int i = 0; i < image.get_num_mipmaps(); i++)
    {
        CSurface mipmap = image.get_mipmap(i);

        gl::CompressedTexImage2D(gl::TEXTURE_2D, i+1, image.get_format(), 
            mipmap.get_width(), mipmap.get_height(), 0, mipmap.get_size(), 
            mipmap);
    }

    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MAG_FILTER, gl::LINEAR_MIPMAP_LINEAR);
    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, gl::LINEAR_MIPMAP_LINEAR);
    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, gl::CLAMP_TO_EDGE);
    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, gl::CLAMP_TO_EDGE);

    // cache
    _cachedTextures[filename] = gl_texID;

    //return success
    return gl_texID;
}

int cub::Content::LoadTexture(string filename)
{
    filename = _path + filename;
    
    if (_cachedTextures.find(filename) != _cachedTextures.end())
        return _cachedTextures[filename];
	
	//check the file signature and deduce its format
    FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(filename.c_str(), 0);
	//if still unknown, try to guess the file format from the file extension
	if (fif == FIF_UNKNOWN) 
		fif = FreeImage_GetFIFFromFilename(filename.c_str());
	//if still unkown, return failure
	if (fif == FIF_UNKNOWN)
		return -1;

	//check that the plugin has reading capabilities and load the file
    FIBITMAP *dib;
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, filename.c_str());
	//if the image failed to load, return failure
	if (!dib)
		return -1;

    FIBITMAP *converted = FreeImage_ConvertTo32Bits(dib);
    
	//retrieve the image data
	BYTE* bits = FreeImage_GetBits(converted);
	//get the image width and height
	unsigned int width = FreeImage_GetWidth(converted);
	unsigned int height = FreeImage_GetHeight(converted);
	//if this somehow one of these failed (they shouldn't), return failure
	if ((bits == 0) || (width == 0) || (height == 0))
		return -1;
	
	//if this texture ID is in use, unload the current texture
	//if(m_texID.find(texID) != m_texID.end())
	//	glDeleteTextures(1, &(m_texID[texID]));

    GLuint gl_texID = -1;
	//generate an OpenGL texture ID for this texture
	gl::GenTextures(1, &gl_texID);
	//store the texture ID mapping
	//m_texID[texID] = gl_texID;
	//bind to the new texture ID
	gl::BindTexture(gl::TEXTURE_2D, gl_texID);
	//store the texture data for OpenGL use
	gl::TexImage2D(gl::TEXTURE_2D, 0, gl::RGBA, width, height, 0, gl::BGRA, gl::UNSIGNED_BYTE, bits); // TODO pixel format
    gl::GenerateMipmap(gl::TEXTURE_2D);
    //gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MAG_FILTER, gl::NEAREST);
    //gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, gl::NEAREST);
    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MAG_FILTER, gl::LINEAR_MIPMAP_LINEAR);
    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, gl::LINEAR_MIPMAP_LINEAR);
    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, gl::CLAMP_TO_EDGE);
    gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, gl::CLAMP_TO_EDGE);
    //GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureMinFilter, (int)TextureMinFilter.LinearMipmapLinear);
    //GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureMagFilter, (int)TextureMagFilter.Linear);

	//Free FreeImage's copy of the data
	FreeImage_Unload(dib);
	FreeImage_Unload(converted);

    // cache
    _cachedTextures[filename] = gl_texID;

	//return success
	return gl_texID;
}

void cub::Content::LoadCubeMap(GLenum target, string filename)
{
    /*
    Bitmap bmp = new Bitmap(filename);
    BitmapData bmp_data = bmp.LockBits(new Rectangle(0, 0, bmp.Width, bmp.Height), ImageLockMode.ReadOnly, System.Drawing.Imaging.PixelFormat.Format32bppArgb);

    GL.TexImage2D(target, 0, PixelInternalFormat.Rgba, bmp_data.Width, bmp_data.Height, 0,
        OpenTK.Graphics.OpenGL.PixelFormat.Bgra, PixelType.UnsignedByte, bmp_data.Scan0);

    bmp.UnlockBits(bmp_data);
    */
}

int cub::Content::LoadSkyBox(string filename)
{
    /*
    if (String.IsNullOrEmpty(filename))
        throw new ArgumentException(filename);

    filename = _path + filename;
    var extension = Path.GetExtension(filename);
    var file = Path.GetDirectoryName(filename) + "/" + Path.GetFileNameWithoutExtension(filename);

    int id = GL.GenTexture();
    GL.BindTexture(TextureTarget.TextureCubeMap, id);
    LoadCubeMap(TextureTarget.TextureCubeMapPositiveX, file + "_xpos" + extension);
    LoadCubeMap(TextureTarget.TextureCubeMapNegativeX, file + "_xneg" + extension);
    LoadCubeMap(TextureTarget.TextureCubeMapPositiveY, file + "_ypos" + extension);
    LoadCubeMap(TextureTarget.TextureCubeMapNegativeY, file + "_yneg" + extension);
    LoadCubeMap(TextureTarget.TextureCubeMapPositiveZ, file + "_zpos" + extension);
    LoadCubeMap(TextureTarget.TextureCubeMapNegativeZ, file + "_zneg" + extension);

    // We haven't uploaded mipmaps, so disable mipmapping (otherwise the texture will not appear).
    // On newer video cards, we can use GL.GenerateMipmaps() or GL.Ext.GenerateMipmaps() to create
    // mipmaps automatically. In that case, use TextureMinFilter.LinearMipmapLinear to enable them.
    //GL.GenerateMipmap(GenerateMipmapTarget.TextureCubeMap);
    GL.TexParameter(TextureTarget.TextureCubeMap, TextureParameterName.TextureMinFilter, (int)TextureMinFilter.Nearest);
    GL.TexParameter(TextureTarget.TextureCubeMap, TextureParameterName.TextureMagFilter, (int)TextureMagFilter.Nearest);
    GL.TexParameter(TextureTarget.TextureCubeMap, TextureParameterName.TextureWrapS, (int)TextureWrapMode.ClampToEdge);
    GL.TexParameter(TextureTarget.TextureCubeMap, TextureParameterName.TextureWrapR, (int)TextureWrapMode.ClampToEdge);
    GL.TexParameter(TextureTarget.TextureCubeMap, TextureParameterName.TextureWrapT, (int)TextureWrapMode.ClampToEdge);

    return id;
    */

    return -1;
}

cub::ShaderProgram* cub::Content::LoadShaders(string fileVert, string fileFrag)
{
    fileVert = _path + fileVert;
    fileFrag = _path + fileFrag;

    string id = fileVert + "|" + fileFrag;

    if (_cachedShaders.find(id) != _cachedShaders.end())
        return _cachedShaders[id];

    Shader vertexShader(Shader::Vertex);
    vertexShader.LoadFile(fileVert);

    Shader fragmentShader(Shader::Fragment);
    fragmentShader.LoadFile(fileFrag);

    ShaderProgram *shader = new ShaderProgram();
    shader->AttachShader(vertexShader);
    shader->AttachShader(fragmentShader);
    shader->Link();
    shader->Bind();

    _cachedShaders[id] = shader;

    return shader;
}

/*
cub::ShaderProgram cub::Content::LoadShaders(string fileVert, string fileGeom, string fileFrag)
{
    fileVert = _path + fileVert;
    fileGeom = _path + fileGeom;
    fileFrag = _path + fileFrag;


    Shader vertexShader(Shader::Vertex);
    vertexShader.LoadFile(fileVert);

    Shader geometryShader(Shader::Geometry);
    geometryShader.LoadFile(fileGeom);

    Shader fragmentShader(Shader::Fragment);
    fragmentShader.LoadFile(fileFrag);

    ShaderProgram shader;
    shader.AttachShader(vertexShader);
    shader.AttachShader(geometryShader);
    shader.AttachShader(fragmentShader);
    shader.Link();
    shader.Bind();

    return shader;
}
*/