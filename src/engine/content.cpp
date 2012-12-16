#include <engine/content.h>
#include <engine/shader.h>

using namespace std;

cub::Content::Content()
{
    _path = "./";
}

cub::Content::Content(string path)
{
    _path = path + "/";
}

int cub::Content::LoadTexture(string filename)
{
    /*
    if (String.IsNullOrEmpty(filename))
        throw new ArgumentException(filename);

    filename = _path + filename;

    int id = GL.GenTexture();
    GL.BindTexture(TextureTarget.Texture2D, id);

    Bitmap bmp = new Bitmap(filename);
    BitmapData bmp_data = bmp.LockBits(new Rectangle(0, 0, bmp.Width, bmp.Height), ImageLockMode.ReadOnly, System.Drawing.Imaging.PixelFormat.Format32bppArgb);

    GL.TexImage2D(TextureTarget.Texture2D, 0, PixelInternalFormat.Rgba, bmp_data.Width, bmp_data.Height, 0,
        OpenTK.Graphics.OpenGL.PixelFormat.Bgra, PixelType.UnsignedByte, bmp_data.Scan0);

    bmp.UnlockBits(bmp_data);

    // We haven't uploaded mipmaps, so disable mipmapping (otherwise the texture will not appear).
    // On newer video cards, we can use GL.GenerateMipmaps() or GL.Ext.GenerateMipmaps() to create
    // mipmaps automatically. In that case, use TextureMinFilter.LinearMipmapLinear to enable them.
    GL.GenerateMipmap(GenerateMipmapTarget.Texture2D);
    GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureMinFilter, (int)TextureMinFilter.LinearMipmapLinear);
    GL.TexParameter(TextureTarget.Texture2D, TextureParameterName.TextureMagFilter, (int)TextureMagFilter.Linear);

    return id;
    */

    return -1;
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

cub::ShaderProgram cub::Content::LoadShaders(string fileVert, string fileFrag)
{
    fileVert = _path + fileVert;
    fileFrag = _path + fileFrag;


    Shader vertexShader(Shader::Vertex);
    vertexShader.LoadFile(fileVert);

    Shader fragmentShader(Shader::Fragment);
    fragmentShader.LoadFile(fileFrag);

    ShaderProgram shader;
    shader.AttachShader(vertexShader);
    shader.AttachShader(fragmentShader);
    shader.Link();
    shader.Bind();

    return shader;
}

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