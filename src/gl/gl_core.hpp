#ifndef POINTER_CPP_GENERATED_HEADEROPENGL_HPP
#define POINTER_CPP_GENERATED_HEADEROPENGL_HPP

#if defined(__gl_h_) || defined(__GL_H__)
#error Attempt to include auto-generated header after including gl.h
#endif
#if defined(__glext_h_) || defined(__GLEXT_H_)
#error Attempt to include auto-generated header after including glext.h
#endif
#if defined(__gl_ATI_h_)
#error Attempt to include auto-generated header after including glATI.h
#endif

#define __gl_h_
#define __GL_H__
#define __glext_h_
#define __GLEXT_H_
#define __gl_ATI_h_

#ifndef APIENTRY
	#if defined(__MINGW32__)
		#ifndef WIN32_LEAN_AND_MEAN
			#define WIN32_LEAN_AND_MEAN 1
		#endif
		#ifndef NOMINMAX
			#define NOMINMAX
		#endif
		#include <windows.h>
	#elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) || defined(__BORLANDC__)
		#ifndef WIN32_LEAN_AND_MEAN
			#define WIN32_LEAN_AND_MEAN 1
		#endif
		#ifndef NOMINMAX
			#define NOMINMAX
		#endif
		#include <windows.h>
	#else
		#define APIENTRY
	#endif
#endif /*APIENTRY*/

#ifndef CODEGEN_FUNCPTR
	#define CODEGEN_REMOVE_FUNCPTR
	#if defined(_WIN32)
		#define CODEGEN_FUNCPTR APIENTRY
	#else
		#define CODEGEN_FUNCPTR
	#endif
#endif /*CODEGEN_FUNCPTR*/

#ifndef GLAPI
	#define GLAPI extern
#endif


#ifndef GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS
#define GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS

	typedef unsigned int GLenum;
	typedef unsigned char GLboolean;
	typedef unsigned int GLbitfield;
	typedef signed char GLbyte;
	typedef short GLshort;
	typedef int GLint;
	typedef int GLsizei;
	typedef unsigned char GLubyte;
	typedef unsigned short GLushort;
	typedef unsigned int GLuint;
	typedef float GLfloat;
	typedef float GLclampf;
	typedef double GLdouble;
	typedef double GLclampd;
	#define GLvoid void

#endif /*GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS*/

#include <stddef.h>
#ifndef GL_VERSION_2_0
	/* GL type for program/shader text */
	typedef char GLchar;
#endif
#ifndef GL_VERSION_1_5
	/* GL types for handling large vertex buffer objects */
	typedef ptrdiff_t GLintptr;
	typedef ptrdiff_t GLsizeiptr;
#endif
#ifndef GL_ARB_vertex_buffer_object
	/* GL types for handling large vertex buffer objects */
	typedef ptrdiff_t GLintptrARB;
	typedef ptrdiff_t GLsizeiptrARB;
#endif
#ifndef GL_ARB_shader_objects
	/* GL types for program/shader text and shader object handles */
	typedef char GLcharARB;
	typedef unsigned int GLhandleARB;
#endif
/* GL type for "half" precision (s10e5) float data in host memory */
#ifndef GL_ARB_half_float_pixel
	typedef unsigned short GLhalfARB;
#endif
#ifndef GL_NV_half_float
	typedef unsigned short GLhalfNV;
#endif
#ifndef GLEXT_64_TYPES_DEFINED
	/* This code block is duplicated in glxext.h, so must be protected */
	#define GLEXT_64_TYPES_DEFINED
	/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
	/* (as used in the GL_EXT_timer_query extension). */
	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
		#include <inttypes.h>
	#elif defined(__sun__) || defined(__digital__)
		#include <inttypes.h>
		#if defined(__STDC__)
			#if defined(__arch64__) || defined(_LP64)
				typedef long int int64_t;
				typedef unsigned long int uint64_t;
				#else
				typedef long long int int64_t;
				typedef unsigned long long int uint64_t;
			#endif /* __arch64__ */
		#endif /* __STDC__ */
	#elif defined( __VMS ) || defined(__sgi)
		#include <inttypes.h>
	#elif defined(__SCO__) || defined(__USLC__)
		#include <stdint.h>
	#elif defined(__UNIXOS2__) || defined(__SOL64__)
		typedef long int int32_t;
		typedef long long int int64_t;
		typedef unsigned long long int uint64_t;
	#elif defined(_WIN32) && defined(__GNUC__)
		#include <stdint.h>
	#elif defined(_WIN32)
		typedef __int32 int32_t;
		typedef __int64 int64_t;
		typedef unsigned __int64 uint64_t;
		#else
		/* Fallback if nothing above works */
		#include <inttypes.h>
	#endif
#endif
#ifndef GL_EXT_timer_query
	typedef int64_t GLint64EXT;
	typedef uint64_t GLuint64EXT;
#endif
#ifndef GL_ARB_sync
	typedef int64_t GLint64;
	typedef uint64_t GLuint64;
	typedef struct __GLsync *GLsync;
#endif
#ifndef GL_ARB_cl_event
	/* These incomplete types let us declare types compatible with OpenCL's cl_context and cl_event */
	struct _cl_context;
	struct _cl_event;
#endif
#ifndef GL_ARB_debug_output
	typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,GLvoid *userParam);
#endif
#ifndef GL_AMD_debug_output
	typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,GLvoid *userParam);
#endif
#ifndef GL_KHR_debug
	typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,GLvoid *userParam);
#endif
#ifndef GL_NV_vdpau_interop
	typedef GLintptr GLvdpauSurfaceNV;
#endif

namespace gl
{
	namespace exts
	{
		class LoadTest
		{
		private:
			//Safe bool idiom. Joy!
			typedef void (LoadTest::*bool_type)() const;
			void big_long_name_that_really_doesnt_matter() const {}
			
		public:
			operator bool_type() const
			{
				return m_isLoaded ? &LoadTest::big_long_name_that_really_doesnt_matter : 0;
			}
			
			int GetNumMissing() const {return m_numMissing;}
			
			LoadTest() : m_isLoaded(false), m_numMissing(0) {}
			LoadTest(bool isLoaded, int numMissing) : m_isLoaded(isLoaded), m_numMissing(numMissing) {}
		private:
			bool m_isLoaded;
			int m_numMissing;
		};
		
	} //namespace exts
	enum
	{
		DEPTH_BUFFER_BIT                 = 0x00000100,
		STENCIL_BUFFER_BIT               = 0x00000400,
		COLOR_BUFFER_BIT                 = 0x00004000,
		FALSE_                           = 0,
		TRUE_                            = 1,
		POINTS                           = 0x0000,
		LINES                            = 0x0001,
		LINE_LOOP                        = 0x0002,
		LINE_STRIP                       = 0x0003,
		TRIANGLES                        = 0x0004,
		TRIANGLE_STRIP                   = 0x0005,
		TRIANGLE_FAN                     = 0x0006,
		QUADS                            = 0x0007,
		NEVER                            = 0x0200,
		LESS                             = 0x0201,
		EQUAL                            = 0x0202,
		LEQUAL                           = 0x0203,
		GREATER                          = 0x0204,
		NOTEQUAL                         = 0x0205,
		GEQUAL                           = 0x0206,
		ALWAYS                           = 0x0207,
		ZERO                             = 0,
		ONE                              = 1,
		SRC_COLOR                        = 0x0300,
		ONE_MINUS_SRC_COLOR              = 0x0301,
		SRC_ALPHA                        = 0x0302,
		ONE_MINUS_SRC_ALPHA              = 0x0303,
		DST_ALPHA                        = 0x0304,
		ONE_MINUS_DST_ALPHA              = 0x0305,
		DST_COLOR                        = 0x0306,
		ONE_MINUS_DST_COLOR              = 0x0307,
		SRC_ALPHA_SATURATE               = 0x0308,
		NONE                             = 0,
		FRONT_LEFT                       = 0x0400,
		FRONT_RIGHT                      = 0x0401,
		BACK_LEFT                        = 0x0402,
		BACK_RIGHT                       = 0x0403,
		FRONT                            = 0x0404,
		BACK                             = 0x0405,
		LEFT                             = 0x0406,
		RIGHT                            = 0x0407,
		FRONT_AND_BACK                   = 0x0408,
		NO_ERROR_                        = 0,
		INVALID_ENUM                     = 0x0500,
		INVALID_VALUE                    = 0x0501,
		INVALID_OPERATION                = 0x0502,
		OUT_OF_MEMORY                    = 0x0505,
		CW                               = 0x0900,
		CCW                              = 0x0901,
		POINT_SIZE                       = 0x0B11,
		POINT_SIZE_RANGE                 = 0x0B12,
		POINT_SIZE_GRANULARITY           = 0x0B13,
		LINE_SMOOTH                      = 0x0B20,
		LINE_WIDTH                       = 0x0B21,
		LINE_WIDTH_RANGE                 = 0x0B22,
		LINE_WIDTH_GRANULARITY           = 0x0B23,
		POLYGON_MODE                     = 0x0B40,
		POLYGON_SMOOTH                   = 0x0B41,
		CULL_FACE                        = 0x0B44,
		CULL_FACE_MODE                   = 0x0B45,
		FRONT_FACE                       = 0x0B46,
		DEPTH_RANGE                      = 0x0B70,
		DEPTH_TEST                       = 0x0B71,
		DEPTH_WRITEMASK                  = 0x0B72,
		DEPTH_CLEAR_VALUE                = 0x0B73,
		DEPTH_FUNC                       = 0x0B74,
		STENCIL_TEST                     = 0x0B90,
		STENCIL_CLEAR_VALUE              = 0x0B91,
		STENCIL_FUNC                     = 0x0B92,
		STENCIL_VALUE_MASK               = 0x0B93,
		STENCIL_FAIL                     = 0x0B94,
		STENCIL_PASS_DEPTH_FAIL          = 0x0B95,
		STENCIL_PASS_DEPTH_PASS          = 0x0B96,
		STENCIL_REF                      = 0x0B97,
		STENCIL_WRITEMASK                = 0x0B98,
		VIEWPORT                         = 0x0BA2,
		DITHER                           = 0x0BD0,
		BLEND_DST                        = 0x0BE0,
		BLEND_SRC                        = 0x0BE1,
		BLEND                            = 0x0BE2,
		LOGIC_OP_MODE                    = 0x0BF0,
		COLOR_LOGIC_OP                   = 0x0BF2,
		DRAW_BUFFER                      = 0x0C01,
		READ_BUFFER                      = 0x0C02,
		SCISSOR_BOX                      = 0x0C10,
		SCISSOR_TEST                     = 0x0C11,
		COLOR_CLEAR_VALUE                = 0x0C22,
		COLOR_WRITEMASK                  = 0x0C23,
		DOUBLEBUFFER                     = 0x0C32,
		STEREO                           = 0x0C33,
		LINE_SMOOTH_HINT                 = 0x0C52,
		POLYGON_SMOOTH_HINT              = 0x0C53,
		UNPACK_SWAP_BYTES                = 0x0CF0,
		UNPACK_LSB_FIRST                 = 0x0CF1,
		UNPACK_ROW_LENGTH                = 0x0CF2,
		UNPACK_SKIP_ROWS                 = 0x0CF3,
		UNPACK_SKIP_PIXELS               = 0x0CF4,
		UNPACK_ALIGNMENT                 = 0x0CF5,
		PACK_SWAP_BYTES                  = 0x0D00,
		PACK_LSB_FIRST                   = 0x0D01,
		PACK_ROW_LENGTH                  = 0x0D02,
		PACK_SKIP_ROWS                   = 0x0D03,
		PACK_SKIP_PIXELS                 = 0x0D04,
		PACK_ALIGNMENT                   = 0x0D05,
		MAX_TEXTURE_SIZE                 = 0x0D33,
		MAX_VIEWPORT_DIMS                = 0x0D3A,
		SUBPIXEL_BITS                    = 0x0D50,
		TEXTURE_1D                       = 0x0DE0,
		TEXTURE_2D                       = 0x0DE1,
		POLYGON_OFFSET_UNITS             = 0x2A00,
		POLYGON_OFFSET_POINT             = 0x2A01,
		POLYGON_OFFSET_LINE              = 0x2A02,
		POLYGON_OFFSET_FILL              = 0x8037,
		POLYGON_OFFSET_FACTOR            = 0x8038,
		TEXTURE_BINDING_1D               = 0x8068,
		TEXTURE_BINDING_2D               = 0x8069,
		TEXTURE_WIDTH                    = 0x1000,
		TEXTURE_HEIGHT                   = 0x1001,
		TEXTURE_INTERNAL_FORMAT          = 0x1003,
		TEXTURE_BORDER_COLOR             = 0x1004,
		TEXTURE_RED_SIZE                 = 0x805C,
		TEXTURE_GREEN_SIZE               = 0x805D,
		TEXTURE_BLUE_SIZE                = 0x805E,
		TEXTURE_ALPHA_SIZE               = 0x805F,
		DONT_CARE                        = 0x1100,
		FASTEST                          = 0x1101,
		NICEST                           = 0x1102,
		BYTE                             = 0x1400,
		UNSIGNED_BYTE                    = 0x1401,
		SHORT                            = 0x1402,
		UNSIGNED_SHORT                   = 0x1403,
		INT                              = 0x1404,
		UNSIGNED_INT                     = 0x1405,
		FLOAT                            = 0x1406,
		DOUBLE                           = 0x140A,
		CLEAR                            = 0x1500,
		AND                              = 0x1501,
		AND_REVERSE                      = 0x1502,
		COPY                             = 0x1503,
		AND_INVERTED                     = 0x1504,
		NOOP                             = 0x1505,
		XOR                              = 0x1506,
		OR                               = 0x1507,
		NOR                              = 0x1508,
		EQUIV                            = 0x1509,
		INVERT                           = 0x150A,
		OR_REVERSE                       = 0x150B,
		COPY_INVERTED                    = 0x150C,
		OR_INVERTED                      = 0x150D,
		NAND                             = 0x150E,
		SET                              = 0x150F,
		TEXTURE                          = 0x1702,
		COLOR                            = 0x1800,
		DEPTH                            = 0x1801,
		STENCIL                          = 0x1802,
		STENCIL_INDEX                    = 0x1901,
		DEPTH_COMPONENT                  = 0x1902,
		RED                              = 0x1903,
		GREEN                            = 0x1904,
		BLUE                             = 0x1905,
		ALPHA                            = 0x1906,
		RGB                              = 0x1907,
		RGBA                             = 0x1908,
		POINT                            = 0x1B00,
		LINE                             = 0x1B01,
		FILL                             = 0x1B02,
		KEEP                             = 0x1E00,
		REPLACE                          = 0x1E01,
		INCR                             = 0x1E02,
		DECR                             = 0x1E03,
		VENDOR                           = 0x1F00,
		RENDERER                         = 0x1F01,
		VERSION                          = 0x1F02,
		EXTENSIONS                       = 0x1F03,
		NEAREST                          = 0x2600,
		LINEAR                           = 0x2601,
		NEAREST_MIPMAP_NEAREST           = 0x2700,
		LINEAR_MIPMAP_NEAREST            = 0x2701,
		NEAREST_MIPMAP_LINEAR            = 0x2702,
		LINEAR_MIPMAP_LINEAR             = 0x2703,
		TEXTURE_MAG_FILTER               = 0x2800,
		TEXTURE_MIN_FILTER               = 0x2801,
		TEXTURE_WRAP_S                   = 0x2802,
		TEXTURE_WRAP_T                   = 0x2803,
		PROXY_TEXTURE_1D                 = 0x8063,
		PROXY_TEXTURE_2D                 = 0x8064,
		REPEAT                           = 0x2901,
		R3_G3_B2                         = 0x2A10,
		RGB4                             = 0x804F,
		RGB5                             = 0x8050,
		RGB8                             = 0x8051,
		RGB10                            = 0x8052,
		RGB12                            = 0x8053,
		RGB16                            = 0x8054,
		RGBA2                            = 0x8055,
		RGBA4                            = 0x8056,
		RGB5_A1                          = 0x8057,
		RGBA8                            = 0x8058,
		RGB10_A2                         = 0x8059,
		RGBA12                           = 0x805A,
		RGBA16                           = 0x805B,
		CURRENT_BIT                      = 0x00000001,
		POINT_BIT                        = 0x00000002,
		LINE_BIT                         = 0x00000004,
		POLYGON_BIT                      = 0x00000008,
		POLYGON_STIPPLE_BIT              = 0x00000010,
		PIXEL_MODE_BIT                   = 0x00000020,
		LIGHTING_BIT                     = 0x00000040,
		FOG_BIT                          = 0x00000080,
		ACCUM_BUFFER_BIT                 = 0x00000200,
		VIEWPORT_BIT                     = 0x00000800,
		TRANSFORM_BIT                    = 0x00001000,
		ENABLE_BIT                       = 0x00002000,
		HINT_BIT                         = 0x00008000,
		EVAL_BIT                         = 0x00010000,
		LIST_BIT                         = 0x00020000,
		TEXTURE_BIT                      = 0x00040000,
		SCISSOR_BIT                      = 0x00080000,
		ALL_ATTRIB_BITS                  = 0xFFFFFFFF,
		CLIENT_PIXEL_STORE_BIT           = 0x00000001,
		CLIENT_VERTEX_ARRAY_BIT          = 0x00000002,
		CLIENT_ALL_ATTRIB_BITS           = 0xFFFFFFFF,
		QUAD_STRIP                       = 0x0008,
		POLYGON                          = 0x0009,
		ACCUM                            = 0x0100,
		LOAD                             = 0x0101,
		RETURN                           = 0x0102,
		MULT                             = 0x0103,
		ADD                              = 0x0104,
		AUX0                             = 0x0409,
		AUX1                             = 0x040A,
		AUX2                             = 0x040B,
		AUX3                             = 0x040C,
		_2D                              = 0x0600,
		_3D                              = 0x0601,
		_3D_COLOR                        = 0x0602,
		_3D_COLOR_TEXTURE                = 0x0603,
		_4D_COLOR_TEXTURE                = 0x0604,
		PASS_THROUGH_TOKEN               = 0x0700,
		POINT_TOKEN                      = 0x0701,
		LINE_TOKEN                       = 0x0702,
		POLYGON_TOKEN                    = 0x0703,
		BITMAP_TOKEN                     = 0x0704,
		DRAW_PIXEL_TOKEN                 = 0x0705,
		COPY_PIXEL_TOKEN                 = 0x0706,
		LINE_RESET_TOKEN                 = 0x0707,
		EXP                              = 0x0800,
		EXP2                             = 0x0801,
		COEFF                            = 0x0A00,
		ORDER                            = 0x0A01,
		DOMAIN_                          = 0x0A02,
		PIXEL_MAP_I_TO_I                 = 0x0C70,
		PIXEL_MAP_S_TO_S                 = 0x0C71,
		PIXEL_MAP_I_TO_R                 = 0x0C72,
		PIXEL_MAP_I_TO_G                 = 0x0C73,
		PIXEL_MAP_I_TO_B                 = 0x0C74,
		PIXEL_MAP_I_TO_A                 = 0x0C75,
		PIXEL_MAP_R_TO_R                 = 0x0C76,
		PIXEL_MAP_G_TO_G                 = 0x0C77,
		PIXEL_MAP_B_TO_B                 = 0x0C78,
		PIXEL_MAP_A_TO_A                 = 0x0C79,
		VERTEX_ARRAY_POINTER             = 0x808E,
		NORMAL_ARRAY_POINTER             = 0x808F,
		COLOR_ARRAY_POINTER              = 0x8090,
		INDEX_ARRAY_POINTER              = 0x8091,
		TEXTURE_COORD_ARRAY_POINTER      = 0x8092,
		EDGE_FLAG_ARRAY_POINTER          = 0x8093,
		FEEDBACK_BUFFER_POINTER          = 0x0DF0,
		SELECTION_BUFFER_POINTER         = 0x0DF3,
		CURRENT_COLOR                    = 0x0B00,
		CURRENT_INDEX                    = 0x0B01,
		CURRENT_NORMAL                   = 0x0B02,
		CURRENT_TEXTURE_COORDS           = 0x0B03,
		CURRENT_RASTER_COLOR             = 0x0B04,
		CURRENT_RASTER_INDEX             = 0x0B05,
		CURRENT_RASTER_TEXTURE_COORDS    = 0x0B06,
		CURRENT_RASTER_POSITION          = 0x0B07,
		CURRENT_RASTER_POSITION_VALID    = 0x0B08,
		CURRENT_RASTER_DISTANCE          = 0x0B09,
		POINT_SMOOTH                     = 0x0B10,
		LINE_STIPPLE                     = 0x0B24,
		LINE_STIPPLE_PATTERN             = 0x0B25,
		LINE_STIPPLE_REPEAT              = 0x0B26,
		LIST_MODE                        = 0x0B30,
		MAX_LIST_NESTING                 = 0x0B31,
		LIST_BASE                        = 0x0B32,
		LIST_INDEX                       = 0x0B33,
		POLYGON_STIPPLE                  = 0x0B42,
		EDGE_FLAG                        = 0x0B43,
		LIGHTING                         = 0x0B50,
		LIGHT_MODEL_LOCAL_VIEWER         = 0x0B51,
		LIGHT_MODEL_TWO_SIDE             = 0x0B52,
		LIGHT_MODEL_AMBIENT              = 0x0B53,
		SHADE_MODEL                      = 0x0B54,
		COLOR_MATERIAL_FACE              = 0x0B55,
		COLOR_MATERIAL_PARAMETER         = 0x0B56,
		COLOR_MATERIAL                   = 0x0B57,
		FOG                              = 0x0B60,
		FOG_INDEX                        = 0x0B61,
		FOG_DENSITY                      = 0x0B62,
		FOG_START                        = 0x0B63,
		FOG_END                          = 0x0B64,
		FOG_MODE                         = 0x0B65,
		FOG_COLOR                        = 0x0B66,
		ACCUM_CLEAR_VALUE                = 0x0B80,
		MATRIX_MODE                      = 0x0BA0,
		NORMALIZE                        = 0x0BA1,
		MODELVIEW_STACK_DEPTH            = 0x0BA3,
		PROJECTION_STACK_DEPTH           = 0x0BA4,
		TEXTURE_STACK_DEPTH              = 0x0BA5,
		MODELVIEW_MATRIX                 = 0x0BA6,
		PROJECTION_MATRIX                = 0x0BA7,
		TEXTURE_MATRIX                   = 0x0BA8,
		ATTRIB_STACK_DEPTH               = 0x0BB0,
		CLIENT_ATTRIB_STACK_DEPTH        = 0x0BB1,
		ALPHA_TEST                       = 0x0BC0,
		ALPHA_TEST_FUNC                  = 0x0BC1,
		ALPHA_TEST_REF                   = 0x0BC2,
		INDEX_LOGIC_OP                   = 0x0BF1,
		LOGIC_OP                         = 0x0BF1,
		AUX_BUFFERS                      = 0x0C00,
		INDEX_CLEAR_VALUE                = 0x0C20,
		INDEX_WRITEMASK                  = 0x0C21,
		INDEX_MODE                       = 0x0C30,
		RGBA_MODE                        = 0x0C31,
		RENDER_MODE                      = 0x0C40,
		PERSPECTIVE_CORRECTION_HINT      = 0x0C50,
		POINT_SMOOTH_HINT                = 0x0C51,
		FOG_HINT                         = 0x0C54,
		TEXTURE_GEN_S                    = 0x0C60,
		TEXTURE_GEN_T                    = 0x0C61,
		TEXTURE_GEN_R                    = 0x0C62,
		TEXTURE_GEN_Q                    = 0x0C63,
		PIXEL_MAP_I_TO_I_SIZE            = 0x0CB0,
		PIXEL_MAP_S_TO_S_SIZE            = 0x0CB1,
		PIXEL_MAP_I_TO_R_SIZE            = 0x0CB2,
		PIXEL_MAP_I_TO_G_SIZE            = 0x0CB3,
		PIXEL_MAP_I_TO_B_SIZE            = 0x0CB4,
		PIXEL_MAP_I_TO_A_SIZE            = 0x0CB5,
		PIXEL_MAP_R_TO_R_SIZE            = 0x0CB6,
		PIXEL_MAP_G_TO_G_SIZE            = 0x0CB7,
		PIXEL_MAP_B_TO_B_SIZE            = 0x0CB8,
		PIXEL_MAP_A_TO_A_SIZE            = 0x0CB9,
		MAP_COLOR                        = 0x0D10,
		MAP_STENCIL                      = 0x0D11,
		INDEX_SHIFT                      = 0x0D12,
		INDEX_OFFSET                     = 0x0D13,
		RED_SCALE                        = 0x0D14,
		RED_BIAS                         = 0x0D15,
		ZOOM_X                           = 0x0D16,
		ZOOM_Y                           = 0x0D17,
		GREEN_SCALE                      = 0x0D18,
		GREEN_BIAS                       = 0x0D19,
		BLUE_SCALE                       = 0x0D1A,
		BLUE_BIAS                        = 0x0D1B,
		ALPHA_SCALE                      = 0x0D1C,
		ALPHA_BIAS                       = 0x0D1D,
		DEPTH_SCALE                      = 0x0D1E,
		DEPTH_BIAS                       = 0x0D1F,
		MAX_EVAL_ORDER                   = 0x0D30,
		MAX_LIGHTS                       = 0x0D31,
		MAX_CLIP_PLANES                  = 0x0D32,
		MAX_PIXEL_MAP_TABLE              = 0x0D34,
		MAX_ATTRIB_STACK_DEPTH           = 0x0D35,
		MAX_MODELVIEW_STACK_DEPTH        = 0x0D36,
		MAX_NAME_STACK_DEPTH             = 0x0D37,
		MAX_PROJECTION_STACK_DEPTH       = 0x0D38,
		MAX_TEXTURE_STACK_DEPTH          = 0x0D39,
		MAX_CLIENT_ATTRIB_STACK_DEPTH    = 0x0D3B,
		INDEX_BITS                       = 0x0D51,
		RED_BITS                         = 0x0D52,
		GREEN_BITS                       = 0x0D53,
		BLUE_BITS                        = 0x0D54,
		ALPHA_BITS                       = 0x0D55,
		DEPTH_BITS                       = 0x0D56,
		STENCIL_BITS                     = 0x0D57,
		ACCUM_RED_BITS                   = 0x0D58,
		ACCUM_GREEN_BITS                 = 0x0D59,
		ACCUM_BLUE_BITS                  = 0x0D5A,
		ACCUM_ALPHA_BITS                 = 0x0D5B,
		NAME_STACK_DEPTH                 = 0x0D70,
		AUTO_NORMAL                      = 0x0D80,
		MAP1_COLOR_4                     = 0x0D90,
		MAP1_INDEX                       = 0x0D91,
		MAP1_NORMAL                      = 0x0D92,
		MAP1_TEXTURE_COORD_1             = 0x0D93,
		MAP1_TEXTURE_COORD_2             = 0x0D94,
		MAP1_TEXTURE_COORD_3             = 0x0D95,
		MAP1_TEXTURE_COORD_4             = 0x0D96,
		MAP1_VERTEX_3                    = 0x0D97,
		MAP1_VERTEX_4                    = 0x0D98,
		MAP2_COLOR_4                     = 0x0DB0,
		MAP2_INDEX                       = 0x0DB1,
		MAP2_NORMAL                      = 0x0DB2,
		MAP2_TEXTURE_COORD_1             = 0x0DB3,
		MAP2_TEXTURE_COORD_2             = 0x0DB4,
		MAP2_TEXTURE_COORD_3             = 0x0DB5,
		MAP2_TEXTURE_COORD_4             = 0x0DB6,
		MAP2_VERTEX_3                    = 0x0DB7,
		MAP2_VERTEX_4                    = 0x0DB8,
		MAP1_GRID_DOMAIN                 = 0x0DD0,
		MAP1_GRID_SEGMENTS               = 0x0DD1,
		MAP2_GRID_DOMAIN                 = 0x0DD2,
		MAP2_GRID_SEGMENTS               = 0x0DD3,
		FEEDBACK_BUFFER_SIZE             = 0x0DF1,
		FEEDBACK_BUFFER_TYPE             = 0x0DF2,
		SELECTION_BUFFER_SIZE            = 0x0DF4,
		VERTEX_ARRAY                     = 0x8074,
		NORMAL_ARRAY                     = 0x8075,
		COLOR_ARRAY                      = 0x8076,
		INDEX_ARRAY                      = 0x8077,
		TEXTURE_COORD_ARRAY              = 0x8078,
		EDGE_FLAG_ARRAY                  = 0x8079,
		VERTEX_ARRAY_SIZE                = 0x807A,
		VERTEX_ARRAY_TYPE                = 0x807B,
		VERTEX_ARRAY_STRIDE              = 0x807C,
		NORMAL_ARRAY_TYPE                = 0x807E,
		NORMAL_ARRAY_STRIDE              = 0x807F,
		COLOR_ARRAY_SIZE                 = 0x8081,
		COLOR_ARRAY_TYPE                 = 0x8082,
		COLOR_ARRAY_STRIDE               = 0x8083,
		INDEX_ARRAY_TYPE                 = 0x8085,
		INDEX_ARRAY_STRIDE               = 0x8086,
		TEXTURE_COORD_ARRAY_SIZE         = 0x8088,
		TEXTURE_COORD_ARRAY_TYPE         = 0x8089,
		TEXTURE_COORD_ARRAY_STRIDE       = 0x808A,
		EDGE_FLAG_ARRAY_STRIDE           = 0x808C,
		TEXTURE_COMPONENTS               = 0x1003,
		TEXTURE_BORDER                   = 0x1005,
		TEXTURE_LUMINANCE_SIZE           = 0x8060,
		TEXTURE_INTENSITY_SIZE           = 0x8061,
		TEXTURE_PRIORITY                 = 0x8066,
		TEXTURE_RESIDENT                 = 0x8067,
		AMBIENT                          = 0x1200,
		DIFFUSE                          = 0x1201,
		SPECULAR                         = 0x1202,
		POSITION                         = 0x1203,
		SPOT_DIRECTION                   = 0x1204,
		SPOT_EXPONENT                    = 0x1205,
		SPOT_CUTOFF                      = 0x1206,
		CONSTANT_ATTENUATION             = 0x1207,
		LINEAR_ATTENUATION               = 0x1208,
		QUADRATIC_ATTENUATION            = 0x1209,
		COMPILE                          = 0x1300,
		COMPILE_AND_EXECUTE              = 0x1301,
		_2_BYTES                         = 0x1407,
		_3_BYTES                         = 0x1408,
		_4_BYTES                         = 0x1409,
		EMISSION                         = 0x1600,
		SHININESS                        = 0x1601,
		AMBIENT_AND_DIFFUSE              = 0x1602,
		COLOR_INDEXES                    = 0x1603,
		MODELVIEW                        = 0x1700,
		PROJECTION                       = 0x1701,
		COLOR_INDEX                      = 0x1900,
		LUMINANCE                        = 0x1909,
		LUMINANCE_ALPHA                  = 0x190A,
		BITMAP                           = 0x1A00,
		RENDER                           = 0x1C00,
		FEEDBACK                         = 0x1C01,
		SELECT                           = 0x1C02,
		FLAT                             = 0x1D00,
		SMOOTH                           = 0x1D01,
		S                                = 0x2000,
		T                                = 0x2001,
		R                                = 0x2002,
		Q                                = 0x2003,
		MODULATE                         = 0x2100,
		DECAL                            = 0x2101,
		TEXTURE_ENV_MODE                 = 0x2200,
		TEXTURE_ENV_COLOR                = 0x2201,
		TEXTURE_ENV                      = 0x2300,
		EYE_LINEAR                       = 0x2400,
		OBJECT_LINEAR                    = 0x2401,
		SPHERE_MAP                       = 0x2402,
		TEXTURE_GEN_MODE                 = 0x2500,
		OBJECT_PLANE                     = 0x2501,
		EYE_PLANE                        = 0x2502,
		CLAMP                            = 0x2900,
		ALPHA4                           = 0x803B,
		ALPHA8                           = 0x803C,
		ALPHA12                          = 0x803D,
		ALPHA16                          = 0x803E,
		LUMINANCE4                       = 0x803F,
		LUMINANCE8                       = 0x8040,
		LUMINANCE12                      = 0x8041,
		LUMINANCE16                      = 0x8042,
		LUMINANCE4_ALPHA4                = 0x8043,
		LUMINANCE6_ALPHA2                = 0x8044,
		LUMINANCE8_ALPHA8                = 0x8045,
		LUMINANCE12_ALPHA4               = 0x8046,
		LUMINANCE12_ALPHA12              = 0x8047,
		LUMINANCE16_ALPHA16              = 0x8048,
		INTENSITY                        = 0x8049,
		INTENSITY4                       = 0x804A,
		INTENSITY8                       = 0x804B,
		INTENSITY12                      = 0x804C,
		INTENSITY16                      = 0x804D,
		V2F                              = 0x2A20,
		V3F                              = 0x2A21,
		C4UB_V2F                         = 0x2A22,
		C4UB_V3F                         = 0x2A23,
		C3F_V3F                          = 0x2A24,
		N3F_V3F                          = 0x2A25,
		C4F_N3F_V3F                      = 0x2A26,
		T2F_V3F                          = 0x2A27,
		T4F_V4F                          = 0x2A28,
		T2F_C4UB_V3F                     = 0x2A29,
		T2F_C3F_V3F                      = 0x2A2A,
		T2F_N3F_V3F                      = 0x2A2B,
		T2F_C4F_N3F_V3F                  = 0x2A2C,
		T4F_C4F_N3F_V4F                  = 0x2A2D,
		CLIP_PLANE0                      = 0x3000,
		CLIP_PLANE1                      = 0x3001,
		CLIP_PLANE2                      = 0x3002,
		CLIP_PLANE3                      = 0x3003,
		CLIP_PLANE4                      = 0x3004,
		CLIP_PLANE5                      = 0x3005,
		LIGHT0                           = 0x4000,
		LIGHT1                           = 0x4001,
		LIGHT2                           = 0x4002,
		LIGHT3                           = 0x4003,
		LIGHT4                           = 0x4004,
		LIGHT5                           = 0x4005,
		LIGHT6                           = 0x4006,
		LIGHT7                           = 0x4007,
		
		CONSTANT_COLOR                   = 0x8001,
		ONE_MINUS_CONSTANT_COLOR         = 0x8002,
		CONSTANT_ALPHA                   = 0x8003,
		ONE_MINUS_CONSTANT_ALPHA         = 0x8004,
		BLEND_COLOR                      = 0x8005,
		FUNC_ADD                         = 0x8006,
		MIN                              = 0x8007,
		MAX                              = 0x8008,
		BLEND_EQUATION                   = 0x8009,
		FUNC_SUBTRACT                    = 0x800A,
		FUNC_REVERSE_SUBTRACT            = 0x800B,
		CONVOLUTION_1D                   = 0x8010,
		CONVOLUTION_2D                   = 0x8011,
		SEPARABLE_2D                     = 0x8012,
		CONVOLUTION_BORDER_MODE          = 0x8013,
		CONVOLUTION_FILTER_SCALE         = 0x8014,
		CONVOLUTION_FILTER_BIAS          = 0x8015,
		REDUCE                           = 0x8016,
		CONVOLUTION_FORMAT               = 0x8017,
		CONVOLUTION_WIDTH                = 0x8018,
		CONVOLUTION_HEIGHT               = 0x8019,
		MAX_CONVOLUTION_WIDTH            = 0x801A,
		MAX_CONVOLUTION_HEIGHT           = 0x801B,
		POST_CONVOLUTION_RED_SCALE       = 0x801C,
		POST_CONVOLUTION_GREEN_SCALE     = 0x801D,
		POST_CONVOLUTION_BLUE_SCALE      = 0x801E,
		POST_CONVOLUTION_ALPHA_SCALE     = 0x801F,
		POST_CONVOLUTION_RED_BIAS        = 0x8020,
		POST_CONVOLUTION_GREEN_BIAS      = 0x8021,
		POST_CONVOLUTION_BLUE_BIAS       = 0x8022,
		POST_CONVOLUTION_ALPHA_BIAS      = 0x8023,
		HISTOGRAM                        = 0x8024,
		PROXY_HISTOGRAM                  = 0x8025,
		HISTOGRAM_WIDTH                  = 0x8026,
		HISTOGRAM_FORMAT                 = 0x8027,
		HISTOGRAM_RED_SIZE               = 0x8028,
		HISTOGRAM_GREEN_SIZE             = 0x8029,
		HISTOGRAM_BLUE_SIZE              = 0x802A,
		HISTOGRAM_ALPHA_SIZE             = 0x802B,
		HISTOGRAM_LUMINANCE_SIZE         = 0x802C,
		HISTOGRAM_SINK                   = 0x802D,
		MINMAX                           = 0x802E,
		MINMAX_FORMAT                    = 0x802F,
		MINMAX_SINK                      = 0x8030,
		TABLE_TOO_LARGE                  = 0x8031,
		COLOR_MATRIX                     = 0x80B1,
		COLOR_MATRIX_STACK_DEPTH         = 0x80B2,
		MAX_COLOR_MATRIX_STACK_DEPTH     = 0x80B3,
		POST_COLOR_MATRIX_RED_SCALE      = 0x80B4,
		POST_COLOR_MATRIX_GREEN_SCALE    = 0x80B5,
		POST_COLOR_MATRIX_BLUE_SCALE     = 0x80B6,
		POST_COLOR_MATRIX_ALPHA_SCALE    = 0x80B7,
		POST_COLOR_MATRIX_RED_BIAS       = 0x80B8,
		POST_COLOR_MATRIX_GREEN_BIAS     = 0x80B9,
		POST_COLOR_MATRIX_BLUE_BIAS      = 0x80BA,
		POST_COLOR_MATRIX_ALPHA_BIAS     = 0x80BB,
		COLOR_TABLE                      = 0x80D0,
		POST_CONVOLUTION_COLOR_TABLE     = 0x80D1,
		POST_COLOR_MATRIX_COLOR_TABLE    = 0x80D2,
		PROXY_COLOR_TABLE                = 0x80D3,
		PROXY_POST_CONVOLUTION_COLOR_TABLE = 0x80D4,
		PROXY_POST_COLOR_MATRIX_COLOR_TABLE = 0x80D5,
		COLOR_TABLE_SCALE                = 0x80D6,
		COLOR_TABLE_BIAS                 = 0x80D7,
		COLOR_TABLE_FORMAT               = 0x80D8,
		COLOR_TABLE_WIDTH                = 0x80D9,
		COLOR_TABLE_RED_SIZE             = 0x80DA,
		COLOR_TABLE_GREEN_SIZE           = 0x80DB,
		COLOR_TABLE_BLUE_SIZE            = 0x80DC,
		COLOR_TABLE_ALPHA_SIZE           = 0x80DD,
		COLOR_TABLE_LUMINANCE_SIZE       = 0x80DE,
		COLOR_TABLE_INTENSITY_SIZE       = 0x80DF,
		CONSTANT_BORDER                  = 0x8151,
		REPLICATE_BORDER                 = 0x8153,
		CONVOLUTION_BORDER_COLOR         = 0x8154,
		
		UNSIGNED_BYTE_3_3_2              = 0x8032,
		UNSIGNED_SHORT_4_4_4_4           = 0x8033,
		UNSIGNED_SHORT_5_5_5_1           = 0x8034,
		UNSIGNED_INT_8_8_8_8             = 0x8035,
		UNSIGNED_INT_10_10_10_2          = 0x8036,
		TEXTURE_BINDING_3D               = 0x806A,
		PACK_SKIP_IMAGES                 = 0x806B,
		PACK_IMAGE_HEIGHT                = 0x806C,
		UNPACK_SKIP_IMAGES               = 0x806D,
		UNPACK_IMAGE_HEIGHT              = 0x806E,
		TEXTURE_3D                       = 0x806F,
		PROXY_TEXTURE_3D                 = 0x8070,
		TEXTURE_DEPTH                    = 0x8071,
		TEXTURE_WRAP_R                   = 0x8072,
		MAX_3D_TEXTURE_SIZE              = 0x8073,
		UNSIGNED_BYTE_2_3_3_REV          = 0x8362,
		UNSIGNED_SHORT_5_6_5             = 0x8363,
		UNSIGNED_SHORT_5_6_5_REV         = 0x8364,
		UNSIGNED_SHORT_4_4_4_4_REV       = 0x8365,
		UNSIGNED_SHORT_1_5_5_5_REV       = 0x8366,
		UNSIGNED_INT_8_8_8_8_REV         = 0x8367,
		UNSIGNED_INT_2_10_10_10_REV      = 0x8368,
		BGR                              = 0x80E0,
		BGRA                             = 0x80E1,
		MAX_ELEMENTS_VERTICES            = 0x80E8,
		MAX_ELEMENTS_INDICES             = 0x80E9,
		CLAMP_TO_EDGE                    = 0x812F,
		TEXTURE_MIN_LOD                  = 0x813A,
		TEXTURE_MAX_LOD                  = 0x813B,
		TEXTURE_BASE_LEVEL               = 0x813C,
		TEXTURE_MAX_LEVEL                = 0x813D,
		SMOOTH_POINT_SIZE_RANGE          = 0x0B12,
		SMOOTH_POINT_SIZE_GRANULARITY    = 0x0B13,
		SMOOTH_LINE_WIDTH_RANGE          = 0x0B22,
		SMOOTH_LINE_WIDTH_GRANULARITY    = 0x0B23,
		ALIASED_LINE_WIDTH_RANGE         = 0x846E,
		RESCALE_NORMAL                   = 0x803A,
		LIGHT_MODEL_COLOR_CONTROL        = 0x81F8,
		SINGLE_COLOR                     = 0x81F9,
		SEPARATE_SPECULAR_COLOR          = 0x81FA,
		ALIASED_POINT_SIZE_RANGE         = 0x846D,
		
		TEXTURE0                         = 0x84C0,
		TEXTURE1                         = 0x84C1,
		TEXTURE2                         = 0x84C2,
		TEXTURE3                         = 0x84C3,
		TEXTURE4                         = 0x84C4,
		TEXTURE5                         = 0x84C5,
		TEXTURE6                         = 0x84C6,
		TEXTURE7                         = 0x84C7,
		TEXTURE8                         = 0x84C8,
		TEXTURE9                         = 0x84C9,
		TEXTURE10                        = 0x84CA,
		TEXTURE11                        = 0x84CB,
		TEXTURE12                        = 0x84CC,
		TEXTURE13                        = 0x84CD,
		TEXTURE14                        = 0x84CE,
		TEXTURE15                        = 0x84CF,
		TEXTURE16                        = 0x84D0,
		TEXTURE17                        = 0x84D1,
		TEXTURE18                        = 0x84D2,
		TEXTURE19                        = 0x84D3,
		TEXTURE20                        = 0x84D4,
		TEXTURE21                        = 0x84D5,
		TEXTURE22                        = 0x84D6,
		TEXTURE23                        = 0x84D7,
		TEXTURE24                        = 0x84D8,
		TEXTURE25                        = 0x84D9,
		TEXTURE26                        = 0x84DA,
		TEXTURE27                        = 0x84DB,
		TEXTURE28                        = 0x84DC,
		TEXTURE29                        = 0x84DD,
		TEXTURE30                        = 0x84DE,
		TEXTURE31                        = 0x84DF,
		ACTIVE_TEXTURE                   = 0x84E0,
		MULTISAMPLE                      = 0x809D,
		SAMPLE_ALPHA_TO_COVERAGE         = 0x809E,
		SAMPLE_ALPHA_TO_ONE              = 0x809F,
		SAMPLE_COVERAGE                  = 0x80A0,
		SAMPLE_BUFFERS                   = 0x80A8,
		SAMPLES                          = 0x80A9,
		SAMPLE_COVERAGE_VALUE            = 0x80AA,
		SAMPLE_COVERAGE_INVERT           = 0x80AB,
		TEXTURE_CUBE_MAP                 = 0x8513,
		TEXTURE_BINDING_CUBE_MAP         = 0x8514,
		TEXTURE_CUBE_MAP_POSITIVE_X      = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X      = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y      = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y      = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z      = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z      = 0x851A,
		PROXY_TEXTURE_CUBE_MAP           = 0x851B,
		MAX_CUBE_MAP_TEXTURE_SIZE        = 0x851C,
		COMPRESSED_RGB                   = 0x84ED,
		COMPRESSED_RGBA                  = 0x84EE,
		TEXTURE_COMPRESSION_HINT         = 0x84EF,
		TEXTURE_COMPRESSED_IMAGE_SIZE    = 0x86A0,
		TEXTURE_COMPRESSED               = 0x86A1,
		NUM_COMPRESSED_TEXTURE_FORMATS   = 0x86A2,
		COMPRESSED_TEXTURE_FORMATS       = 0x86A3,
		CLAMP_TO_BORDER                  = 0x812D,
		CLIENT_ACTIVE_TEXTURE            = 0x84E1,
		MAX_TEXTURE_UNITS                = 0x84E2,
		TRANSPOSE_MODELVIEW_MATRIX       = 0x84E3,
		TRANSPOSE_PROJECTION_MATRIX      = 0x84E4,
		TRANSPOSE_TEXTURE_MATRIX         = 0x84E5,
		TRANSPOSE_COLOR_MATRIX           = 0x84E6,
		MULTISAMPLE_BIT                  = 0x20000000,
		NORMAL_MAP                       = 0x8511,
		REFLECTION_MAP                   = 0x8512,
		COMPRESSED_ALPHA                 = 0x84E9,
		COMPRESSED_LUMINANCE             = 0x84EA,
		COMPRESSED_LUMINANCE_ALPHA       = 0x84EB,
		COMPRESSED_INTENSITY             = 0x84EC,
		COMBINE                          = 0x8570,
		COMBINE_RGB                      = 0x8571,
		COMBINE_ALPHA                    = 0x8572,
		SOURCE0_RGB                      = 0x8580,
		SOURCE1_RGB                      = 0x8581,
		SOURCE2_RGB                      = 0x8582,
		SOURCE0_ALPHA                    = 0x8588,
		SOURCE1_ALPHA                    = 0x8589,
		SOURCE2_ALPHA                    = 0x858A,
		OPERAND0_RGB                     = 0x8590,
		OPERAND1_RGB                     = 0x8591,
		OPERAND2_RGB                     = 0x8592,
		OPERAND0_ALPHA                   = 0x8598,
		OPERAND1_ALPHA                   = 0x8599,
		OPERAND2_ALPHA                   = 0x859A,
		RGB_SCALE                        = 0x8573,
		ADD_SIGNED                       = 0x8574,
		INTERPOLATE                      = 0x8575,
		SUBTRACT                         = 0x84E7,
		CONSTANT                         = 0x8576,
		PRIMARY_COLOR                    = 0x8577,
		PREVIOUS                         = 0x8578,
		DOT3_RGB                         = 0x86AE,
		DOT3_RGBA                        = 0x86AF,
		
		BLEND_DST_RGB                    = 0x80C8,
		BLEND_SRC_RGB                    = 0x80C9,
		BLEND_DST_ALPHA                  = 0x80CA,
		BLEND_SRC_ALPHA                  = 0x80CB,
		POINT_FADE_THRESHOLD_SIZE        = 0x8128,
		DEPTH_COMPONENT16                = 0x81A5,
		DEPTH_COMPONENT24                = 0x81A6,
		DEPTH_COMPONENT32                = 0x81A7,
		MIRRORED_REPEAT                  = 0x8370,
		MAX_TEXTURE_LOD_BIAS             = 0x84FD,
		TEXTURE_LOD_BIAS                 = 0x8501,
		INCR_WRAP                        = 0x8507,
		DECR_WRAP                        = 0x8508,
		TEXTURE_DEPTH_SIZE               = 0x884A,
		TEXTURE_COMPARE_MODE             = 0x884C,
		TEXTURE_COMPARE_FUNC             = 0x884D,
		POINT_SIZE_MIN                   = 0x8126,
		POINT_SIZE_MAX                   = 0x8127,
		POINT_DISTANCE_ATTENUATION       = 0x8129,
		GENERATE_MIPMAP                  = 0x8191,
		GENERATE_MIPMAP_HINT             = 0x8192,
		FOG_COORDINATE_SOURCE            = 0x8450,
		FOG_COORDINATE                   = 0x8451,
		FRAGMENT_DEPTH                   = 0x8452,
		CURRENT_FOG_COORDINATE           = 0x8453,
		FOG_COORDINATE_ARRAY_TYPE        = 0x8454,
		FOG_COORDINATE_ARRAY_STRIDE      = 0x8455,
		FOG_COORDINATE_ARRAY_POINTER     = 0x8456,
		FOG_COORDINATE_ARRAY             = 0x8457,
		COLOR_SUM                        = 0x8458,
		CURRENT_SECONDARY_COLOR          = 0x8459,
		SECONDARY_COLOR_ARRAY_SIZE       = 0x845A,
		SECONDARY_COLOR_ARRAY_TYPE       = 0x845B,
		SECONDARY_COLOR_ARRAY_STRIDE     = 0x845C,
		SECONDARY_COLOR_ARRAY_POINTER    = 0x845D,
		SECONDARY_COLOR_ARRAY            = 0x845E,
		TEXTURE_FILTER_CONTROL           = 0x8500,
		DEPTH_TEXTURE_MODE               = 0x884B,
		COMPARE_R_TO_TEXTURE             = 0x884E,
		
		BUFFER_SIZE                      = 0x8764,
		BUFFER_USAGE                     = 0x8765,
		QUERY_COUNTER_BITS               = 0x8864,
		CURRENT_QUERY                    = 0x8865,
		QUERY_RESULT                     = 0x8866,
		QUERY_RESULT_AVAILABLE           = 0x8867,
		ARRAY_BUFFER                     = 0x8892,
		ELEMENT_ARRAY_BUFFER             = 0x8893,
		ARRAY_BUFFER_BINDING             = 0x8894,
		ELEMENT_ARRAY_BUFFER_BINDING     = 0x8895,
		VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
		READ_ONLY                        = 0x88B8,
		WRITE_ONLY                       = 0x88B9,
		READ_WRITE                       = 0x88BA,
		BUFFER_ACCESS                    = 0x88BB,
		BUFFER_MAPPED                    = 0x88BC,
		BUFFER_MAP_POINTER               = 0x88BD,
		STREAM_DRAW                      = 0x88E0,
		STREAM_READ                      = 0x88E1,
		STREAM_COPY                      = 0x88E2,
		STATIC_DRAW                      = 0x88E4,
		STATIC_READ                      = 0x88E5,
		STATIC_COPY                      = 0x88E6,
		DYNAMIC_DRAW                     = 0x88E8,
		DYNAMIC_READ                     = 0x88E9,
		DYNAMIC_COPY                     = 0x88EA,
		SAMPLES_PASSED                   = 0x8914,
		SRC1_ALPHA                       = 0x8589,
		VERTEX_ARRAY_BUFFER_BINDING      = 0x8896,
		NORMAL_ARRAY_BUFFER_BINDING      = 0x8897,
		COLOR_ARRAY_BUFFER_BINDING       = 0x8898,
		INDEX_ARRAY_BUFFER_BINDING       = 0x8899,
		TEXTURE_COORD_ARRAY_BUFFER_BINDING = 0x889A,
		EDGE_FLAG_ARRAY_BUFFER_BINDING   = 0x889B,
		SECONDARY_COLOR_ARRAY_BUFFER_BINDING = 0x889C,
		FOG_COORDINATE_ARRAY_BUFFER_BINDING = 0x889D,
		WEIGHT_ARRAY_BUFFER_BINDING      = 0x889E,
		FOG_COORD_SRC                    = 0x8450,
		FOG_COORD                        = 0x8451,
		CURRENT_FOG_COORD                = 0x8453,
		FOG_COORD_ARRAY_TYPE             = 0x8454,
		FOG_COORD_ARRAY_STRIDE           = 0x8455,
		FOG_COORD_ARRAY_POINTER          = 0x8456,
		FOG_COORD_ARRAY                  = 0x8457,
		FOG_COORD_ARRAY_BUFFER_BINDING   = 0x889D,
		SRC0_RGB                         = 0x8580,
		SRC1_RGB                         = 0x8581,
		SRC2_RGB                         = 0x8582,
		SRC0_ALPHA                       = 0x8588,
		SRC2_ALPHA                       = 0x858A,
		
		BLEND_EQUATION_RGB               = 0x8009,
		VERTEX_ATTRIB_ARRAY_ENABLED      = 0x8622,
		VERTEX_ATTRIB_ARRAY_SIZE         = 0x8623,
		VERTEX_ATTRIB_ARRAY_STRIDE       = 0x8624,
		VERTEX_ATTRIB_ARRAY_TYPE         = 0x8625,
		CURRENT_VERTEX_ATTRIB            = 0x8626,
		VERTEX_PROGRAM_POINT_SIZE        = 0x8642,
		VERTEX_ATTRIB_ARRAY_POINTER      = 0x8645,
		STENCIL_BACK_FUNC                = 0x8800,
		STENCIL_BACK_FAIL                = 0x8801,
		STENCIL_BACK_PASS_DEPTH_FAIL     = 0x8802,
		STENCIL_BACK_PASS_DEPTH_PASS     = 0x8803,
		MAX_DRAW_BUFFERS                 = 0x8824,
		DRAW_BUFFER0                     = 0x8825,
		DRAW_BUFFER1                     = 0x8826,
		DRAW_BUFFER2                     = 0x8827,
		DRAW_BUFFER3                     = 0x8828,
		DRAW_BUFFER4                     = 0x8829,
		DRAW_BUFFER5                     = 0x882A,
		DRAW_BUFFER6                     = 0x882B,
		DRAW_BUFFER7                     = 0x882C,
		DRAW_BUFFER8                     = 0x882D,
		DRAW_BUFFER9                     = 0x882E,
		DRAW_BUFFER10                    = 0x882F,
		DRAW_BUFFER11                    = 0x8830,
		DRAW_BUFFER12                    = 0x8831,
		DRAW_BUFFER13                    = 0x8832,
		DRAW_BUFFER14                    = 0x8833,
		DRAW_BUFFER15                    = 0x8834,
		BLEND_EQUATION_ALPHA             = 0x883D,
		MAX_VERTEX_ATTRIBS               = 0x8869,
		VERTEX_ATTRIB_ARRAY_NORMALIZED   = 0x886A,
		MAX_TEXTURE_IMAGE_UNITS          = 0x8872,
		FRAGMENT_SHADER                  = 0x8B30,
		VERTEX_SHADER                    = 0x8B31,
		MAX_FRAGMENT_UNIFORM_COMPONENTS  = 0x8B49,
		MAX_VERTEX_UNIFORM_COMPONENTS    = 0x8B4A,
		MAX_VARYING_FLOATS               = 0x8B4B,
		MAX_VERTEX_TEXTURE_IMAGE_UNITS   = 0x8B4C,
		MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D,
		SHADER_TYPE                      = 0x8B4F,
		FLOAT_VEC2                       = 0x8B50,
		FLOAT_VEC3                       = 0x8B51,
		FLOAT_VEC4                       = 0x8B52,
		INT_VEC2                         = 0x8B53,
		INT_VEC3                         = 0x8B54,
		INT_VEC4                         = 0x8B55,
		BOOL                             = 0x8B56,
		BOOL_VEC2                        = 0x8B57,
		BOOL_VEC3                        = 0x8B58,
		BOOL_VEC4                        = 0x8B59,
		FLOAT_MAT2                       = 0x8B5A,
		FLOAT_MAT3                       = 0x8B5B,
		FLOAT_MAT4                       = 0x8B5C,
		SAMPLER_1D                       = 0x8B5D,
		SAMPLER_2D                       = 0x8B5E,
		SAMPLER_3D                       = 0x8B5F,
		SAMPLER_CUBE                     = 0x8B60,
		SAMPLER_1D_SHADOW                = 0x8B61,
		SAMPLER_2D_SHADOW                = 0x8B62,
		DELETE_STATUS                    = 0x8B80,
		COMPILE_STATUS                   = 0x8B81,
		LINK_STATUS                      = 0x8B82,
		VALIDATE_STATUS                  = 0x8B83,
		INFO_LOG_LENGTH                  = 0x8B84,
		ATTACHED_SHADERS                 = 0x8B85,
		ACTIVE_UNIFORMS                  = 0x8B86,
		ACTIVE_UNIFORM_MAX_LENGTH        = 0x8B87,
		SHADER_SOURCE_LENGTH             = 0x8B88,
		ACTIVE_ATTRIBUTES                = 0x8B89,
		ACTIVE_ATTRIBUTE_MAX_LENGTH      = 0x8B8A,
		FRAGMENT_SHADER_DERIVATIVE_HINT  = 0x8B8B,
		SHADING_LANGUAGE_VERSION         = 0x8B8C,
		CURRENT_PROGRAM                  = 0x8B8D,
		POINT_SPRITE_COORD_ORIGIN        = 0x8CA0,
		LOWER_LEFT                       = 0x8CA1,
		UPPER_LEFT                       = 0x8CA2,
		STENCIL_BACK_REF                 = 0x8CA3,
		STENCIL_BACK_VALUE_MASK          = 0x8CA4,
		STENCIL_BACK_WRITEMASK           = 0x8CA5,
		VERTEX_PROGRAM_TWO_SIDE          = 0x8643,
		POINT_SPRITE                     = 0x8861,
		COORD_REPLACE                    = 0x8862,
		MAX_TEXTURE_COORDS               = 0x8871,
		
		PIXEL_PACK_BUFFER                = 0x88EB,
		PIXEL_UNPACK_BUFFER              = 0x88EC,
		PIXEL_PACK_BUFFER_BINDING        = 0x88ED,
		PIXEL_UNPACK_BUFFER_BINDING      = 0x88EF,
		FLOAT_MAT2x3                     = 0x8B65,
		FLOAT_MAT2x4                     = 0x8B66,
		FLOAT_MAT3x2                     = 0x8B67,
		FLOAT_MAT3x4                     = 0x8B68,
		FLOAT_MAT4x2                     = 0x8B69,
		FLOAT_MAT4x3                     = 0x8B6A,
		SRGB                             = 0x8C40,
		SRGB8                            = 0x8C41,
		SRGB_ALPHA                       = 0x8C42,
		SRGB8_ALPHA8                     = 0x8C43,
		COMPRESSED_SRGB                  = 0x8C48,
		COMPRESSED_SRGB_ALPHA            = 0x8C49,
		CURRENT_RASTER_SECONDARY_COLOR   = 0x845F,
		SLUMINANCE_ALPHA                 = 0x8C44,
		SLUMINANCE8_ALPHA8               = 0x8C45,
		SLUMINANCE                       = 0x8C46,
		SLUMINANCE8                      = 0x8C47,
		COMPRESSED_SLUMINANCE            = 0x8C4A,
		COMPRESSED_SLUMINANCE_ALPHA      = 0x8C4B,
		
	};
	extern void (CODEGEN_FUNCPTR *CullFace)(GLenum mode);
	extern void (CODEGEN_FUNCPTR *FrontFace)(GLenum mode);
	extern void (CODEGEN_FUNCPTR *Hint)(GLenum target, GLenum mode);
	extern void (CODEGEN_FUNCPTR *LineWidth)(GLfloat width);
	extern void (CODEGEN_FUNCPTR *PointSize)(GLfloat size);
	extern void (CODEGEN_FUNCPTR *PolygonMode)(GLenum face, GLenum mode);
	extern void (CODEGEN_FUNCPTR *Scissor)(GLint x, GLint y, GLsizei width, GLsizei height);
	extern void (CODEGEN_FUNCPTR *TexParameterf)(GLenum target, GLenum pname, GLfloat param);
	extern void (CODEGEN_FUNCPTR *TexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
	extern void (CODEGEN_FUNCPTR *TexParameteri)(GLenum target, GLenum pname, GLint param);
	extern void (CODEGEN_FUNCPTR *TexParameteriv)(GLenum target, GLenum pname, const GLint *params);
	extern void (CODEGEN_FUNCPTR *TexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	extern void (CODEGEN_FUNCPTR *TexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	extern void (CODEGEN_FUNCPTR *DrawBuffer)(GLenum mode);
	extern void (CODEGEN_FUNCPTR *Clear)(GLbitfield mask);
	extern void (CODEGEN_FUNCPTR *ClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	extern void (CODEGEN_FUNCPTR *ClearStencil)(GLint s);
	extern void (CODEGEN_FUNCPTR *ClearDepth)(GLdouble depth);
	extern void (CODEGEN_FUNCPTR *StencilMask)(GLuint mask);
	extern void (CODEGEN_FUNCPTR *ColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
	extern void (CODEGEN_FUNCPTR *DepthMask)(GLboolean flag);
	extern void (CODEGEN_FUNCPTR *Disable)(GLenum cap);
	extern void (CODEGEN_FUNCPTR *Enable)(GLenum cap);
	extern void (CODEGEN_FUNCPTR *Finish)();
	extern void (CODEGEN_FUNCPTR *Flush)();
	extern void (CODEGEN_FUNCPTR *BlendFunc)(GLenum sfactor, GLenum dfactor);
	extern void (CODEGEN_FUNCPTR *LogicOp)(GLenum opcode);
	extern void (CODEGEN_FUNCPTR *StencilFunc)(GLenum func, GLint ref, GLuint mask);
	extern void (CODEGEN_FUNCPTR *StencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
	extern void (CODEGEN_FUNCPTR *DepthFunc)(GLenum func);
	extern void (CODEGEN_FUNCPTR *PixelStoref)(GLenum pname, GLfloat param);
	extern void (CODEGEN_FUNCPTR *PixelStorei)(GLenum pname, GLint param);
	extern void (CODEGEN_FUNCPTR *ReadBuffer)(GLenum mode);
	extern void (CODEGEN_FUNCPTR *ReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
	extern void (CODEGEN_FUNCPTR *GetBooleanv)(GLenum pname, GLboolean *params);
	extern void (CODEGEN_FUNCPTR *GetDoublev)(GLenum pname, GLdouble *params);
	extern GLenum (CODEGEN_FUNCPTR *GetError)();
	extern void (CODEGEN_FUNCPTR *GetFloatv)(GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetIntegerv)(GLenum pname, GLint *params);
	extern const GLubyte * (CODEGEN_FUNCPTR *GetString)(GLenum name);
	extern void (CODEGEN_FUNCPTR *GetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
	extern void (CODEGEN_FUNCPTR *GetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
	extern GLboolean (CODEGEN_FUNCPTR *IsEnabled)(GLenum cap);
	extern void (CODEGEN_FUNCPTR *DepthRange)(GLdouble ren_near, GLdouble ren_far);
	extern void (CODEGEN_FUNCPTR *Viewport)(GLint x, GLint y, GLsizei width, GLsizei height);
	extern void (CODEGEN_FUNCPTR *NewList)(GLuint list, GLenum mode);
	extern void (CODEGEN_FUNCPTR *EndList)();
	extern void (CODEGEN_FUNCPTR *CallList)(GLuint list);
	extern void (CODEGEN_FUNCPTR *CallLists)(GLsizei n, GLenum type, const GLvoid *lists);
	extern void (CODEGEN_FUNCPTR *DeleteLists)(GLuint list, GLsizei range);
	extern GLuint (CODEGEN_FUNCPTR *GenLists)(GLsizei range);
	extern void (CODEGEN_FUNCPTR *ListBase)(GLuint base);
	extern void (CODEGEN_FUNCPTR *Begin)(GLenum mode);
	extern void (CODEGEN_FUNCPTR *Bitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
	extern void (CODEGEN_FUNCPTR *Color3b)(GLbyte red, GLbyte green, GLbyte blue);
	extern void (CODEGEN_FUNCPTR *Color3bv)(const GLbyte *v);
	extern void (CODEGEN_FUNCPTR *Color3d)(GLdouble red, GLdouble green, GLdouble blue);
	extern void (CODEGEN_FUNCPTR *Color3dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *Color3f)(GLfloat red, GLfloat green, GLfloat blue);
	extern void (CODEGEN_FUNCPTR *Color3fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *Color3i)(GLint red, GLint green, GLint blue);
	extern void (CODEGEN_FUNCPTR *Color3iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *Color3s)(GLshort red, GLshort green, GLshort blue);
	extern void (CODEGEN_FUNCPTR *Color3sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *Color3ub)(GLubyte red, GLubyte green, GLubyte blue);
	extern void (CODEGEN_FUNCPTR *Color3ubv)(const GLubyte *v);
	extern void (CODEGEN_FUNCPTR *Color3ui)(GLuint red, GLuint green, GLuint blue);
	extern void (CODEGEN_FUNCPTR *Color3uiv)(const GLuint *v);
	extern void (CODEGEN_FUNCPTR *Color3us)(GLushort red, GLushort green, GLushort blue);
	extern void (CODEGEN_FUNCPTR *Color3usv)(const GLushort *v);
	extern void (CODEGEN_FUNCPTR *Color4b)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
	extern void (CODEGEN_FUNCPTR *Color4bv)(const GLbyte *v);
	extern void (CODEGEN_FUNCPTR *Color4d)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
	extern void (CODEGEN_FUNCPTR *Color4dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *Color4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	extern void (CODEGEN_FUNCPTR *Color4fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *Color4i)(GLint red, GLint green, GLint blue, GLint alpha);
	extern void (CODEGEN_FUNCPTR *Color4iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *Color4s)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
	extern void (CODEGEN_FUNCPTR *Color4sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *Color4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
	extern void (CODEGEN_FUNCPTR *Color4ubv)(const GLubyte *v);
	extern void (CODEGEN_FUNCPTR *Color4ui)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
	extern void (CODEGEN_FUNCPTR *Color4uiv)(const GLuint *v);
	extern void (CODEGEN_FUNCPTR *Color4us)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
	extern void (CODEGEN_FUNCPTR *Color4usv)(const GLushort *v);
	extern void (CODEGEN_FUNCPTR *EdgeFlag)(GLboolean flag);
	extern void (CODEGEN_FUNCPTR *EdgeFlagv)(const GLboolean *flag);
	extern void (CODEGEN_FUNCPTR *End)();
	extern void (CODEGEN_FUNCPTR *Indexd)(GLdouble c);
	extern void (CODEGEN_FUNCPTR *Indexdv)(const GLdouble *c);
	extern void (CODEGEN_FUNCPTR *Indexf)(GLfloat c);
	extern void (CODEGEN_FUNCPTR *Indexfv)(const GLfloat *c);
	extern void (CODEGEN_FUNCPTR *Indexi)(GLint c);
	extern void (CODEGEN_FUNCPTR *Indexiv)(const GLint *c);
	extern void (CODEGEN_FUNCPTR *Indexs)(GLshort c);
	extern void (CODEGEN_FUNCPTR *Indexsv)(const GLshort *c);
	extern void (CODEGEN_FUNCPTR *Normal3b)(GLbyte nx, GLbyte ny, GLbyte nz);
	extern void (CODEGEN_FUNCPTR *Normal3bv)(const GLbyte *v);
	extern void (CODEGEN_FUNCPTR *Normal3d)(GLdouble nx, GLdouble ny, GLdouble nz);
	extern void (CODEGEN_FUNCPTR *Normal3dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *Normal3f)(GLfloat nx, GLfloat ny, GLfloat nz);
	extern void (CODEGEN_FUNCPTR *Normal3fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *Normal3i)(GLint nx, GLint ny, GLint nz);
	extern void (CODEGEN_FUNCPTR *Normal3iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *Normal3s)(GLshort nx, GLshort ny, GLshort nz);
	extern void (CODEGEN_FUNCPTR *Normal3sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *RasterPos2d)(GLdouble x, GLdouble y);
	extern void (CODEGEN_FUNCPTR *RasterPos2dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *RasterPos2f)(GLfloat x, GLfloat y);
	extern void (CODEGEN_FUNCPTR *RasterPos2fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *RasterPos2i)(GLint x, GLint y);
	extern void (CODEGEN_FUNCPTR *RasterPos2iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *RasterPos2s)(GLshort x, GLshort y);
	extern void (CODEGEN_FUNCPTR *RasterPos2sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *RasterPos3d)(GLdouble x, GLdouble y, GLdouble z);
	extern void (CODEGEN_FUNCPTR *RasterPos3dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *RasterPos3f)(GLfloat x, GLfloat y, GLfloat z);
	extern void (CODEGEN_FUNCPTR *RasterPos3fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *RasterPos3i)(GLint x, GLint y, GLint z);
	extern void (CODEGEN_FUNCPTR *RasterPos3iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *RasterPos3s)(GLshort x, GLshort y, GLshort z);
	extern void (CODEGEN_FUNCPTR *RasterPos3sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *RasterPos4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	extern void (CODEGEN_FUNCPTR *RasterPos4dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *RasterPos4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	extern void (CODEGEN_FUNCPTR *RasterPos4fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *RasterPos4i)(GLint x, GLint y, GLint z, GLint w);
	extern void (CODEGEN_FUNCPTR *RasterPos4iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *RasterPos4s)(GLshort x, GLshort y, GLshort z, GLshort w);
	extern void (CODEGEN_FUNCPTR *RasterPos4sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *Rectd)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
	extern void (CODEGEN_FUNCPTR *Rectdv)(const GLdouble *v1, const GLdouble *v2);
	extern void (CODEGEN_FUNCPTR *Rectf)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
	extern void (CODEGEN_FUNCPTR *Rectfv)(const GLfloat *v1, const GLfloat *v2);
	extern void (CODEGEN_FUNCPTR *Recti)(GLint x1, GLint y1, GLint x2, GLint y2);
	extern void (CODEGEN_FUNCPTR *Rectiv)(const GLint *v1, const GLint *v2);
	extern void (CODEGEN_FUNCPTR *Rects)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
	extern void (CODEGEN_FUNCPTR *Rectsv)(const GLshort *v1, const GLshort *v2);
	extern void (CODEGEN_FUNCPTR *TexCoord1d)(GLdouble s);
	extern void (CODEGEN_FUNCPTR *TexCoord1dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *TexCoord1f)(GLfloat s);
	extern void (CODEGEN_FUNCPTR *TexCoord1fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *TexCoord1i)(GLint s);
	extern void (CODEGEN_FUNCPTR *TexCoord1iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *TexCoord1s)(GLshort s);
	extern void (CODEGEN_FUNCPTR *TexCoord1sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *TexCoord2d)(GLdouble s, GLdouble t);
	extern void (CODEGEN_FUNCPTR *TexCoord2dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *TexCoord2f)(GLfloat s, GLfloat t);
	extern void (CODEGEN_FUNCPTR *TexCoord2fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *TexCoord2i)(GLint s, GLint t);
	extern void (CODEGEN_FUNCPTR *TexCoord2iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *TexCoord2s)(GLshort s, GLshort t);
	extern void (CODEGEN_FUNCPTR *TexCoord2sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *TexCoord3d)(GLdouble s, GLdouble t, GLdouble r);
	extern void (CODEGEN_FUNCPTR *TexCoord3dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *TexCoord3f)(GLfloat s, GLfloat t, GLfloat r);
	extern void (CODEGEN_FUNCPTR *TexCoord3fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *TexCoord3i)(GLint s, GLint t, GLint r);
	extern void (CODEGEN_FUNCPTR *TexCoord3iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *TexCoord3s)(GLshort s, GLshort t, GLshort r);
	extern void (CODEGEN_FUNCPTR *TexCoord3sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *TexCoord4d)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	extern void (CODEGEN_FUNCPTR *TexCoord4dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *TexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	extern void (CODEGEN_FUNCPTR *TexCoord4fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *TexCoord4i)(GLint s, GLint t, GLint r, GLint q);
	extern void (CODEGEN_FUNCPTR *TexCoord4iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *TexCoord4s)(GLshort s, GLshort t, GLshort r, GLshort q);
	extern void (CODEGEN_FUNCPTR *TexCoord4sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *Vertex2d)(GLdouble x, GLdouble y);
	extern void (CODEGEN_FUNCPTR *Vertex2dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *Vertex2f)(GLfloat x, GLfloat y);
	extern void (CODEGEN_FUNCPTR *Vertex2fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *Vertex2i)(GLint x, GLint y);
	extern void (CODEGEN_FUNCPTR *Vertex2iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *Vertex2s)(GLshort x, GLshort y);
	extern void (CODEGEN_FUNCPTR *Vertex2sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *Vertex3d)(GLdouble x, GLdouble y, GLdouble z);
	extern void (CODEGEN_FUNCPTR *Vertex3dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *Vertex3f)(GLfloat x, GLfloat y, GLfloat z);
	extern void (CODEGEN_FUNCPTR *Vertex3fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *Vertex3i)(GLint x, GLint y, GLint z);
	extern void (CODEGEN_FUNCPTR *Vertex3iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *Vertex3s)(GLshort x, GLshort y, GLshort z);
	extern void (CODEGEN_FUNCPTR *Vertex3sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *Vertex4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	extern void (CODEGEN_FUNCPTR *Vertex4dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *Vertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	extern void (CODEGEN_FUNCPTR *Vertex4fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *Vertex4i)(GLint x, GLint y, GLint z, GLint w);
	extern void (CODEGEN_FUNCPTR *Vertex4iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *Vertex4s)(GLshort x, GLshort y, GLshort z, GLshort w);
	extern void (CODEGEN_FUNCPTR *Vertex4sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *ClipPlane)(GLenum plane, const GLdouble *equation);
	extern void (CODEGEN_FUNCPTR *ColorMaterial)(GLenum face, GLenum mode);
	extern void (CODEGEN_FUNCPTR *Fogf)(GLenum pname, GLfloat param);
	extern void (CODEGEN_FUNCPTR *Fogfv)(GLenum pname, const GLfloat *params);
	extern void (CODEGEN_FUNCPTR *Fogi)(GLenum pname, GLint param);
	extern void (CODEGEN_FUNCPTR *Fogiv)(GLenum pname, const GLint *params);
	extern void (CODEGEN_FUNCPTR *Lightf)(GLenum light, GLenum pname, GLfloat param);
	extern void (CODEGEN_FUNCPTR *Lightfv)(GLenum light, GLenum pname, const GLfloat *params);
	extern void (CODEGEN_FUNCPTR *Lighti)(GLenum light, GLenum pname, GLint param);
	extern void (CODEGEN_FUNCPTR *Lightiv)(GLenum light, GLenum pname, const GLint *params);
	extern void (CODEGEN_FUNCPTR *LightModelf)(GLenum pname, GLfloat param);
	extern void (CODEGEN_FUNCPTR *LightModelfv)(GLenum pname, const GLfloat *params);
	extern void (CODEGEN_FUNCPTR *LightModeli)(GLenum pname, GLint param);
	extern void (CODEGEN_FUNCPTR *LightModeliv)(GLenum pname, const GLint *params);
	extern void (CODEGEN_FUNCPTR *LineStipple)(GLint factor, GLushort pattern);
	extern void (CODEGEN_FUNCPTR *Materialf)(GLenum face, GLenum pname, GLfloat param);
	extern void (CODEGEN_FUNCPTR *Materialfv)(GLenum face, GLenum pname, const GLfloat *params);
	extern void (CODEGEN_FUNCPTR *Materiali)(GLenum face, GLenum pname, GLint param);
	extern void (CODEGEN_FUNCPTR *Materialiv)(GLenum face, GLenum pname, const GLint *params);
	extern void (CODEGEN_FUNCPTR *PolygonStipple)(const GLubyte *mask);
	extern void (CODEGEN_FUNCPTR *ShadeModel)(GLenum mode);
	extern void (CODEGEN_FUNCPTR *TexEnvf)(GLenum target, GLenum pname, GLfloat param);
	extern void (CODEGEN_FUNCPTR *TexEnvfv)(GLenum target, GLenum pname, const GLfloat *params);
	extern void (CODEGEN_FUNCPTR *TexEnvi)(GLenum target, GLenum pname, GLint param);
	extern void (CODEGEN_FUNCPTR *TexEnviv)(GLenum target, GLenum pname, const GLint *params);
	extern void (CODEGEN_FUNCPTR *TexGend)(GLenum coord, GLenum pname, GLdouble param);
	extern void (CODEGEN_FUNCPTR *TexGendv)(GLenum coord, GLenum pname, const GLdouble *params);
	extern void (CODEGEN_FUNCPTR *TexGenf)(GLenum coord, GLenum pname, GLfloat param);
	extern void (CODEGEN_FUNCPTR *TexGenfv)(GLenum coord, GLenum pname, const GLfloat *params);
	extern void (CODEGEN_FUNCPTR *TexGeni)(GLenum coord, GLenum pname, GLint param);
	extern void (CODEGEN_FUNCPTR *TexGeniv)(GLenum coord, GLenum pname, const GLint *params);
	extern void (CODEGEN_FUNCPTR *FeedbackBuffer)(GLsizei size, GLenum type, GLfloat *buffer);
	extern void (CODEGEN_FUNCPTR *SelectBuffer)(GLsizei size, GLuint *buffer);
	extern GLint (CODEGEN_FUNCPTR *RenderMode)(GLenum mode);
	extern void (CODEGEN_FUNCPTR *InitNames)();
	extern void (CODEGEN_FUNCPTR *LoadName)(GLuint name);
	extern void (CODEGEN_FUNCPTR *PassThrough)(GLfloat token);
	extern void (CODEGEN_FUNCPTR *PopName)();
	extern void (CODEGEN_FUNCPTR *PushName)(GLuint name);
	extern void (CODEGEN_FUNCPTR *ClearAccum)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	extern void (CODEGEN_FUNCPTR *ClearIndex)(GLfloat c);
	extern void (CODEGEN_FUNCPTR *IndexMask)(GLuint mask);
	extern void (CODEGEN_FUNCPTR *Accum)(GLenum op, GLfloat value);
	extern void (CODEGEN_FUNCPTR *PopAttrib)();
	extern void (CODEGEN_FUNCPTR *PushAttrib)(GLbitfield mask);
	extern void (CODEGEN_FUNCPTR *Map1d)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
	extern void (CODEGEN_FUNCPTR *Map1f)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
	extern void (CODEGEN_FUNCPTR *Map2d)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
	extern void (CODEGEN_FUNCPTR *Map2f)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
	extern void (CODEGEN_FUNCPTR *MapGrid1d)(GLint un, GLdouble u1, GLdouble u2);
	extern void (CODEGEN_FUNCPTR *MapGrid1f)(GLint un, GLfloat u1, GLfloat u2);
	extern void (CODEGEN_FUNCPTR *MapGrid2d)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
	extern void (CODEGEN_FUNCPTR *MapGrid2f)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
	extern void (CODEGEN_FUNCPTR *EvalCoord1d)(GLdouble u);
	extern void (CODEGEN_FUNCPTR *EvalCoord1dv)(const GLdouble *u);
	extern void (CODEGEN_FUNCPTR *EvalCoord1f)(GLfloat u);
	extern void (CODEGEN_FUNCPTR *EvalCoord1fv)(const GLfloat *u);
	extern void (CODEGEN_FUNCPTR *EvalCoord2d)(GLdouble u, GLdouble v);
	extern void (CODEGEN_FUNCPTR *EvalCoord2dv)(const GLdouble *u);
	extern void (CODEGEN_FUNCPTR *EvalCoord2f)(GLfloat u, GLfloat v);
	extern void (CODEGEN_FUNCPTR *EvalCoord2fv)(const GLfloat *u);
	extern void (CODEGEN_FUNCPTR *EvalMesh1)(GLenum mode, GLint i1, GLint i2);
	extern void (CODEGEN_FUNCPTR *EvalPoint1)(GLint i);
	extern void (CODEGEN_FUNCPTR *EvalMesh2)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
	extern void (CODEGEN_FUNCPTR *EvalPoint2)(GLint i, GLint j);
	extern void (CODEGEN_FUNCPTR *AlphaFunc)(GLenum func, GLfloat ref);
	extern void (CODEGEN_FUNCPTR *PixelZoom)(GLfloat xfactor, GLfloat yfactor);
	extern void (CODEGEN_FUNCPTR *PixelTransferf)(GLenum pname, GLfloat param);
	extern void (CODEGEN_FUNCPTR *PixelTransferi)(GLenum pname, GLint param);
	extern void (CODEGEN_FUNCPTR *PixelMapfv)(GLenum map, GLsizei mapsize, const GLfloat *values);
	extern void (CODEGEN_FUNCPTR *PixelMapuiv)(GLenum map, GLsizei mapsize, const GLuint *values);
	extern void (CODEGEN_FUNCPTR *PixelMapusv)(GLenum map, GLsizei mapsize, const GLushort *values);
	extern void (CODEGEN_FUNCPTR *CopyPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
	extern void (CODEGEN_FUNCPTR *DrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
	extern void (CODEGEN_FUNCPTR *GetClipPlane)(GLenum plane, GLdouble *equation);
	extern void (CODEGEN_FUNCPTR *GetLightfv)(GLenum light, GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetLightiv)(GLenum light, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetMapdv)(GLenum target, GLenum query, GLdouble *v);
	extern void (CODEGEN_FUNCPTR *GetMapfv)(GLenum target, GLenum query, GLfloat *v);
	extern void (CODEGEN_FUNCPTR *GetMapiv)(GLenum target, GLenum query, GLint *v);
	extern void (CODEGEN_FUNCPTR *GetMaterialfv)(GLenum face, GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetMaterialiv)(GLenum face, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetPixelMapfv)(GLenum map, GLfloat *values);
	extern void (CODEGEN_FUNCPTR *GetPixelMapuiv)(GLenum map, GLuint *values);
	extern void (CODEGEN_FUNCPTR *GetPixelMapusv)(GLenum map, GLushort *values);
	extern void (CODEGEN_FUNCPTR *GetPolygonStipple)(GLubyte *mask);
	extern void (CODEGEN_FUNCPTR *GetTexEnvfv)(GLenum target, GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetTexEnviv)(GLenum target, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetTexGendv)(GLenum coord, GLenum pname, GLdouble *params);
	extern void (CODEGEN_FUNCPTR *GetTexGenfv)(GLenum coord, GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetTexGeniv)(GLenum coord, GLenum pname, GLint *params);
	extern GLboolean (CODEGEN_FUNCPTR *IsList)(GLuint list);
	extern void (CODEGEN_FUNCPTR *Frustum)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	extern void (CODEGEN_FUNCPTR *LoadIdentity)();
	extern void (CODEGEN_FUNCPTR *LoadMatrixf)(const GLfloat *m);
	extern void (CODEGEN_FUNCPTR *LoadMatrixd)(const GLdouble *m);
	extern void (CODEGEN_FUNCPTR *MatrixMode)(GLenum mode);
	extern void (CODEGEN_FUNCPTR *MultMatrixf)(const GLfloat *m);
	extern void (CODEGEN_FUNCPTR *MultMatrixd)(const GLdouble *m);
	extern void (CODEGEN_FUNCPTR *Ortho)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
	extern void (CODEGEN_FUNCPTR *PopMatrix)();
	extern void (CODEGEN_FUNCPTR *PushMatrix)();
	extern void (CODEGEN_FUNCPTR *Rotated)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
	extern void (CODEGEN_FUNCPTR *Rotatef)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	extern void (CODEGEN_FUNCPTR *Scaled)(GLdouble x, GLdouble y, GLdouble z);
	extern void (CODEGEN_FUNCPTR *Scalef)(GLfloat x, GLfloat y, GLfloat z);
	extern void (CODEGEN_FUNCPTR *Translated)(GLdouble x, GLdouble y, GLdouble z);
	extern void (CODEGEN_FUNCPTR *Translatef)(GLfloat x, GLfloat y, GLfloat z);
	extern void (CODEGEN_FUNCPTR *DrawArrays)(GLenum mode, GLint first, GLsizei count);
	extern void (CODEGEN_FUNCPTR *DrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
	extern void (CODEGEN_FUNCPTR *GetPointerv)(GLenum pname, GLvoid* *params);
	extern void (CODEGEN_FUNCPTR *PolygonOffset)(GLfloat factor, GLfloat units);
	extern void (CODEGEN_FUNCPTR *CopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
	extern void (CODEGEN_FUNCPTR *CopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	extern void (CODEGEN_FUNCPTR *CopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
	extern void (CODEGEN_FUNCPTR *CopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	extern void (CODEGEN_FUNCPTR *TexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
	extern void (CODEGEN_FUNCPTR *TexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
	extern void (CODEGEN_FUNCPTR *BindTexture)(GLenum target, GLuint texture);
	extern void (CODEGEN_FUNCPTR *DeleteTextures)(GLsizei n, const GLuint *textures);
	extern void (CODEGEN_FUNCPTR *GenTextures)(GLsizei n, GLuint *textures);
	extern GLboolean (CODEGEN_FUNCPTR *IsTexture)(GLuint texture);
	extern void (CODEGEN_FUNCPTR *ArrayElement)(GLint i);
	extern void (CODEGEN_FUNCPTR *ColorPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	extern void (CODEGEN_FUNCPTR *DisableClientState)(GLenum ren_array);
	extern void (CODEGEN_FUNCPTR *EdgeFlagPointer)(GLsizei stride, const GLvoid *pointer);
	extern void (CODEGEN_FUNCPTR *EnableClientState)(GLenum ren_array);
	extern void (CODEGEN_FUNCPTR *IndexPointer)(GLenum type, GLsizei stride, const GLvoid *pointer);
	extern void (CODEGEN_FUNCPTR *InterleavedArrays)(GLenum format, GLsizei stride, const GLvoid *pointer);
	extern void (CODEGEN_FUNCPTR *NormalPointer)(GLenum type, GLsizei stride, const GLvoid *pointer);
	extern void (CODEGEN_FUNCPTR *TexCoordPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	extern void (CODEGEN_FUNCPTR *VertexPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	extern GLboolean (CODEGEN_FUNCPTR *AreTexturesResident)(GLsizei n, const GLuint *textures, GLboolean *residences);
	extern void (CODEGEN_FUNCPTR *PrioritizeTextures)(GLsizei n, const GLuint *textures, const GLfloat *priorities);
	extern void (CODEGEN_FUNCPTR *Indexub)(GLubyte c);
	extern void (CODEGEN_FUNCPTR *Indexubv)(const GLubyte *c);
	extern void (CODEGEN_FUNCPTR *PopClientAttrib)();
	extern void (CODEGEN_FUNCPTR *PushClientAttrib)(GLbitfield mask);
	
	
	extern void (CODEGEN_FUNCPTR *BlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	extern void (CODEGEN_FUNCPTR *BlendEquation)(GLenum mode);
	extern void (CODEGEN_FUNCPTR *DrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
	extern void (CODEGEN_FUNCPTR *TexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
	extern void (CODEGEN_FUNCPTR *TexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
	extern void (CODEGEN_FUNCPTR *CopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	extern void (CODEGEN_FUNCPTR *ColorTable)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
	extern void (CODEGEN_FUNCPTR *ColorTableParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
	extern void (CODEGEN_FUNCPTR *ColorTableParameteriv)(GLenum target, GLenum pname, const GLint *params);
	extern void (CODEGEN_FUNCPTR *CopyColorTable)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	extern void (CODEGEN_FUNCPTR *GetColorTable)(GLenum target, GLenum format, GLenum type, GLvoid *table);
	extern void (CODEGEN_FUNCPTR *GetColorTableParameterfv)(GLenum target, GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetColorTableParameteriv)(GLenum target, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *ColorSubTable)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
	extern void (CODEGEN_FUNCPTR *CopyColorSubTable)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
	extern void (CODEGEN_FUNCPTR *ConvolutionFilter1D)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
	extern void (CODEGEN_FUNCPTR *ConvolutionFilter2D)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
	extern void (CODEGEN_FUNCPTR *ConvolutionParameterf)(GLenum target, GLenum pname, GLfloat params);
	extern void (CODEGEN_FUNCPTR *ConvolutionParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
	extern void (CODEGEN_FUNCPTR *ConvolutionParameteri)(GLenum target, GLenum pname, GLint params);
	extern void (CODEGEN_FUNCPTR *ConvolutionParameteriv)(GLenum target, GLenum pname, const GLint *params);
	extern void (CODEGEN_FUNCPTR *CopyConvolutionFilter1D)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
	extern void (CODEGEN_FUNCPTR *CopyConvolutionFilter2D)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
	extern void (CODEGEN_FUNCPTR *GetConvolutionFilter)(GLenum target, GLenum format, GLenum type, GLvoid *image);
	extern void (CODEGEN_FUNCPTR *GetConvolutionParameterfv)(GLenum target, GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetConvolutionParameteriv)(GLenum target, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetSeparableFilter)(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
	extern void (CODEGEN_FUNCPTR *SeparableFilter2D)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
	extern void (CODEGEN_FUNCPTR *GetHistogram)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
	extern void (CODEGEN_FUNCPTR *GetHistogramParameterfv)(GLenum target, GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetHistogramParameteriv)(GLenum target, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetMinmax)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
	extern void (CODEGEN_FUNCPTR *GetMinmaxParameterfv)(GLenum target, GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetMinmaxParameteriv)(GLenum target, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *Histogram)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
	extern void (CODEGEN_FUNCPTR *Minmax)(GLenum target, GLenum internalformat, GLboolean sink);
	extern void (CODEGEN_FUNCPTR *ResetHistogram)(GLenum target);
	extern void (CODEGEN_FUNCPTR *ResetMinmax)(GLenum target);
	
	extern void (CODEGEN_FUNCPTR *ActiveTexture)(GLenum texture);
	extern void (CODEGEN_FUNCPTR *SampleCoverage)(GLfloat value, GLboolean invert);
	extern void (CODEGEN_FUNCPTR *CompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
	extern void (CODEGEN_FUNCPTR *CompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
	extern void (CODEGEN_FUNCPTR *CompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
	extern void (CODEGEN_FUNCPTR *CompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
	extern void (CODEGEN_FUNCPTR *CompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
	extern void (CODEGEN_FUNCPTR *CompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
	extern void (CODEGEN_FUNCPTR *GetCompressedTexImage)(GLenum target, GLint level, GLvoid *img);
	extern void (CODEGEN_FUNCPTR *ClientActiveTexture)(GLenum texture);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord1d)(GLenum target, GLdouble s);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord1dv)(GLenum target, const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord1f)(GLenum target, GLfloat s);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord1fv)(GLenum target, const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord1i)(GLenum target, GLint s);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord1iv)(GLenum target, const GLint *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord1s)(GLenum target, GLshort s);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord1sv)(GLenum target, const GLshort *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord2d)(GLenum target, GLdouble s, GLdouble t);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord2dv)(GLenum target, const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord2f)(GLenum target, GLfloat s, GLfloat t);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord2fv)(GLenum target, const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord2i)(GLenum target, GLint s, GLint t);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord2iv)(GLenum target, const GLint *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord2s)(GLenum target, GLshort s, GLshort t);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord2sv)(GLenum target, const GLshort *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord3d)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord3dv)(GLenum target, const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord3f)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord3fv)(GLenum target, const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord3i)(GLenum target, GLint s, GLint t, GLint r);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord3iv)(GLenum target, const GLint *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord3s)(GLenum target, GLshort s, GLshort t, GLshort r);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord3sv)(GLenum target, const GLshort *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord4d)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord4dv)(GLenum target, const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord4f)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord4fv)(GLenum target, const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord4i)(GLenum target, GLint s, GLint t, GLint r, GLint q);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord4iv)(GLenum target, const GLint *v);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord4s)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
	extern void (CODEGEN_FUNCPTR *MultiTexCoord4sv)(GLenum target, const GLshort *v);
	extern void (CODEGEN_FUNCPTR *LoadTransposeMatrixf)(const GLfloat *m);
	extern void (CODEGEN_FUNCPTR *LoadTransposeMatrixd)(const GLdouble *m);
	extern void (CODEGEN_FUNCPTR *MultTransposeMatrixf)(const GLfloat *m);
	extern void (CODEGEN_FUNCPTR *MultTransposeMatrixd)(const GLdouble *m);
	
	extern void (CODEGEN_FUNCPTR *BlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	extern void (CODEGEN_FUNCPTR *MultiDrawArrays)(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
	extern void (CODEGEN_FUNCPTR *MultiDrawElements)(GLenum mode, const GLsizei *count, GLenum type, const GLvoid* const *indices, GLsizei drawcount);
	extern void (CODEGEN_FUNCPTR *PointParameterf)(GLenum pname, GLfloat param);
	extern void (CODEGEN_FUNCPTR *PointParameterfv)(GLenum pname, const GLfloat *params);
	extern void (CODEGEN_FUNCPTR *PointParameteri)(GLenum pname, GLint param);
	extern void (CODEGEN_FUNCPTR *PointParameteriv)(GLenum pname, const GLint *params);
	extern void (CODEGEN_FUNCPTR *FogCoordf)(GLfloat coord);
	extern void (CODEGEN_FUNCPTR *FogCoordfv)(const GLfloat *coord);
	extern void (CODEGEN_FUNCPTR *FogCoordd)(GLdouble coord);
	extern void (CODEGEN_FUNCPTR *FogCoorddv)(const GLdouble *coord);
	extern void (CODEGEN_FUNCPTR *FogCoordPointer)(GLenum type, GLsizei stride, const GLvoid *pointer);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3b)(GLbyte red, GLbyte green, GLbyte blue);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3bv)(const GLbyte *v);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3d)(GLdouble red, GLdouble green, GLdouble blue);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3f)(GLfloat red, GLfloat green, GLfloat blue);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3i)(GLint red, GLint green, GLint blue);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3s)(GLshort red, GLshort green, GLshort blue);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3ub)(GLubyte red, GLubyte green, GLubyte blue);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3ubv)(const GLubyte *v);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3ui)(GLuint red, GLuint green, GLuint blue);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3uiv)(const GLuint *v);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3us)(GLushort red, GLushort green, GLushort blue);
	extern void (CODEGEN_FUNCPTR *SecondaryColor3usv)(const GLushort *v);
	extern void (CODEGEN_FUNCPTR *SecondaryColorPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
	extern void (CODEGEN_FUNCPTR *WindowPos2d)(GLdouble x, GLdouble y);
	extern void (CODEGEN_FUNCPTR *WindowPos2dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *WindowPos2f)(GLfloat x, GLfloat y);
	extern void (CODEGEN_FUNCPTR *WindowPos2fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *WindowPos2i)(GLint x, GLint y);
	extern void (CODEGEN_FUNCPTR *WindowPos2iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *WindowPos2s)(GLshort x, GLshort y);
	extern void (CODEGEN_FUNCPTR *WindowPos2sv)(const GLshort *v);
	extern void (CODEGEN_FUNCPTR *WindowPos3d)(GLdouble x, GLdouble y, GLdouble z);
	extern void (CODEGEN_FUNCPTR *WindowPos3dv)(const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *WindowPos3f)(GLfloat x, GLfloat y, GLfloat z);
	extern void (CODEGEN_FUNCPTR *WindowPos3fv)(const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *WindowPos3i)(GLint x, GLint y, GLint z);
	extern void (CODEGEN_FUNCPTR *WindowPos3iv)(const GLint *v);
	extern void (CODEGEN_FUNCPTR *WindowPos3s)(GLshort x, GLshort y, GLshort z);
	extern void (CODEGEN_FUNCPTR *WindowPos3sv)(const GLshort *v);
	
	extern void (CODEGEN_FUNCPTR *GenQueries)(GLsizei n, GLuint *ids);
	extern void (CODEGEN_FUNCPTR *DeleteQueries)(GLsizei n, const GLuint *ids);
	extern GLboolean (CODEGEN_FUNCPTR *IsQuery)(GLuint id);
	extern void (CODEGEN_FUNCPTR *BeginQuery)(GLenum target, GLuint id);
	extern void (CODEGEN_FUNCPTR *EndQuery)(GLenum target);
	extern void (CODEGEN_FUNCPTR *GetQueryiv)(GLenum target, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetQueryObjectiv)(GLuint id, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetQueryObjectuiv)(GLuint id, GLenum pname, GLuint *params);
	extern void (CODEGEN_FUNCPTR *BindBuffer)(GLenum target, GLuint buffer);
	extern void (CODEGEN_FUNCPTR *DeleteBuffers)(GLsizei n, const GLuint *buffers);
	extern void (CODEGEN_FUNCPTR *GenBuffers)(GLsizei n, GLuint *buffers);
	extern GLboolean (CODEGEN_FUNCPTR *IsBuffer)(GLuint buffer);
	extern void (CODEGEN_FUNCPTR *BufferData)(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
	extern void (CODEGEN_FUNCPTR *BufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
	extern void (CODEGEN_FUNCPTR *GetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);
	extern GLvoid* (CODEGEN_FUNCPTR *MapBuffer)(GLenum target, GLenum access);
	extern GLboolean (CODEGEN_FUNCPTR *UnmapBuffer)(GLenum target);
	extern void (CODEGEN_FUNCPTR *GetBufferParameteriv)(GLenum target, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetBufferPointerv)(GLenum target, GLenum pname, GLvoid* *params);
	
	extern void (CODEGEN_FUNCPTR *BlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha);
	extern void (CODEGEN_FUNCPTR *DrawBuffers)(GLsizei n, const GLenum *bufs);
	extern void (CODEGEN_FUNCPTR *StencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
	extern void (CODEGEN_FUNCPTR *StencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask);
	extern void (CODEGEN_FUNCPTR *StencilMaskSeparate)(GLenum face, GLuint mask);
	extern void (CODEGEN_FUNCPTR *AttachShader)(GLuint program, GLuint shader);
	extern void (CODEGEN_FUNCPTR *BindAttribLocation)(GLuint program, GLuint index, const GLchar *name);
	extern void (CODEGEN_FUNCPTR *CompileShader)(GLuint shader);
	extern GLuint (CODEGEN_FUNCPTR *CreateProgram)();
	extern GLuint (CODEGEN_FUNCPTR *CreateShader)(GLenum type);
	extern void (CODEGEN_FUNCPTR *DeleteProgram)(GLuint program);
	extern void (CODEGEN_FUNCPTR *DeleteShader)(GLuint shader);
	extern void (CODEGEN_FUNCPTR *DetachShader)(GLuint program, GLuint shader);
	extern void (CODEGEN_FUNCPTR *DisableVertexAttribArray)(GLuint index);
	extern void (CODEGEN_FUNCPTR *EnableVertexAttribArray)(GLuint index);
	extern void (CODEGEN_FUNCPTR *GetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	extern void (CODEGEN_FUNCPTR *GetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	extern void (CODEGEN_FUNCPTR *GetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *obj);
	extern GLint (CODEGEN_FUNCPTR *GetAttribLocation)(GLuint program, const GLchar *name);
	extern void (CODEGEN_FUNCPTR *GetProgramiv)(GLuint program, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	extern void (CODEGEN_FUNCPTR *GetShaderiv)(GLuint shader, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	extern void (CODEGEN_FUNCPTR *GetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
	extern GLint (CODEGEN_FUNCPTR *GetUniformLocation)(GLuint program, const GLchar *name);
	extern void (CODEGEN_FUNCPTR *GetUniformfv)(GLuint program, GLint location, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetUniformiv)(GLuint program, GLint location, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetVertexAttribdv)(GLuint index, GLenum pname, GLdouble *params);
	extern void (CODEGEN_FUNCPTR *GetVertexAttribfv)(GLuint index, GLenum pname, GLfloat *params);
	extern void (CODEGEN_FUNCPTR *GetVertexAttribiv)(GLuint index, GLenum pname, GLint *params);
	extern void (CODEGEN_FUNCPTR *GetVertexAttribPointerv)(GLuint index, GLenum pname, GLvoid* *pointer);
	extern GLboolean (CODEGEN_FUNCPTR *IsProgram)(GLuint program);
	extern GLboolean (CODEGEN_FUNCPTR *IsShader)(GLuint shader);
	extern void (CODEGEN_FUNCPTR *LinkProgram)(GLuint program);
	extern void (CODEGEN_FUNCPTR *ShaderSource)(GLuint shader, GLsizei count, const GLchar* const *string, const GLint *length);
	extern void (CODEGEN_FUNCPTR *UseProgram)(GLuint program);
	extern void (CODEGEN_FUNCPTR *Uniform1f)(GLint location, GLfloat v0);
	extern void (CODEGEN_FUNCPTR *Uniform2f)(GLint location, GLfloat v0, GLfloat v1);
	extern void (CODEGEN_FUNCPTR *Uniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	extern void (CODEGEN_FUNCPTR *Uniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	extern void (CODEGEN_FUNCPTR *Uniform1i)(GLint location, GLint v0);
	extern void (CODEGEN_FUNCPTR *Uniform2i)(GLint location, GLint v0, GLint v1);
	extern void (CODEGEN_FUNCPTR *Uniform3i)(GLint location, GLint v0, GLint v1, GLint v2);
	extern void (CODEGEN_FUNCPTR *Uniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	extern void (CODEGEN_FUNCPTR *Uniform1fv)(GLint location, GLsizei count, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *Uniform2fv)(GLint location, GLsizei count, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *Uniform3fv)(GLint location, GLsizei count, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *Uniform4fv)(GLint location, GLsizei count, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *Uniform1iv)(GLint location, GLsizei count, const GLint *value);
	extern void (CODEGEN_FUNCPTR *Uniform2iv)(GLint location, GLsizei count, const GLint *value);
	extern void (CODEGEN_FUNCPTR *Uniform3iv)(GLint location, GLsizei count, const GLint *value);
	extern void (CODEGEN_FUNCPTR *Uniform4iv)(GLint location, GLsizei count, const GLint *value);
	extern void (CODEGEN_FUNCPTR *UniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *UniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *UniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *ValidateProgram)(GLuint program);
	extern void (CODEGEN_FUNCPTR *VertexAttrib1d)(GLuint index, GLdouble x);
	extern void (CODEGEN_FUNCPTR *VertexAttrib1dv)(GLuint index, const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib1f)(GLuint index, GLfloat x);
	extern void (CODEGEN_FUNCPTR *VertexAttrib1fv)(GLuint index, const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib1s)(GLuint index, GLshort x);
	extern void (CODEGEN_FUNCPTR *VertexAttrib1sv)(GLuint index, const GLshort *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
	extern void (CODEGEN_FUNCPTR *VertexAttrib2dv)(GLuint index, const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
	extern void (CODEGEN_FUNCPTR *VertexAttrib2fv)(GLuint index, const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib2s)(GLuint index, GLshort x, GLshort y);
	extern void (CODEGEN_FUNCPTR *VertexAttrib2sv)(GLuint index, const GLshort *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
	extern void (CODEGEN_FUNCPTR *VertexAttrib3dv)(GLuint index, const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
	extern void (CODEGEN_FUNCPTR *VertexAttrib3fv)(GLuint index, const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
	extern void (CODEGEN_FUNCPTR *VertexAttrib3sv)(GLuint index, const GLshort *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4Nbv)(GLuint index, const GLbyte *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4Niv)(GLuint index, const GLint *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4Nsv)(GLuint index, const GLshort *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4Nubv)(GLuint index, const GLubyte *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4Nuiv)(GLuint index, const GLuint *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4Nusv)(GLuint index, const GLushort *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4bv)(GLuint index, const GLbyte *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4dv)(GLuint index, const GLdouble *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4fv)(GLuint index, const GLfloat *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4iv)(GLuint index, const GLint *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4sv)(GLuint index, const GLshort *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4ubv)(GLuint index, const GLubyte *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4uiv)(GLuint index, const GLuint *v);
	extern void (CODEGEN_FUNCPTR *VertexAttrib4usv)(GLuint index, const GLushort *v);
	extern void (CODEGEN_FUNCPTR *VertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
	
	extern void (CODEGEN_FUNCPTR *UniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *UniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *UniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *UniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *UniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	extern void (CODEGEN_FUNCPTR *UniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	
	namespace sys
	{
		
		exts::LoadTest LoadFunctions();
		
		int GetMinorVersion();
		int GetMajorVersion();
		bool IsVersionGEQ(int majorVersion, int minorVersion);
		
	} //namespace sys
} //namespace gl
#endif //POINTER_CPP_GENERATED_HEADEROPENGL_HPP
