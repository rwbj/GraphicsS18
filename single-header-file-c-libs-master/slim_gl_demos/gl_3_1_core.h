#ifndef OPENGL_NOLOAD_STYLE_H
#define OPENGL_NOLOAD_STYLE_H

/**
 * This header only contains the OpenGL 3.1 core profile definitions. It's meant
 * to be used on Linux where you can directly link against libGL.so and the operating
 * system loader loads all the OpenGL function pointers. On Windows you need to
 * use the header in the win directory since extra code is necessary to load the
 * function pointers.
 * 
 * The header file was generated with glLoadGen in the noload_c style. The actual
 * loading code was removed by hand so only the definitions remained.
 */

#if defined(__glew_h__) || defined(__GLEW_H__)
#error Attempt to include auto-generated header after including glew.h
#endif
#if defined(__gl_h_) || defined(__GL_H__)
#error Attempt to include auto-generated header after including gl.h
#endif
#if defined(__glext_h_) || defined(__GLEXT_H_)
#error Attempt to include auto-generated header after including glext.h
#endif
#if defined(__gltypes_h_)
#error Attempt to include auto-generated header after gltypes.h
#endif
#if defined(__gl_ATI_h_)
#error Attempt to include auto-generated header after including glATI.h
#endif

#define __glew_h__
#define __GLEW_H__
#define __gl_h_
#define __GL_H__
#define __glext_h_
#define __GLEXT_H_
#define __gltypes_h_
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


#endif /*GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS*/

#include <stddef.h>
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
	typedef unsigned int GLenum;
	typedef unsigned char GLboolean;
	typedef unsigned int GLbitfield;
	typedef void GLvoid;
	typedef signed char GLbyte;
	typedef short GLshort;
	typedef int GLint;
	typedef unsigned char GLubyte;
	typedef unsigned short GLushort;
	typedef unsigned int GLuint;
	typedef int GLsizei;
	typedef float GLfloat;
	typedef float GLclampf;
	typedef double GLdouble;
	typedef double GLclampd;
	typedef char GLchar;
	typedef char GLcharARB;
	#ifdef __APPLE__
typedef void *GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif
		typedef unsigned short GLhalfARB;
		typedef unsigned short GLhalf;
		typedef GLint GLfixed;
		typedef ptrdiff_t GLintptr;
		typedef ptrdiff_t GLsizeiptr;
		typedef int64_t GLint64;
		typedef uint64_t GLuint64;
		typedef ptrdiff_t GLintptrARB;
		typedef ptrdiff_t GLsizeiptrARB;
		typedef int64_t GLint64EXT;
		typedef uint64_t GLuint64EXT;
		typedef struct __GLsync *GLsync;
		struct _cl_context;
		struct _cl_event;
		typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
		typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
		typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
		typedef unsigned short GLhalfNV;
		typedef GLintptr GLvdpauSurfaceNV;
		
		#ifdef __cplusplus
		extern "C" {
		#endif /*__cplusplus*/
		
		/////////////////////////
		// Extension Variables
		
		
		// Version: 1.1
		#define GL_2D                            0x0600
		#define GL_2_BYTES                       0x1407
		#define GL_3D                            0x0601
		#define GL_3D_COLOR                      0x0602
		#define GL_3D_COLOR_TEXTURE              0x0603
		#define GL_3_BYTES                       0x1408
		#define GL_4D_COLOR_TEXTURE              0x0604
		#define GL_4_BYTES                       0x1409
		#define GL_ACCUM                         0x0100
		#define GL_ACCUM_ALPHA_BITS              0x0D5B
		#define GL_ACCUM_BLUE_BITS               0x0D5A
		#define GL_ACCUM_BUFFER_BIT              0x00000200
		#define GL_ACCUM_CLEAR_VALUE             0x0B80
		#define GL_ACCUM_GREEN_BITS              0x0D59
		#define GL_ACCUM_RED_BITS                0x0D58
		#define GL_ADD                           0x0104
		#define GL_ALL_ATTRIB_BITS               0xFFFFFFFF
		#define GL_ALPHA                         0x1906
		#define GL_ALPHA12                       0x803D
		#define GL_ALPHA16                       0x803E
		#define GL_ALPHA4                        0x803B
		#define GL_ALPHA8                        0x803C
		#define GL_ALPHA_BIAS                    0x0D1D
		#define GL_ALPHA_BITS                    0x0D55
		#define GL_ALPHA_SCALE                   0x0D1C
		#define GL_ALPHA_TEST                    0x0BC0
		#define GL_ALPHA_TEST_FUNC               0x0BC1
		#define GL_ALPHA_TEST_REF                0x0BC2
		#define GL_ALWAYS                        0x0207
		#define GL_AMBIENT                       0x1200
		#define GL_AMBIENT_AND_DIFFUSE           0x1602
		#define GL_AND                           0x1501
		#define GL_AND_INVERTED                  0x1504
		#define GL_AND_REVERSE                   0x1502
		#define GL_ATTRIB_STACK_DEPTH            0x0BB0
		#define GL_AUTO_NORMAL                   0x0D80
		#define GL_AUX0                          0x0409
		#define GL_AUX1                          0x040A
		#define GL_AUX2                          0x040B
		#define GL_AUX3                          0x040C
		#define GL_AUX_BUFFERS                   0x0C00
		#define GL_BACK                          0x0405
		#define GL_BACK_LEFT                     0x0402
		#define GL_BACK_RIGHT                    0x0403
		#define GL_BITMAP                        0x1A00
		#define GL_BITMAP_TOKEN                  0x0704
		#define GL_BLEND                         0x0BE2
		#define GL_BLEND_DST                     0x0BE0
		#define GL_BLEND_SRC                     0x0BE1
		#define GL_BLUE                          0x1905
		#define GL_BLUE_BIAS                     0x0D1B
		#define GL_BLUE_BITS                     0x0D54
		#define GL_BLUE_SCALE                    0x0D1A
		#define GL_BYTE                          0x1400
		#define GL_C3F_V3F                       0x2A24
		#define GL_C4F_N3F_V3F                   0x2A26
		#define GL_C4UB_V2F                      0x2A22
		#define GL_C4UB_V3F                      0x2A23
		#define GL_CCW                           0x0901
		#define GL_CLAMP                         0x2900
		#define GL_CLEAR                         0x1500
		#define GL_CLIENT_ALL_ATTRIB_BITS        0xFFFFFFFF
		#define GL_CLIENT_ATTRIB_STACK_DEPTH     0x0BB1
		#define GL_CLIENT_PIXEL_STORE_BIT        0x00000001
		#define GL_CLIENT_VERTEX_ARRAY_BIT       0x00000002
		#define GL_CLIP_PLANE0                   0x3000
		#define GL_CLIP_PLANE1                   0x3001
		#define GL_CLIP_PLANE2                   0x3002
		#define GL_CLIP_PLANE3                   0x3003
		#define GL_CLIP_PLANE4                   0x3004
		#define GL_CLIP_PLANE5                   0x3005
		#define GL_COEFF                         0x0A00
		#define GL_COLOR                         0x1800
		#define GL_COLOR_ARRAY                   0x8076
		#define GL_COLOR_ARRAY_POINTER           0x8090
		#define GL_COLOR_ARRAY_SIZE              0x8081
		#define GL_COLOR_ARRAY_STRIDE            0x8083
		#define GL_COLOR_ARRAY_TYPE              0x8082
		#define GL_COLOR_BUFFER_BIT              0x00004000
		#define GL_COLOR_CLEAR_VALUE             0x0C22
		#define GL_COLOR_INDEX                   0x1900
		#define GL_COLOR_INDEXES                 0x1603
		#define GL_COLOR_LOGIC_OP                0x0BF2
		#define GL_COLOR_MATERIAL                0x0B57
		#define GL_COLOR_MATERIAL_FACE           0x0B55
		#define GL_COLOR_MATERIAL_PARAMETER      0x0B56
		#define GL_COLOR_WRITEMASK               0x0C23
		#define GL_COMPILE                       0x1300
		#define GL_COMPILE_AND_EXECUTE           0x1301
		#define GL_CONSTANT_ATTENUATION          0x1207
		#define GL_COPY                          0x1503
		#define GL_COPY_INVERTED                 0x150C
		#define GL_COPY_PIXEL_TOKEN              0x0706
		#define GL_CULL_FACE                     0x0B44
		#define GL_CULL_FACE_MODE                0x0B45
		#define GL_CURRENT_BIT                   0x00000001
		#define GL_CURRENT_COLOR                 0x0B00
		#define GL_CURRENT_INDEX                 0x0B01
		#define GL_CURRENT_NORMAL                0x0B02
		#define GL_CURRENT_RASTER_COLOR          0x0B04
		#define GL_CURRENT_RASTER_DISTANCE       0x0B09
		#define GL_CURRENT_RASTER_INDEX          0x0B05
		#define GL_CURRENT_RASTER_POSITION       0x0B07
		#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
		#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
		#define GL_CURRENT_TEXTURE_COORDS        0x0B03
		#define GL_CW                            0x0900
		#define GL_DECAL                         0x2101
		#define GL_DECR                          0x1E03
		#define GL_DEPTH                         0x1801
		#define GL_DEPTH_BIAS                    0x0D1F
		#define GL_DEPTH_BITS                    0x0D56
		#define GL_DEPTH_BUFFER_BIT              0x00000100
		#define GL_DEPTH_CLEAR_VALUE             0x0B73
		#define GL_DEPTH_COMPONENT               0x1902
		#define GL_DEPTH_FUNC                    0x0B74
		#define GL_DEPTH_RANGE                   0x0B70
		#define GL_DEPTH_SCALE                   0x0D1E
		#define GL_DEPTH_TEST                    0x0B71
		#define GL_DEPTH_WRITEMASK               0x0B72
		#define GL_DIFFUSE                       0x1201
		#define GL_DITHER                        0x0BD0
		#define GL_DOMAIN                        0x0A02
		#define GL_DONT_CARE                     0x1100
		#define GL_DOUBLE                        0x140A
		#define GL_DOUBLEBUFFER                  0x0C32
		#define GL_DRAW_BUFFER                   0x0C01
		#define GL_DRAW_PIXEL_TOKEN              0x0705
		#define GL_DST_ALPHA                     0x0304
		#define GL_DST_COLOR                     0x0306
		#define GL_EDGE_FLAG                     0x0B43
		#define GL_EDGE_FLAG_ARRAY               0x8079
		#define GL_EDGE_FLAG_ARRAY_POINTER       0x8093
		#define GL_EDGE_FLAG_ARRAY_STRIDE        0x808C
		#define GL_EMISSION                      0x1600
		#define GL_ENABLE_BIT                    0x00002000
		#define GL_EQUAL                         0x0202
		#define GL_EQUIV                         0x1509
		#define GL_EVAL_BIT                      0x00010000
		#define GL_EXP                           0x0800
		#define GL_EXP2                          0x0801
		#define GL_EXTENSIONS                    0x1F03
		#define GL_EYE_LINEAR                    0x2400
		#define GL_EYE_PLANE                     0x2502
		#define GL_FALSE                         0
		#define GL_FASTEST                       0x1101
		#define GL_FEEDBACK                      0x1C01
		#define GL_FEEDBACK_BUFFER_POINTER       0x0DF0
		#define GL_FEEDBACK_BUFFER_SIZE          0x0DF1
		#define GL_FEEDBACK_BUFFER_TYPE          0x0DF2
		#define GL_FILL                          0x1B02
		#define GL_FLAT                          0x1D00
		#define GL_FLOAT                         0x1406
		#define GL_FOG                           0x0B60
		#define GL_FOG_BIT                       0x00000080
		#define GL_FOG_COLOR                     0x0B66
		#define GL_FOG_DENSITY                   0x0B62
		#define GL_FOG_END                       0x0B64
		#define GL_FOG_HINT                      0x0C54
		#define GL_FOG_INDEX                     0x0B61
		#define GL_FOG_MODE                      0x0B65
		#define GL_FOG_START                     0x0B63
		#define GL_FRONT                         0x0404
		#define GL_FRONT_AND_BACK                0x0408
		#define GL_FRONT_FACE                    0x0B46
		#define GL_FRONT_LEFT                    0x0400
		#define GL_FRONT_RIGHT                   0x0401
		#define GL_GEQUAL                        0x0206
		#define GL_GREATER                       0x0204
		#define GL_GREEN                         0x1904
		#define GL_GREEN_BIAS                    0x0D19
		#define GL_GREEN_BITS                    0x0D53
		#define GL_GREEN_SCALE                   0x0D18
		#define GL_HINT_BIT                      0x00008000
		#define GL_INCR                          0x1E02
		#define GL_INDEX_ARRAY                   0x8077
		#define GL_INDEX_ARRAY_POINTER           0x8091
		#define GL_INDEX_ARRAY_STRIDE            0x8086
		#define GL_INDEX_ARRAY_TYPE              0x8085
		#define GL_INDEX_BITS                    0x0D51
		#define GL_INDEX_CLEAR_VALUE             0x0C20
		#define GL_INDEX_LOGIC_OP                0x0BF1
		#define GL_INDEX_MODE                    0x0C30
		#define GL_INDEX_OFFSET                  0x0D13
		#define GL_INDEX_SHIFT                   0x0D12
		#define GL_INDEX_WRITEMASK               0x0C21
		#define GL_INT                           0x1404
		#define GL_INTENSITY                     0x8049
		#define GL_INTENSITY12                   0x804C
		#define GL_INTENSITY16                   0x804D
		#define GL_INTENSITY4                    0x804A
		#define GL_INTENSITY8                    0x804B
		#define GL_INVALID_ENUM                  0x0500
		#define GL_INVALID_OPERATION             0x0502
		#define GL_INVALID_VALUE                 0x0501
		#define GL_INVERT                        0x150A
		#define GL_KEEP                          0x1E00
		#define GL_LEFT                          0x0406
		#define GL_LEQUAL                        0x0203
		#define GL_LESS                          0x0201
		#define GL_LIGHT0                        0x4000
		#define GL_LIGHT1                        0x4001
		#define GL_LIGHT2                        0x4002
		#define GL_LIGHT3                        0x4003
		#define GL_LIGHT4                        0x4004
		#define GL_LIGHT5                        0x4005
		#define GL_LIGHT6                        0x4006
		#define GL_LIGHT7                        0x4007
		#define GL_LIGHTING                      0x0B50
		#define GL_LIGHTING_BIT                  0x00000040
		#define GL_LIGHT_MODEL_AMBIENT           0x0B53
		#define GL_LIGHT_MODEL_LOCAL_VIEWER      0x0B51
		#define GL_LIGHT_MODEL_TWO_SIDE          0x0B52
		#define GL_LINE                          0x1B01
		#define GL_LINEAR                        0x2601
		#define GL_LINEAR_ATTENUATION            0x1208
		#define GL_LINEAR_MIPMAP_LINEAR          0x2703
		#define GL_LINEAR_MIPMAP_NEAREST         0x2701
		#define GL_LINES                         0x0001
		#define GL_LINE_BIT                      0x00000004
		#define GL_LINE_LOOP                     0x0002
		#define GL_LINE_RESET_TOKEN              0x0707
		#define GL_LINE_SMOOTH                   0x0B20
		#define GL_LINE_SMOOTH_HINT              0x0C52
		#define GL_LINE_STIPPLE                  0x0B24
		#define GL_LINE_STIPPLE_PATTERN          0x0B25
		#define GL_LINE_STIPPLE_REPEAT           0x0B26
		#define GL_LINE_STRIP                    0x0003
		#define GL_LINE_TOKEN                    0x0702
		#define GL_LINE_WIDTH                    0x0B21
		#define GL_LINE_WIDTH_GRANULARITY        0x0B23
		#define GL_LINE_WIDTH_RANGE              0x0B22
		#define GL_LIST_BASE                     0x0B32
		#define GL_LIST_BIT                      0x00020000
		#define GL_LIST_INDEX                    0x0B33
		#define GL_LIST_MODE                     0x0B30
		#define GL_LOAD                          0x0101
		#define GL_LOGIC_OP                      0x0BF1
		#define GL_LOGIC_OP_MODE                 0x0BF0
		#define GL_LUMINANCE                     0x1909
		#define GL_LUMINANCE12                   0x8041
		#define GL_LUMINANCE12_ALPHA12           0x8047
		#define GL_LUMINANCE12_ALPHA4            0x8046
		#define GL_LUMINANCE16                   0x8042
		#define GL_LUMINANCE16_ALPHA16           0x8048
		#define GL_LUMINANCE4                    0x803F
		#define GL_LUMINANCE4_ALPHA4             0x8043
		#define GL_LUMINANCE6_ALPHA2             0x8044
		#define GL_LUMINANCE8                    0x8040
		#define GL_LUMINANCE8_ALPHA8             0x8045
		#define GL_LUMINANCE_ALPHA               0x190A
		#define GL_MAP1_COLOR_4                  0x0D90
		#define GL_MAP1_GRID_DOMAIN              0x0DD0
		#define GL_MAP1_GRID_SEGMENTS            0x0DD1
		#define GL_MAP1_INDEX                    0x0D91
		#define GL_MAP1_NORMAL                   0x0D92
		#define GL_MAP1_TEXTURE_COORD_1          0x0D93
		#define GL_MAP1_TEXTURE_COORD_2          0x0D94
		#define GL_MAP1_TEXTURE_COORD_3          0x0D95
		#define GL_MAP1_TEXTURE_COORD_4          0x0D96
		#define GL_MAP1_VERTEX_3                 0x0D97
		#define GL_MAP1_VERTEX_4                 0x0D98
		#define GL_MAP2_COLOR_4                  0x0DB0
		#define GL_MAP2_GRID_DOMAIN              0x0DD2
		#define GL_MAP2_GRID_SEGMENTS            0x0DD3
		#define GL_MAP2_INDEX                    0x0DB1
		#define GL_MAP2_NORMAL                   0x0DB2
		#define GL_MAP2_TEXTURE_COORD_1          0x0DB3
		#define GL_MAP2_TEXTURE_COORD_2          0x0DB4
		#define GL_MAP2_TEXTURE_COORD_3          0x0DB5
		#define GL_MAP2_TEXTURE_COORD_4          0x0DB6
		#define GL_MAP2_VERTEX_3                 0x0DB7
		#define GL_MAP2_VERTEX_4                 0x0DB8
		#define GL_MAP_COLOR                     0x0D10
		#define GL_MAP_STENCIL                   0x0D11
		#define GL_MATRIX_MODE                   0x0BA0
		#define GL_MAX_ATTRIB_STACK_DEPTH        0x0D35
		#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
		#define GL_MAX_CLIP_PLANES               0x0D32
		#define GL_MAX_EVAL_ORDER                0x0D30
		#define GL_MAX_LIGHTS                    0x0D31
		#define GL_MAX_LIST_NESTING              0x0B31
		#define GL_MAX_MODELVIEW_STACK_DEPTH     0x0D36
		#define GL_MAX_NAME_STACK_DEPTH          0x0D37
		#define GL_MAX_PIXEL_MAP_TABLE           0x0D34
		#define GL_MAX_PROJECTION_STACK_DEPTH    0x0D38
		#define GL_MAX_TEXTURE_SIZE              0x0D33
		#define GL_MAX_TEXTURE_STACK_DEPTH       0x0D39
		#define GL_MAX_VIEWPORT_DIMS             0x0D3A
		#define GL_MODELVIEW                     0x1700
		#define GL_MODELVIEW_MATRIX              0x0BA6
		#define GL_MODELVIEW_STACK_DEPTH         0x0BA3
		#define GL_MODULATE                      0x2100
		#define GL_MULT                          0x0103
		#define GL_N3F_V3F                       0x2A25
		#define GL_NAME_STACK_DEPTH              0x0D70
		#define GL_NAND                          0x150E
		#define GL_NEAREST                       0x2600
		#define GL_NEAREST_MIPMAP_LINEAR         0x2702
		#define GL_NEAREST_MIPMAP_NEAREST        0x2700
		#define GL_NEVER                         0x0200
		#define GL_NICEST                        0x1102
		#define GL_NONE                          0
		#define GL_NOOP                          0x1505
		#define GL_NOR                           0x1508
		#define GL_NORMALIZE                     0x0BA1
		#define GL_NORMAL_ARRAY                  0x8075
		#define GL_NORMAL_ARRAY_POINTER          0x808F
		#define GL_NORMAL_ARRAY_STRIDE           0x807F
		#define GL_NORMAL_ARRAY_TYPE             0x807E
		#define GL_NOTEQUAL                      0x0205
		#define GL_NO_ERROR                      0
		#define GL_OBJECT_LINEAR                 0x2401
		#define GL_OBJECT_PLANE                  0x2501
		#define GL_ONE                           1
		#define GL_ONE_MINUS_DST_ALPHA           0x0305
		#define GL_ONE_MINUS_DST_COLOR           0x0307
		#define GL_ONE_MINUS_SRC_ALPHA           0x0303
		#define GL_ONE_MINUS_SRC_COLOR           0x0301
		#define GL_OR                            0x1507
		#define GL_ORDER                         0x0A01
		#define GL_OR_INVERTED                   0x150D
		#define GL_OR_REVERSE                    0x150B
		#define GL_OUT_OF_MEMORY                 0x0505
		#define GL_PACK_ALIGNMENT                0x0D05
		#define GL_PACK_LSB_FIRST                0x0D01
		#define GL_PACK_ROW_LENGTH               0x0D02
		#define GL_PACK_SKIP_PIXELS              0x0D04
		#define GL_PACK_SKIP_ROWS                0x0D03
		#define GL_PACK_SWAP_BYTES               0x0D00
		#define GL_PASS_THROUGH_TOKEN            0x0700
		#define GL_PERSPECTIVE_CORRECTION_HINT   0x0C50
		#define GL_PIXEL_MAP_A_TO_A              0x0C79
		#define GL_PIXEL_MAP_A_TO_A_SIZE         0x0CB9
		#define GL_PIXEL_MAP_B_TO_B              0x0C78
		#define GL_PIXEL_MAP_B_TO_B_SIZE         0x0CB8
		#define GL_PIXEL_MAP_G_TO_G              0x0C77
		#define GL_PIXEL_MAP_G_TO_G_SIZE         0x0CB7
		#define GL_PIXEL_MAP_I_TO_A              0x0C75
		#define GL_PIXEL_MAP_I_TO_A_SIZE         0x0CB5
		#define GL_PIXEL_MAP_I_TO_B              0x0C74
		#define GL_PIXEL_MAP_I_TO_B_SIZE         0x0CB4
		#define GL_PIXEL_MAP_I_TO_G              0x0C73
		#define GL_PIXEL_MAP_I_TO_G_SIZE         0x0CB3
		#define GL_PIXEL_MAP_I_TO_I              0x0C70
		#define GL_PIXEL_MAP_I_TO_I_SIZE         0x0CB0
		#define GL_PIXEL_MAP_I_TO_R              0x0C72
		#define GL_PIXEL_MAP_I_TO_R_SIZE         0x0CB2
		#define GL_PIXEL_MAP_R_TO_R              0x0C76
		#define GL_PIXEL_MAP_R_TO_R_SIZE         0x0CB6
		#define GL_PIXEL_MAP_S_TO_S              0x0C71
		#define GL_PIXEL_MAP_S_TO_S_SIZE         0x0CB1
		#define GL_PIXEL_MODE_BIT                0x00000020
		#define GL_POINT                         0x1B00
		#define GL_POINTS                        0x0000
		#define GL_POINT_BIT                     0x00000002
		#define GL_POINT_SIZE                    0x0B11
		#define GL_POINT_SIZE_GRANULARITY        0x0B13
		#define GL_POINT_SIZE_RANGE              0x0B12
		#define GL_POINT_SMOOTH                  0x0B10
		#define GL_POINT_SMOOTH_HINT             0x0C51
		#define GL_POINT_TOKEN                   0x0701
		#define GL_POLYGON                       0x0009
		#define GL_POLYGON_BIT                   0x00000008
		#define GL_POLYGON_MODE                  0x0B40
		#define GL_POLYGON_OFFSET_FACTOR         0x8038
		#define GL_POLYGON_OFFSET_FILL           0x8037
		#define GL_POLYGON_OFFSET_LINE           0x2A02
		#define GL_POLYGON_OFFSET_POINT          0x2A01
		#define GL_POLYGON_OFFSET_UNITS          0x2A00
		#define GL_POLYGON_SMOOTH                0x0B41
		#define GL_POLYGON_SMOOTH_HINT           0x0C53
		#define GL_POLYGON_STIPPLE               0x0B42
		#define GL_POLYGON_STIPPLE_BIT           0x00000010
		#define GL_POLYGON_TOKEN                 0x0703
		#define GL_POSITION                      0x1203
		#define GL_PROJECTION                    0x1701
		#define GL_PROJECTION_MATRIX             0x0BA7
		#define GL_PROJECTION_STACK_DEPTH        0x0BA4
		#define GL_PROXY_TEXTURE_1D              0x8063
		#define GL_PROXY_TEXTURE_2D              0x8064
		#define GL_Q                             0x2003
		#define GL_QUADRATIC_ATTENUATION         0x1209
		#define GL_QUADS                         0x0007
		#define GL_QUAD_STRIP                    0x0008
		#define GL_R                             0x2002
		#define GL_R3_G3_B2                      0x2A10
		#define GL_READ_BUFFER                   0x0C02
		#define GL_RED                           0x1903
		#define GL_RED_BIAS                      0x0D15
		#define GL_RED_BITS                      0x0D52
		#define GL_RED_SCALE                     0x0D14
		#define GL_RENDER                        0x1C00
		#define GL_RENDERER                      0x1F01
		#define GL_RENDER_MODE                   0x0C40
		#define GL_REPEAT                        0x2901
		#define GL_REPLACE                       0x1E01
		#define GL_RETURN                        0x0102
		#define GL_RGB                           0x1907
		#define GL_RGB10                         0x8052
		#define GL_RGB10_A2                      0x8059
		#define GL_RGB12                         0x8053
		#define GL_RGB16                         0x8054
		#define GL_RGB4                          0x804F
		#define GL_RGB5                          0x8050
		#define GL_RGB5_A1                       0x8057
		#define GL_RGB8                          0x8051
		#define GL_RGBA                          0x1908
		#define GL_RGBA12                        0x805A
		#define GL_RGBA16                        0x805B
		#define GL_RGBA2                         0x8055
		#define GL_RGBA4                         0x8056
		#define GL_RGBA8                         0x8058
		#define GL_RGBA_MODE                     0x0C31
		#define GL_RIGHT                         0x0407
		#define GL_S                             0x2000
		#define GL_SCISSOR_BIT                   0x00080000
		#define GL_SCISSOR_BOX                   0x0C10
		#define GL_SCISSOR_TEST                  0x0C11
		#define GL_SELECT                        0x1C02
		#define GL_SELECTION_BUFFER_POINTER      0x0DF3
		#define GL_SELECTION_BUFFER_SIZE         0x0DF4
		#define GL_SET                           0x150F
		#define GL_SHADE_MODEL                   0x0B54
		#define GL_SHININESS                     0x1601
		#define GL_SHORT                         0x1402
		#define GL_SMOOTH                        0x1D01
		#define GL_SPECULAR                      0x1202
		#define GL_SPHERE_MAP                    0x2402
		#define GL_SPOT_CUTOFF                   0x1206
		#define GL_SPOT_DIRECTION                0x1204
		#define GL_SPOT_EXPONENT                 0x1205
		#define GL_SRC_ALPHA                     0x0302
		#define GL_SRC_ALPHA_SATURATE            0x0308
		#define GL_SRC_COLOR                     0x0300
		#define GL_STACK_OVERFLOW                0x0503
		#define GL_STACK_UNDERFLOW               0x0504
		#define GL_STENCIL                       0x1802
		#define GL_STENCIL_BITS                  0x0D57
		#define GL_STENCIL_BUFFER_BIT            0x00000400
		#define GL_STENCIL_CLEAR_VALUE           0x0B91
		#define GL_STENCIL_FAIL                  0x0B94
		#define GL_STENCIL_FUNC                  0x0B92
		#define GL_STENCIL_INDEX                 0x1901
		#define GL_STENCIL_PASS_DEPTH_FAIL       0x0B95
		#define GL_STENCIL_PASS_DEPTH_PASS       0x0B96
		#define GL_STENCIL_REF                   0x0B97
		#define GL_STENCIL_TEST                  0x0B90
		#define GL_STENCIL_VALUE_MASK            0x0B93
		#define GL_STENCIL_WRITEMASK             0x0B98
		#define GL_STEREO                        0x0C33
		#define GL_SUBPIXEL_BITS                 0x0D50
		#define GL_T                             0x2001
		#define GL_T2F_C3F_V3F                   0x2A2A
		#define GL_T2F_C4F_N3F_V3F               0x2A2C
		#define GL_T2F_C4UB_V3F                  0x2A29
		#define GL_T2F_N3F_V3F                   0x2A2B
		#define GL_T2F_V3F                       0x2A27
		#define GL_T4F_C4F_N3F_V4F               0x2A2D
		#define GL_T4F_V4F                       0x2A28
		#define GL_TEXTURE                       0x1702
		#define GL_TEXTURE_1D                    0x0DE0
		#define GL_TEXTURE_2D                    0x0DE1
		#define GL_TEXTURE_ALPHA_SIZE            0x805F
		#define GL_TEXTURE_BINDING_1D            0x8068
		#define GL_TEXTURE_BINDING_2D            0x8069
		#define GL_TEXTURE_BIT                   0x00040000
		#define GL_TEXTURE_BLUE_SIZE             0x805E
		#define GL_TEXTURE_BORDER                0x1005
		#define GL_TEXTURE_BORDER_COLOR          0x1004
		#define GL_TEXTURE_COMPONENTS            0x1003
		#define GL_TEXTURE_COORD_ARRAY           0x8078
		#define GL_TEXTURE_COORD_ARRAY_POINTER   0x8092
		#define GL_TEXTURE_COORD_ARRAY_SIZE      0x8088
		#define GL_TEXTURE_COORD_ARRAY_STRIDE    0x808A
		#define GL_TEXTURE_COORD_ARRAY_TYPE      0x8089
		#define GL_TEXTURE_ENV                   0x2300
		#define GL_TEXTURE_ENV_COLOR             0x2201
		#define GL_TEXTURE_ENV_MODE              0x2200
		#define GL_TEXTURE_GEN_MODE              0x2500
		#define GL_TEXTURE_GEN_Q                 0x0C63
		#define GL_TEXTURE_GEN_R                 0x0C62
		#define GL_TEXTURE_GEN_S                 0x0C60
		#define GL_TEXTURE_GEN_T                 0x0C61
		#define GL_TEXTURE_GREEN_SIZE            0x805D
		#define GL_TEXTURE_HEIGHT                0x1001
		#define GL_TEXTURE_INTENSITY_SIZE        0x8061
		#define GL_TEXTURE_INTERNAL_FORMAT       0x1003
		#define GL_TEXTURE_LUMINANCE_SIZE        0x8060
		#define GL_TEXTURE_MAG_FILTER            0x2800
		#define GL_TEXTURE_MATRIX                0x0BA8
		#define GL_TEXTURE_MIN_FILTER            0x2801
		#define GL_TEXTURE_PRIORITY              0x8066
		#define GL_TEXTURE_RED_SIZE              0x805C
		#define GL_TEXTURE_RESIDENT              0x8067
		#define GL_TEXTURE_STACK_DEPTH           0x0BA5
		#define GL_TEXTURE_WIDTH                 0x1000
		#define GL_TEXTURE_WRAP_S                0x2802
		#define GL_TEXTURE_WRAP_T                0x2803
		#define GL_TRANSFORM_BIT                 0x00001000
		#define GL_TRIANGLES                     0x0004
		#define GL_TRIANGLE_FAN                  0x0006
		#define GL_TRIANGLE_STRIP                0x0005
		#define GL_TRUE                          1
		#define GL_UNPACK_ALIGNMENT              0x0CF5
		#define GL_UNPACK_LSB_FIRST              0x0CF1
		#define GL_UNPACK_ROW_LENGTH             0x0CF2
		#define GL_UNPACK_SKIP_PIXELS            0x0CF4
		#define GL_UNPACK_SKIP_ROWS              0x0CF3
		#define GL_UNPACK_SWAP_BYTES             0x0CF0
		#define GL_UNSIGNED_BYTE                 0x1401
		#define GL_UNSIGNED_INT                  0x1405
		#define GL_UNSIGNED_SHORT                0x1403
		#define GL_V2F                           0x2A20
		#define GL_V3F                           0x2A21
		#define GL_VENDOR                        0x1F00
		#define GL_VERSION                       0x1F02
		#define GL_VERTEX_ARRAY                  0x8074
		#define GL_VERTEX_ARRAY_POINTER          0x808E
		#define GL_VERTEX_ARRAY_SIZE             0x807A
		#define GL_VERTEX_ARRAY_STRIDE           0x807C
		#define GL_VERTEX_ARRAY_TYPE             0x807B
		#define GL_VIEWPORT                      0x0BA2
		#define GL_VIEWPORT_BIT                  0x00000800
		#define GL_XOR                           0x1506
		#define GL_ZERO                          0
		#define GL_ZOOM_X                        0x0D16
		#define GL_ZOOM_Y                        0x0D17
		
		// Version: 1.2
		#define GL_ALIASED_LINE_WIDTH_RANGE      0x846E
		#define GL_ALIASED_POINT_SIZE_RANGE      0x846D
		#define GL_BGR                           0x80E0
		#define GL_BGRA                          0x80E1
		#define GL_CLAMP_TO_EDGE                 0x812F
		#define GL_LIGHT_MODEL_COLOR_CONTROL     0x81F8
		#define GL_MAX_3D_TEXTURE_SIZE           0x8073
		#define GL_MAX_ELEMENTS_INDICES          0x80E9
		#define GL_MAX_ELEMENTS_VERTICES         0x80E8
		#define GL_PACK_IMAGE_HEIGHT             0x806C
		#define GL_PACK_SKIP_IMAGES              0x806B
		#define GL_PROXY_TEXTURE_3D              0x8070
		#define GL_RESCALE_NORMAL                0x803A
		#define GL_SEPARATE_SPECULAR_COLOR       0x81FA
		#define GL_SINGLE_COLOR                  0x81F9
		#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
		#define GL_SMOOTH_LINE_WIDTH_RANGE       0x0B22
		#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
		#define GL_SMOOTH_POINT_SIZE_RANGE       0x0B12
		#define GL_TEXTURE_3D                    0x806F
		#define GL_TEXTURE_BASE_LEVEL            0x813C
		#define GL_TEXTURE_BINDING_3D            0x806A
		#define GL_TEXTURE_DEPTH                 0x8071
		#define GL_TEXTURE_MAX_LEVEL             0x813D
		#define GL_TEXTURE_MAX_LOD               0x813B
		#define GL_TEXTURE_MIN_LOD               0x813A
		#define GL_TEXTURE_WRAP_R                0x8072
		#define GL_UNPACK_IMAGE_HEIGHT           0x806E
		#define GL_UNPACK_SKIP_IMAGES            0x806D
		#define GL_UNSIGNED_BYTE_2_3_3_REV       0x8362
		#define GL_UNSIGNED_BYTE_3_3_2           0x8032
		#define GL_UNSIGNED_INT_10_10_10_2       0x8036
		#define GL_UNSIGNED_INT_2_10_10_10_REV   0x8368
		#define GL_UNSIGNED_INT_8_8_8_8          0x8035
		#define GL_UNSIGNED_INT_8_8_8_8_REV      0x8367
		#define GL_UNSIGNED_SHORT_1_5_5_5_REV    0x8366
		#define GL_UNSIGNED_SHORT_4_4_4_4        0x8033
		#define GL_UNSIGNED_SHORT_4_4_4_4_REV    0x8365
		#define GL_UNSIGNED_SHORT_5_5_5_1        0x8034
		#define GL_UNSIGNED_SHORT_5_6_5          0x8363
		#define GL_UNSIGNED_SHORT_5_6_5_REV      0x8364
		
		// Version: 1.3
		#define GL_ACTIVE_TEXTURE                0x84E0
		#define GL_ADD_SIGNED                    0x8574
		#define GL_CLAMP_TO_BORDER               0x812D
		#define GL_CLIENT_ACTIVE_TEXTURE         0x84E1
		#define GL_COMBINE                       0x8570
		#define GL_COMBINE_ALPHA                 0x8572
		#define GL_COMBINE_RGB                   0x8571
		#define GL_COMPRESSED_ALPHA              0x84E9
		#define GL_COMPRESSED_INTENSITY          0x84EC
		#define GL_COMPRESSED_LUMINANCE          0x84EA
		#define GL_COMPRESSED_LUMINANCE_ALPHA    0x84EB
		#define GL_COMPRESSED_RGB                0x84ED
		#define GL_COMPRESSED_RGBA               0x84EE
		#define GL_COMPRESSED_TEXTURE_FORMATS    0x86A3
		#define GL_CONSTANT                      0x8576
		#define GL_DOT3_RGB                      0x86AE
		#define GL_DOT3_RGBA                     0x86AF
		#define GL_INTERPOLATE                   0x8575
		#define GL_MAX_CUBE_MAP_TEXTURE_SIZE     0x851C
		#define GL_MAX_TEXTURE_UNITS             0x84E2
		#define GL_MULTISAMPLE                   0x809D
		#define GL_MULTISAMPLE_BIT               0x20000000
		#define GL_NORMAL_MAP                    0x8511
		#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
		#define GL_OPERAND0_ALPHA                0x8598
		#define GL_OPERAND0_RGB                  0x8590
		#define GL_OPERAND1_ALPHA                0x8599
		#define GL_OPERAND1_RGB                  0x8591
		#define GL_OPERAND2_ALPHA                0x859A
		#define GL_OPERAND2_RGB                  0x8592
		#define GL_PREVIOUS                      0x8578
		#define GL_PRIMARY_COLOR                 0x8577
		#define GL_PROXY_TEXTURE_CUBE_MAP        0x851B
		#define GL_REFLECTION_MAP                0x8512
		#define GL_RGB_SCALE                     0x8573
		#define GL_SAMPLES                       0x80A9
		#define GL_SAMPLE_ALPHA_TO_COVERAGE      0x809E
		#define GL_SAMPLE_ALPHA_TO_ONE           0x809F
		#define GL_SAMPLE_BUFFERS                0x80A8
		#define GL_SAMPLE_COVERAGE               0x80A0
		#define GL_SAMPLE_COVERAGE_INVERT        0x80AB
		#define GL_SAMPLE_COVERAGE_VALUE         0x80AA
		#define GL_SOURCE0_ALPHA                 0x8588
		#define GL_SOURCE0_RGB                   0x8580
		#define GL_SOURCE1_ALPHA                 0x8589
		#define GL_SOURCE1_RGB                   0x8581
		#define GL_SOURCE2_ALPHA                 0x858A
		#define GL_SOURCE2_RGB                   0x8582
		#define GL_SUBTRACT                      0x84E7
		#define GL_TEXTURE0                      0x84C0
		#define GL_TEXTURE1                      0x84C1
		#define GL_TEXTURE10                     0x84CA
		#define GL_TEXTURE11                     0x84CB
		#define GL_TEXTURE12                     0x84CC
		#define GL_TEXTURE13                     0x84CD
		#define GL_TEXTURE14                     0x84CE
		#define GL_TEXTURE15                     0x84CF
		#define GL_TEXTURE16                     0x84D0
		#define GL_TEXTURE17                     0x84D1
		#define GL_TEXTURE18                     0x84D2
		#define GL_TEXTURE19                     0x84D3
		#define GL_TEXTURE2                      0x84C2
		#define GL_TEXTURE20                     0x84D4
		#define GL_TEXTURE21                     0x84D5
		#define GL_TEXTURE22                     0x84D6
		#define GL_TEXTURE23                     0x84D7
		#define GL_TEXTURE24                     0x84D8
		#define GL_TEXTURE25                     0x84D9
		#define GL_TEXTURE26                     0x84DA
		#define GL_TEXTURE27                     0x84DB
		#define GL_TEXTURE28                     0x84DC
		#define GL_TEXTURE29                     0x84DD
		#define GL_TEXTURE3                      0x84C3
		#define GL_TEXTURE30                     0x84DE
		#define GL_TEXTURE31                     0x84DF
		#define GL_TEXTURE4                      0x84C4
		#define GL_TEXTURE5                      0x84C5
		#define GL_TEXTURE6                      0x84C6
		#define GL_TEXTURE7                      0x84C7
		#define GL_TEXTURE8                      0x84C8
		#define GL_TEXTURE9                      0x84C9
		#define GL_TEXTURE_BINDING_CUBE_MAP      0x8514
		#define GL_TEXTURE_COMPRESSED            0x86A1
		#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
		#define GL_TEXTURE_COMPRESSION_HINT      0x84EF
		#define GL_TEXTURE_CUBE_MAP              0x8513
		#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X   0x8516
		#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y   0x8518
		#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z   0x851A
		#define GL_TEXTURE_CUBE_MAP_POSITIVE_X   0x8515
		#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y   0x8517
		#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z   0x8519
		#define GL_TRANSPOSE_COLOR_MATRIX        0x84E6
		#define GL_TRANSPOSE_MODELVIEW_MATRIX    0x84E3
		#define GL_TRANSPOSE_PROJECTION_MATRIX   0x84E4
		#define GL_TRANSPOSE_TEXTURE_MATRIX      0x84E5
		
		// Version: 1.4
		#define GL_BLEND_COLOR                   0x8005
		#define GL_BLEND_DST_ALPHA               0x80CA
		#define GL_BLEND_DST_RGB                 0x80C8
		#define GL_BLEND_EQUATION                0x8009
		#define GL_BLEND_SRC_ALPHA               0x80CB
		#define GL_BLEND_SRC_RGB                 0x80C9
		#define GL_COLOR_SUM                     0x8458
		#define GL_COMPARE_R_TO_TEXTURE          0x884E
		#define GL_CONSTANT_ALPHA                0x8003
		#define GL_CONSTANT_COLOR                0x8001
		#define GL_CURRENT_FOG_COORDINATE        0x8453
		#define GL_CURRENT_SECONDARY_COLOR       0x8459
		#define GL_DECR_WRAP                     0x8508
		#define GL_DEPTH_COMPONENT16             0x81A5
		#define GL_DEPTH_COMPONENT24             0x81A6
		#define GL_DEPTH_COMPONENT32             0x81A7
		#define GL_DEPTH_TEXTURE_MODE            0x884B
		#define GL_FOG_COORDINATE                0x8451
		#define GL_FOG_COORDINATE_ARRAY          0x8457
		#define GL_FOG_COORDINATE_ARRAY_POINTER  0x8456
		#define GL_FOG_COORDINATE_ARRAY_STRIDE   0x8455
		#define GL_FOG_COORDINATE_ARRAY_TYPE     0x8454
		#define GL_FOG_COORDINATE_SOURCE         0x8450
		#define GL_FRAGMENT_DEPTH                0x8452
		#define GL_FUNC_ADD                      0x8006
		#define GL_FUNC_REVERSE_SUBTRACT         0x800B
		#define GL_FUNC_SUBTRACT                 0x800A
		#define GL_GENERATE_MIPMAP               0x8191
		#define GL_GENERATE_MIPMAP_HINT          0x8192
		#define GL_INCR_WRAP                     0x8507
		#define GL_MAX                           0x8008
		#define GL_MAX_TEXTURE_LOD_BIAS          0x84FD
		#define GL_MIN                           0x8007
		#define GL_MIRRORED_REPEAT               0x8370
		#define GL_ONE_MINUS_CONSTANT_ALPHA      0x8004
		#define GL_ONE_MINUS_CONSTANT_COLOR      0x8002
		#define GL_POINT_DISTANCE_ATTENUATION    0x8129
		#define GL_POINT_FADE_THRESHOLD_SIZE     0x8128
		#define GL_POINT_SIZE_MAX                0x8127
		#define GL_POINT_SIZE_MIN                0x8126
		#define GL_SECONDARY_COLOR_ARRAY         0x845E
		#define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
		#define GL_SECONDARY_COLOR_ARRAY_SIZE    0x845A
		#define GL_SECONDARY_COLOR_ARRAY_STRIDE  0x845C
		#define GL_SECONDARY_COLOR_ARRAY_TYPE    0x845B
		#define GL_TEXTURE_COMPARE_FUNC          0x884D
		#define GL_TEXTURE_COMPARE_MODE          0x884C
		#define GL_TEXTURE_DEPTH_SIZE            0x884A
		#define GL_TEXTURE_FILTER_CONTROL        0x8500
		#define GL_TEXTURE_LOD_BIAS              0x8501
		
		// Version: 1.5
		#define GL_ARRAY_BUFFER                  0x8892
		#define GL_ARRAY_BUFFER_BINDING          0x8894
		#define GL_BUFFER_ACCESS                 0x88BB
		#define GL_BUFFER_MAPPED                 0x88BC
		#define GL_BUFFER_MAP_POINTER            0x88BD
		#define GL_BUFFER_SIZE                   0x8764
		#define GL_BUFFER_USAGE                  0x8765
		#define GL_COLOR_ARRAY_BUFFER_BINDING    0x8898
		#define GL_CURRENT_FOG_COORD             0x8453
		#define GL_CURRENT_QUERY                 0x8865
		#define GL_DYNAMIC_COPY                  0x88EA
		#define GL_DYNAMIC_DRAW                  0x88E8
		#define GL_DYNAMIC_READ                  0x88E9
		#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
		#define GL_ELEMENT_ARRAY_BUFFER          0x8893
		#define GL_ELEMENT_ARRAY_BUFFER_BINDING  0x8895
		#define GL_FOG_COORD                     0x8451
		#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
		#define GL_FOG_COORD_ARRAY               0x8457
		#define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
		#define GL_FOG_COORD_ARRAY_POINTER       0x8456
		#define GL_FOG_COORD_ARRAY_STRIDE        0x8455
		#define GL_FOG_COORD_ARRAY_TYPE          0x8454
		#define GL_FOG_COORD_SRC                 0x8450
		#define GL_INDEX_ARRAY_BUFFER_BINDING    0x8899
		#define GL_NORMAL_ARRAY_BUFFER_BINDING   0x8897
		#define GL_QUERY_COUNTER_BITS            0x8864
		#define GL_QUERY_RESULT                  0x8866
		#define GL_QUERY_RESULT_AVAILABLE        0x8867
		#define GL_READ_ONLY                     0x88B8
		#define GL_READ_WRITE                    0x88BA
		#define GL_SAMPLES_PASSED                0x8914
		#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
		#define GL_SRC0_ALPHA                    0x8588
		#define GL_SRC0_RGB                      0x8580
		#define GL_SRC1_ALPHA                    0x8589
		#define GL_SRC1_RGB                      0x8581
		#define GL_SRC2_ALPHA                    0x858A
		#define GL_SRC2_RGB                      0x8582
		#define GL_STATIC_COPY                   0x88E6
		#define GL_STATIC_DRAW                   0x88E4
		#define GL_STATIC_READ                   0x88E5
		#define GL_STREAM_COPY                   0x88E2
		#define GL_STREAM_DRAW                   0x88E0
		#define GL_STREAM_READ                   0x88E1
		#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
		#define GL_VERTEX_ARRAY_BUFFER_BINDING   0x8896
		#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
		#define GL_WEIGHT_ARRAY_BUFFER_BINDING   0x889E
		#define GL_WRITE_ONLY                    0x88B9
		
		// Version: 2.0
		#define GL_ACTIVE_ATTRIBUTES             0x8B89
		#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH   0x8B8A
		#define GL_ACTIVE_UNIFORMS               0x8B86
		#define GL_ACTIVE_UNIFORM_MAX_LENGTH     0x8B87
		#define GL_ATTACHED_SHADERS              0x8B85
		#define GL_BLEND_EQUATION_ALPHA          0x883D
		#define GL_BLEND_EQUATION_RGB            0x8009
		#define GL_BOOL                          0x8B56
		#define GL_BOOL_VEC2                     0x8B57
		#define GL_BOOL_VEC3                     0x8B58
		#define GL_BOOL_VEC4                     0x8B59
		#define GL_COMPILE_STATUS                0x8B81
		#define GL_COORD_REPLACE                 0x8862
		#define GL_CURRENT_PROGRAM               0x8B8D
		#define GL_CURRENT_VERTEX_ATTRIB         0x8626
		#define GL_DELETE_STATUS                 0x8B80
		#define GL_DRAW_BUFFER0                  0x8825
		#define GL_DRAW_BUFFER1                  0x8826
		#define GL_DRAW_BUFFER10                 0x882F
		#define GL_DRAW_BUFFER11                 0x8830
		#define GL_DRAW_BUFFER12                 0x8831
		#define GL_DRAW_BUFFER13                 0x8832
		#define GL_DRAW_BUFFER14                 0x8833
		#define GL_DRAW_BUFFER15                 0x8834
		#define GL_DRAW_BUFFER2                  0x8827
		#define GL_DRAW_BUFFER3                  0x8828
		#define GL_DRAW_BUFFER4                  0x8829
		#define GL_DRAW_BUFFER5                  0x882A
		#define GL_DRAW_BUFFER6                  0x882B
		#define GL_DRAW_BUFFER7                  0x882C
		#define GL_DRAW_BUFFER8                  0x882D
		#define GL_DRAW_BUFFER9                  0x882E
		#define GL_FLOAT_MAT2                    0x8B5A
		#define GL_FLOAT_MAT3                    0x8B5B
		#define GL_FLOAT_MAT4                    0x8B5C
		#define GL_FLOAT_VEC2                    0x8B50
		#define GL_FLOAT_VEC3                    0x8B51
		#define GL_FLOAT_VEC4                    0x8B52
		#define GL_FRAGMENT_SHADER               0x8B30
		#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
		#define GL_INFO_LOG_LENGTH               0x8B84
		#define GL_INT_VEC2                      0x8B53
		#define GL_INT_VEC3                      0x8B54
		#define GL_INT_VEC4                      0x8B55
		#define GL_LINK_STATUS                   0x8B82
		#define GL_LOWER_LEFT                    0x8CA1
		#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
		#define GL_MAX_DRAW_BUFFERS              0x8824
		#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
		#define GL_MAX_TEXTURE_COORDS            0x8871
		#define GL_MAX_TEXTURE_IMAGE_UNITS       0x8872
		#define GL_MAX_VARYING_FLOATS            0x8B4B
		#define GL_MAX_VERTEX_ATTRIBS            0x8869
		#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
		#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
		#define GL_POINT_SPRITE                  0x8861
		#define GL_POINT_SPRITE_COORD_ORIGIN     0x8CA0
		#define GL_SAMPLER_1D                    0x8B5D
		#define GL_SAMPLER_1D_SHADOW             0x8B61
		#define GL_SAMPLER_2D                    0x8B5E
		#define GL_SAMPLER_2D_SHADOW             0x8B62
		#define GL_SAMPLER_3D                    0x8B5F
		#define GL_SAMPLER_CUBE                  0x8B60
		#define GL_SHADER_SOURCE_LENGTH          0x8B88
		#define GL_SHADER_TYPE                   0x8B4F
		#define GL_SHADING_LANGUAGE_VERSION      0x8B8C
		#define GL_STENCIL_BACK_FAIL             0x8801
		#define GL_STENCIL_BACK_FUNC             0x8800
		#define GL_STENCIL_BACK_PASS_DEPTH_FAIL  0x8802
		#define GL_STENCIL_BACK_PASS_DEPTH_PASS  0x8803
		#define GL_STENCIL_BACK_REF              0x8CA3
		#define GL_STENCIL_BACK_VALUE_MASK       0x8CA4
		#define GL_STENCIL_BACK_WRITEMASK        0x8CA5
		#define GL_UPPER_LEFT                    0x8CA2
		#define GL_VALIDATE_STATUS               0x8B83
		#define GL_VERTEX_ATTRIB_ARRAY_ENABLED   0x8622
		#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
		#define GL_VERTEX_ATTRIB_ARRAY_POINTER   0x8645
		#define GL_VERTEX_ATTRIB_ARRAY_SIZE      0x8623
		#define GL_VERTEX_ATTRIB_ARRAY_STRIDE    0x8624
		#define GL_VERTEX_ATTRIB_ARRAY_TYPE      0x8625
		#define GL_VERTEX_PROGRAM_POINT_SIZE     0x8642
		#define GL_VERTEX_PROGRAM_TWO_SIDE       0x8643
		#define GL_VERTEX_SHADER                 0x8B31
		
		// Version: 2.1
		#define GL_COMPRESSED_SLUMINANCE         0x8C4A
		#define GL_COMPRESSED_SLUMINANCE_ALPHA   0x8C4B
		#define GL_COMPRESSED_SRGB               0x8C48
		#define GL_COMPRESSED_SRGB_ALPHA         0x8C49
		#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
		#define GL_FLOAT_MAT2x3                  0x8B65
		#define GL_FLOAT_MAT2x4                  0x8B66
		#define GL_FLOAT_MAT3x2                  0x8B67
		#define GL_FLOAT_MAT3x4                  0x8B68
		#define GL_FLOAT_MAT4x2                  0x8B69
		#define GL_FLOAT_MAT4x3                  0x8B6A
		#define GL_PIXEL_PACK_BUFFER             0x88EB
		#define GL_PIXEL_PACK_BUFFER_BINDING     0x88ED
		#define GL_PIXEL_UNPACK_BUFFER           0x88EC
		#define GL_PIXEL_UNPACK_BUFFER_BINDING   0x88EF
		#define GL_SLUMINANCE                    0x8C46
		#define GL_SLUMINANCE8                   0x8C47
		#define GL_SLUMINANCE8_ALPHA8            0x8C45
		#define GL_SLUMINANCE_ALPHA              0x8C44
		#define GL_SRGB                          0x8C40
		#define GL_SRGB8                         0x8C41
		#define GL_SRGB8_ALPHA8                  0x8C43
		#define GL_SRGB_ALPHA                    0x8C42
		
		// Version: 3.0
		#define GL_ALPHA_INTEGER                 0x8D97
		#define GL_BGRA_INTEGER                  0x8D9B
		#define GL_BGR_INTEGER                   0x8D9A
		#define GL_BLUE_INTEGER                  0x8D96
		#define GL_BUFFER_ACCESS_FLAGS           0x911F
		#define GL_BUFFER_MAP_LENGTH             0x9120
		#define GL_BUFFER_MAP_OFFSET             0x9121
		#define GL_CLAMP_FRAGMENT_COLOR          0x891B
		#define GL_CLAMP_READ_COLOR              0x891C
		#define GL_CLAMP_VERTEX_COLOR            0x891A
		#define GL_CLIP_DISTANCE0                0x3000
		#define GL_CLIP_DISTANCE1                0x3001
		#define GL_CLIP_DISTANCE2                0x3002
		#define GL_CLIP_DISTANCE3                0x3003
		#define GL_CLIP_DISTANCE4                0x3004
		#define GL_CLIP_DISTANCE5                0x3005
		#define GL_CLIP_DISTANCE6                0x3006
		#define GL_CLIP_DISTANCE7                0x3007
		#define GL_COLOR_ATTACHMENT0             0x8CE0
		#define GL_COLOR_ATTACHMENT1             0x8CE1
		#define GL_COLOR_ATTACHMENT10            0x8CEA
		#define GL_COLOR_ATTACHMENT11            0x8CEB
		#define GL_COLOR_ATTACHMENT12            0x8CEC
		#define GL_COLOR_ATTACHMENT13            0x8CED
		#define GL_COLOR_ATTACHMENT14            0x8CEE
		#define GL_COLOR_ATTACHMENT15            0x8CEF
		#define GL_COLOR_ATTACHMENT2             0x8CE2
		#define GL_COLOR_ATTACHMENT3             0x8CE3
		#define GL_COLOR_ATTACHMENT4             0x8CE4
		#define GL_COLOR_ATTACHMENT5             0x8CE5
		#define GL_COLOR_ATTACHMENT6             0x8CE6
		#define GL_COLOR_ATTACHMENT7             0x8CE7
		#define GL_COLOR_ATTACHMENT8             0x8CE8
		#define GL_COLOR_ATTACHMENT9             0x8CE9
		#define GL_COMPARE_REF_TO_TEXTURE        0x884E
		#define GL_COMPRESSED_RED                0x8225
		#define GL_COMPRESSED_RED_RGTC1          0x8DBB
		#define GL_COMPRESSED_RG                 0x8226
		#define GL_COMPRESSED_RG_RGTC2           0x8DBD
		#define GL_COMPRESSED_SIGNED_RED_RGTC1   0x8DBC
		#define GL_COMPRESSED_SIGNED_RG_RGTC2    0x8DBE
		#define GL_CONTEXT_FLAGS                 0x821E
		#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
		#define GL_DEPTH24_STENCIL8              0x88F0
		#define GL_DEPTH32F_STENCIL8             0x8CAD
		#define GL_DEPTH_ATTACHMENT              0x8D00
		#define GL_DEPTH_COMPONENT32F            0x8CAC
		#define GL_DEPTH_STENCIL                 0x84F9
		#define GL_DEPTH_STENCIL_ATTACHMENT      0x821A
		#define GL_DRAW_FRAMEBUFFER              0x8CA9
		#define GL_DRAW_FRAMEBUFFER_BINDING      0x8CA6
		#define GL_FIXED_ONLY                    0x891D
		#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
		#define GL_FRAMEBUFFER                   0x8D40
		#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
		#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
		#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
		#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
		#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
		#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
		#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
		#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
		#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
		#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
		#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
		#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
		#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
		#define GL_FRAMEBUFFER_BINDING           0x8CA6
		#define GL_FRAMEBUFFER_COMPLETE          0x8CD5
		#define GL_FRAMEBUFFER_DEFAULT           0x8218
		#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
		#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
		#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
		#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
		#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
		#define GL_FRAMEBUFFER_SRGB              0x8DB9
		#define GL_FRAMEBUFFER_UNDEFINED         0x8219
		#define GL_FRAMEBUFFER_UNSUPPORTED       0x8CDD
		#define GL_GREEN_INTEGER                 0x8D95
		#define GL_HALF_FLOAT                    0x140B
		#define GL_INTERLEAVED_ATTRIBS           0x8C8C
		#define GL_INT_SAMPLER_1D                0x8DC9
		#define GL_INT_SAMPLER_1D_ARRAY          0x8DCE
		#define GL_INT_SAMPLER_2D                0x8DCA
		#define GL_INT_SAMPLER_2D_ARRAY          0x8DCF
		#define GL_INT_SAMPLER_3D                0x8DCB
		#define GL_INT_SAMPLER_CUBE              0x8DCC
		#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
		#define GL_MAJOR_VERSION                 0x821B
		#define GL_MAP_FLUSH_EXPLICIT_BIT        0x0010
		#define GL_MAP_INVALIDATE_BUFFER_BIT     0x0008
		#define GL_MAP_INVALIDATE_RANGE_BIT      0x0004
		#define GL_MAP_READ_BIT                  0x0001
		#define GL_MAP_UNSYNCHRONIZED_BIT        0x0020
		#define GL_MAP_WRITE_BIT                 0x0002
		#define GL_MAX_ARRAY_TEXTURE_LAYERS      0x88FF
		#define GL_MAX_CLIP_DISTANCES            0x0D32
		#define GL_MAX_COLOR_ATTACHMENTS         0x8CDF
		#define GL_MAX_PROGRAM_TEXEL_OFFSET      0x8905
		#define GL_MAX_RENDERBUFFER_SIZE         0x84E8
		#define GL_MAX_SAMPLES                   0x8D57
		#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
		#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
		#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
		#define GL_MAX_VARYING_COMPONENTS        0x8B4B
		#define GL_MINOR_VERSION                 0x821C
		#define GL_MIN_PROGRAM_TEXEL_OFFSET      0x8904
		#define GL_NUM_EXTENSIONS                0x821D
		#define GL_PRIMITIVES_GENERATED          0x8C87
		#define GL_PROXY_TEXTURE_1D_ARRAY        0x8C19
		#define GL_PROXY_TEXTURE_2D_ARRAY        0x8C1B
		#define GL_QUERY_BY_REGION_NO_WAIT       0x8E16
		#define GL_QUERY_BY_REGION_WAIT          0x8E15
		#define GL_QUERY_NO_WAIT                 0x8E14
		#define GL_QUERY_WAIT                    0x8E13
		#define GL_R11F_G11F_B10F                0x8C3A
		#define GL_R16                           0x822A
		#define GL_R16F                          0x822D
		#define GL_R16I                          0x8233
		#define GL_R16UI                         0x8234
		#define GL_R32F                          0x822E
		#define GL_R32I                          0x8235
		#define GL_R32UI                         0x8236
		#define GL_R8                            0x8229
		#define GL_R8I                           0x8231
		#define GL_R8UI                          0x8232
		#define GL_RASTERIZER_DISCARD            0x8C89
		#define GL_READ_FRAMEBUFFER              0x8CA8
		#define GL_READ_FRAMEBUFFER_BINDING      0x8CAA
		#define GL_RED_INTEGER                   0x8D94
		#define GL_RENDERBUFFER                  0x8D41
		#define GL_RENDERBUFFER_ALPHA_SIZE       0x8D53
		#define GL_RENDERBUFFER_BINDING          0x8CA7
		#define GL_RENDERBUFFER_BLUE_SIZE        0x8D52
		#define GL_RENDERBUFFER_DEPTH_SIZE       0x8D54
		#define GL_RENDERBUFFER_GREEN_SIZE       0x8D51
		#define GL_RENDERBUFFER_HEIGHT           0x8D43
		#define GL_RENDERBUFFER_INTERNAL_FORMAT  0x8D44
		#define GL_RENDERBUFFER_RED_SIZE         0x8D50
		#define GL_RENDERBUFFER_SAMPLES          0x8CAB
		#define GL_RENDERBUFFER_STENCIL_SIZE     0x8D55
		#define GL_RENDERBUFFER_WIDTH            0x8D42
		#define GL_RG                            0x8227
		#define GL_RG16                          0x822C
		#define GL_RG16F                         0x822F
		#define GL_RG16I                         0x8239
		#define GL_RG16UI                        0x823A
		#define GL_RG32F                         0x8230
		#define GL_RG32I                         0x823B
		#define GL_RG32UI                        0x823C
		#define GL_RG8                           0x822B
		#define GL_RG8I                          0x8237
		#define GL_RG8UI                         0x8238
		#define GL_RGB16F                        0x881B
		#define GL_RGB16I                        0x8D89
		#define GL_RGB16UI                       0x8D77
		#define GL_RGB32F                        0x8815
		#define GL_RGB32I                        0x8D83
		#define GL_RGB32UI                       0x8D71
		#define GL_RGB8I                         0x8D8F
		#define GL_RGB8UI                        0x8D7D
		#define GL_RGB9_E5                       0x8C3D
		#define GL_RGBA16F                       0x881A
		#define GL_RGBA16I                       0x8D88
		#define GL_RGBA16UI                      0x8D76
		#define GL_RGBA32F                       0x8814
		#define GL_RGBA32I                       0x8D82
		#define GL_RGBA32UI                      0x8D70
		#define GL_RGBA8I                        0x8D8E
		#define GL_RGBA8UI                       0x8D7C
		#define GL_RGBA_INTEGER                  0x8D99
		#define GL_RGB_INTEGER                   0x8D98
		#define GL_RG_INTEGER                    0x8228
		#define GL_SAMPLER_1D_ARRAY              0x8DC0
		#define GL_SAMPLER_1D_ARRAY_SHADOW       0x8DC3
		#define GL_SAMPLER_2D_ARRAY              0x8DC1
		#define GL_SAMPLER_2D_ARRAY_SHADOW       0x8DC4
		#define GL_SAMPLER_CUBE_SHADOW           0x8DC5
		#define GL_SEPARATE_ATTRIBS              0x8C8D
		#define GL_STENCIL_ATTACHMENT            0x8D20
		#define GL_STENCIL_INDEX1                0x8D46
		#define GL_STENCIL_INDEX16               0x8D49
		#define GL_STENCIL_INDEX4                0x8D47
		#define GL_STENCIL_INDEX8                0x8D48
		#define GL_TEXTURE_1D_ARRAY              0x8C18
		#define GL_TEXTURE_2D_ARRAY              0x8C1A
		#define GL_TEXTURE_ALPHA_TYPE            0x8C13
		#define GL_TEXTURE_BINDING_1D_ARRAY      0x8C1C
		#define GL_TEXTURE_BINDING_2D_ARRAY      0x8C1D
		#define GL_TEXTURE_BLUE_TYPE             0x8C12
		#define GL_TEXTURE_DEPTH_TYPE            0x8C16
		#define GL_TEXTURE_GREEN_TYPE            0x8C11
		#define GL_TEXTURE_RED_TYPE              0x8C10
		#define GL_TEXTURE_SHARED_SIZE           0x8C3F
		#define GL_TEXTURE_STENCIL_SIZE          0x88F1
		#define GL_TRANSFORM_FEEDBACK_BUFFER     0x8C8E
		#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
		#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
		#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
		#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
		#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
		#define GL_TRANSFORM_FEEDBACK_VARYINGS   0x8C83
		#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
		#define GL_UNSIGNED_INT_10F_11F_11F_REV  0x8C3B
		#define GL_UNSIGNED_INT_24_8             0x84FA
		#define GL_UNSIGNED_INT_5_9_9_9_REV      0x8C3E
		#define GL_UNSIGNED_INT_SAMPLER_1D       0x8DD1
		#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
		#define GL_UNSIGNED_INT_SAMPLER_2D       0x8DD2
		#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
		#define GL_UNSIGNED_INT_SAMPLER_3D       0x8DD3
		#define GL_UNSIGNED_INT_SAMPLER_CUBE     0x8DD4
		#define GL_UNSIGNED_INT_VEC2             0x8DC6
		#define GL_UNSIGNED_INT_VEC3             0x8DC7
		#define GL_UNSIGNED_INT_VEC4             0x8DC8
		#define GL_UNSIGNED_NORMALIZED           0x8C17
		#define GL_VERTEX_ARRAY_BINDING          0x85B5
		#define GL_VERTEX_ATTRIB_ARRAY_INTEGER   0x88FD
		
		// Version: 3.1
		#define GL_ACTIVE_UNIFORM_BLOCKS         0x8A36
		#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
		#define GL_COPY_READ_BUFFER              0x8F36
		#define GL_COPY_WRITE_BUFFER             0x8F37
		#define GL_INT_SAMPLER_2D_RECT           0x8DCD
		#define GL_INT_SAMPLER_BUFFER            0x8DD0
		#define GL_INVALID_INDEX                 0xFFFFFFFF
		#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
		#define GL_MAX_COMBINED_UNIFORM_BLOCKS   0x8A2E
		#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
		#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS   0x8A2D
		#define GL_MAX_RECTANGLE_TEXTURE_SIZE    0x84F8
		#define GL_MAX_TEXTURE_BUFFER_SIZE       0x8C2B
		#define GL_MAX_UNIFORM_BLOCK_SIZE        0x8A30
		#define GL_MAX_UNIFORM_BUFFER_BINDINGS   0x8A2F
		#define GL_MAX_VERTEX_UNIFORM_BLOCKS     0x8A2B
		#define GL_PRIMITIVE_RESTART             0x8F9D
		#define GL_PRIMITIVE_RESTART_INDEX       0x8F9E
		#define GL_PROXY_TEXTURE_RECTANGLE       0x84F7
		#define GL_R16_SNORM                     0x8F98
		#define GL_R8_SNORM                      0x8F94
		#define GL_RG16_SNORM                    0x8F99
		#define GL_RG8_SNORM                     0x8F95
		#define GL_RGB16_SNORM                   0x8F9A
		#define GL_RGB8_SNORM                    0x8F96
		#define GL_RGBA16_SNORM                  0x8F9B
		#define GL_RGBA8_SNORM                   0x8F97
		#define GL_SAMPLER_2D_RECT               0x8B63
		#define GL_SAMPLER_2D_RECT_SHADOW        0x8B64
		#define GL_SAMPLER_BUFFER                0x8DC2
		#define GL_SIGNED_NORMALIZED             0x8F9C
		#define GL_TEXTURE_BINDING_BUFFER        0x8C2C
		#define GL_TEXTURE_BINDING_RECTANGLE     0x84F6
		#define GL_TEXTURE_BUFFER                0x8C2A
		#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
		#define GL_TEXTURE_RECTANGLE             0x84F5
		#define GL_UNIFORM_ARRAY_STRIDE          0x8A3C
		#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
		#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
		#define GL_UNIFORM_BLOCK_BINDING         0x8A3F
		#define GL_UNIFORM_BLOCK_DATA_SIZE       0x8A40
		#define GL_UNIFORM_BLOCK_INDEX           0x8A3A
		#define GL_UNIFORM_BLOCK_NAME_LENGTH     0x8A41
		#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
		#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
		#define GL_UNIFORM_BUFFER                0x8A11
		#define GL_UNIFORM_BUFFER_BINDING        0x8A28
		#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
		#define GL_UNIFORM_BUFFER_SIZE           0x8A2A
		#define GL_UNIFORM_BUFFER_START          0x8A29
		#define GL_UNIFORM_IS_ROW_MAJOR          0x8A3E
		#define GL_UNIFORM_MATRIX_STRIDE         0x8A3D
		#define GL_UNIFORM_NAME_LENGTH           0x8A39
		#define GL_UNIFORM_OFFSET                0x8A3B
		#define GL_UNIFORM_SIZE                  0x8A38
		#define GL_UNIFORM_TYPE                  0x8A37
		#define GL_UNSIGNED_INT_SAMPLER_2D_RECT  0x8DD5
		#define GL_UNSIGNED_INT_SAMPLER_BUFFER   0x8DD8
		
		
		// Extension: 1.0
		extern void glAccum(GLenum op, GLfloat value);
		extern void glAlphaFunc(GLenum func, GLfloat ref);
		extern void glBegin(GLenum mode);
		extern void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap);
		extern void glBlendFunc(GLenum sfactor, GLenum dfactor);
		extern void glCallList(GLuint list);
		extern void glCallLists(GLsizei n, GLenum type, const GLvoid * lists);
		extern void glClear(GLbitfield mask);
		extern void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
		extern void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
		extern void glClearDepth(GLdouble depth);
		extern void glClearIndex(GLfloat c);
		extern void glClearStencil(GLint s);
		extern void glClipPlane(GLenum plane, const GLdouble * equation);
		extern void glColor3b(GLbyte red, GLbyte green, GLbyte blue);
		extern void glColor3bv(const GLbyte * v);
		extern void glColor3d(GLdouble red, GLdouble green, GLdouble blue);
		extern void glColor3dv(const GLdouble * v);
		extern void glColor3f(GLfloat red, GLfloat green, GLfloat blue);
		extern void glColor3fv(const GLfloat * v);
		extern void glColor3i(GLint red, GLint green, GLint blue);
		extern void glColor3iv(const GLint * v);
		extern void glColor3s(GLshort red, GLshort green, GLshort blue);
		extern void glColor3sv(const GLshort * v);
		extern void glColor3ub(GLubyte red, GLubyte green, GLubyte blue);
		extern void glColor3ubv(const GLubyte * v);
		extern void glColor3ui(GLuint red, GLuint green, GLuint blue);
		extern void glColor3uiv(const GLuint * v);
		extern void glColor3us(GLushort red, GLushort green, GLushort blue);
		extern void glColor3usv(const GLushort * v);
		extern void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
		extern void glColor4bv(const GLbyte * v);
		extern void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
		extern void glColor4dv(const GLdouble * v);
		extern void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
		extern void glColor4fv(const GLfloat * v);
		extern void glColor4i(GLint red, GLint green, GLint blue, GLint alpha);
		extern void glColor4iv(const GLint * v);
		extern void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha);
		extern void glColor4sv(const GLshort * v);
		extern void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
		extern void glColor4ubv(const GLubyte * v);
		extern void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha);
		extern void glColor4uiv(const GLuint * v);
		extern void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
		extern void glColor4usv(const GLushort * v);
		extern void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
		extern void glColorMaterial(GLenum face, GLenum mode);
		extern void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
		extern void glCullFace(GLenum mode);
		extern void glDeleteLists(GLuint list, GLsizei range);
		extern void glDepthFunc(GLenum func);
		extern void glDepthMask(GLboolean flag);
		extern void glDepthRange(GLdouble ren_near, GLdouble ren_far);
		extern void glDisable(GLenum cap);
		extern void glDrawBuffer(GLenum mode);
		extern void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
		extern void glEdgeFlag(GLboolean flag);
		extern void glEdgeFlagv(const GLboolean * flag);
		extern void glEnable(GLenum cap);
		extern void glEnd();
		extern void glEndList();
		extern void glEvalCoord1d(GLdouble u);
		extern void glEvalCoord1dv(const GLdouble * u);
		extern void glEvalCoord1f(GLfloat u);
		extern void glEvalCoord1fv(const GLfloat * u);
		extern void glEvalCoord2d(GLdouble u, GLdouble v);
		extern void glEvalCoord2dv(const GLdouble * u);
		extern void glEvalCoord2f(GLfloat u, GLfloat v);
		extern void glEvalCoord2fv(const GLfloat * u);
		extern void glEvalMesh1(GLenum mode, GLint i1, GLint i2);
		extern void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
		extern void glEvalPoint1(GLint i);
		extern void glEvalPoint2(GLint i, GLint j);
		extern void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer);
		extern void glFinish();
		extern void glFlush();
		extern void glFogf(GLenum pname, GLfloat param);
		extern void glFogfv(GLenum pname, const GLfloat * params);
		extern void glFogi(GLenum pname, GLint param);
		extern void glFogiv(GLenum pname, const GLint * params);
		extern void glFrontFace(GLenum mode);
		extern void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
		extern GLuint glGenLists(GLsizei range);
		extern void glGetBooleanv(GLenum pname, GLboolean * params);
		extern void glGetClipPlane(GLenum plane, GLdouble * equation);
		extern void glGetDoublev(GLenum pname, GLdouble * params);
		extern GLenum glGetError();
		extern void glGetFloatv(GLenum pname, GLfloat * params);
		extern void glGetIntegerv(GLenum pname, GLint * params);
		extern void glGetLightfv(GLenum light, GLenum pname, GLfloat * params);
		extern void glGetLightiv(GLenum light, GLenum pname, GLint * params);
		extern void glGetMapdv(GLenum target, GLenum query, GLdouble * v);
		extern void glGetMapfv(GLenum target, GLenum query, GLfloat * v);
		extern void glGetMapiv(GLenum target, GLenum query, GLint * v);
		extern void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params);
		extern void glGetMaterialiv(GLenum face, GLenum pname, GLint * params);
		extern void glGetPixelMapfv(GLenum map, GLfloat * values);
		extern void glGetPixelMapuiv(GLenum map, GLuint * values);
		extern void glGetPixelMapusv(GLenum map, GLushort * values);
		extern void glGetPolygonStipple(GLubyte * mask);
		extern const GLubyte * glGetString(GLenum name);
		extern void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params);
		extern void glGetTexEnviv(GLenum target, GLenum pname, GLint * params);
		extern void glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params);
		extern void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params);
		extern void glGetTexGeniv(GLenum coord, GLenum pname, GLint * params);
		extern void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels);
		extern void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params);
		extern void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params);
		extern void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params);
		extern void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params);
		extern void glHint(GLenum target, GLenum mode);
		extern void glIndexMask(GLuint mask);
		extern void glIndexd(GLdouble c);
		extern void glIndexdv(const GLdouble * c);
		extern void glIndexf(GLfloat c);
		extern void glIndexfv(const GLfloat * c);
		extern void glIndexi(GLint c);
		extern void glIndexiv(const GLint * c);
		extern void glIndexs(GLshort c);
		extern void glIndexsv(const GLshort * c);
		extern void glInitNames();
		extern GLboolean glIsEnabled(GLenum cap);
		extern GLboolean glIsList(GLuint list);
		extern void glLightModelf(GLenum pname, GLfloat param);
		extern void glLightModelfv(GLenum pname, const GLfloat * params);
		extern void glLightModeli(GLenum pname, GLint param);
		extern void glLightModeliv(GLenum pname, const GLint * params);
		extern void glLightf(GLenum light, GLenum pname, GLfloat param);
		extern void glLightfv(GLenum light, GLenum pname, const GLfloat * params);
		extern void glLighti(GLenum light, GLenum pname, GLint param);
		extern void glLightiv(GLenum light, GLenum pname, const GLint * params);
		extern void glLineStipple(GLint factor, GLushort pattern);
		extern void glLineWidth(GLfloat width);
		extern void glListBase(GLuint base);
		extern void glLoadIdentity();
		extern void glLoadMatrixd(const GLdouble * m);
		extern void glLoadMatrixf(const GLfloat * m);
		extern void glLoadName(GLuint name);
		extern void glLogicOp(GLenum opcode);
		extern void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points);
		extern void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points);
		extern void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points);
		extern void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points);
		extern void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
		extern void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
		extern void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
		extern void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
		extern void glMaterialf(GLenum face, GLenum pname, GLfloat param);
		extern void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params);
		extern void glMateriali(GLenum face, GLenum pname, GLint param);
		extern void glMaterialiv(GLenum face, GLenum pname, const GLint * params);
		extern void glMatrixMode(GLenum mode);
		extern void glMultMatrixd(const GLdouble * m);
		extern void glMultMatrixf(const GLfloat * m);
		extern void glNewList(GLuint list, GLenum mode);
		extern void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz);
		extern void glNormal3bv(const GLbyte * v);
		extern void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz);
		extern void glNormal3dv(const GLdouble * v);
		extern void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
		extern void glNormal3fv(const GLfloat * v);
		extern void glNormal3i(GLint nx, GLint ny, GLint nz);
		extern void glNormal3iv(const GLint * v);
		extern void glNormal3s(GLshort nx, GLshort ny, GLshort nz);
		extern void glNormal3sv(const GLshort * v);
		extern void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
		extern void glPassThrough(GLfloat token);
		extern void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values);
		extern void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values);
		extern void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values);
		extern void glPixelStoref(GLenum pname, GLfloat param);
		extern void glPixelStorei(GLenum pname, GLint param);
		extern void glPixelTransferf(GLenum pname, GLfloat param);
		extern void glPixelTransferi(GLenum pname, GLint param);
		extern void glPixelZoom(GLfloat xfactor, GLfloat yfactor);
		extern void glPointSize(GLfloat size);
		extern void glPolygonMode(GLenum face, GLenum mode);
		extern void glPolygonStipple(const GLubyte * mask);
		extern void glPopAttrib();
		extern void glPopMatrix();
		extern void glPopName();
		extern void glPushAttrib(GLbitfield mask);
		extern void glPushMatrix();
		extern void glPushName(GLuint name);
		extern void glRasterPos2d(GLdouble x, GLdouble y);
		extern void glRasterPos2dv(const GLdouble * v);
		extern void glRasterPos2f(GLfloat x, GLfloat y);
		extern void glRasterPos2fv(const GLfloat * v);
		extern void glRasterPos2i(GLint x, GLint y);
		extern void glRasterPos2iv(const GLint * v);
		extern void glRasterPos2s(GLshort x, GLshort y);
		extern void glRasterPos2sv(const GLshort * v);
		extern void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z);
		extern void glRasterPos3dv(const GLdouble * v);
		extern void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
		extern void glRasterPos3fv(const GLfloat * v);
		extern void glRasterPos3i(GLint x, GLint y, GLint z);
		extern void glRasterPos3iv(const GLint * v);
		extern void glRasterPos3s(GLshort x, GLshort y, GLshort z);
		extern void glRasterPos3sv(const GLshort * v);
		extern void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
		extern void glRasterPos4dv(const GLdouble * v);
		extern void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
		extern void glRasterPos4fv(const GLfloat * v);
		extern void glRasterPos4i(GLint x, GLint y, GLint z, GLint w);
		extern void glRasterPos4iv(const GLint * v);
		extern void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w);
		extern void glRasterPos4sv(const GLshort * v);
		extern void glReadBuffer(GLenum mode);
		extern void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels);
		extern void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
		extern void glRectdv(const GLdouble * v1, const GLdouble * v2);
		extern void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
		extern void glRectfv(const GLfloat * v1, const GLfloat * v2);
		extern void glRecti(GLint x1, GLint y1, GLint x2, GLint y2);
		extern void glRectiv(const GLint * v1, const GLint * v2);
		extern void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
		extern void glRectsv(const GLshort * v1, const GLshort * v2);
		extern GLint glRenderMode(GLenum mode);
		extern void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
		extern void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
		extern void glScaled(GLdouble x, GLdouble y, GLdouble z);
		extern void glScalef(GLfloat x, GLfloat y, GLfloat z);
		extern void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
		extern void glSelectBuffer(GLsizei size, GLuint * buffer);
		extern void glShadeModel(GLenum mode);
		extern void glStencilFunc(GLenum func, GLint ref, GLuint mask);
		extern void glStencilMask(GLuint mask);
		extern void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
		extern void glTexCoord1d(GLdouble s);
		extern void glTexCoord1dv(const GLdouble * v);
		extern void glTexCoord1f(GLfloat s);
		extern void glTexCoord1fv(const GLfloat * v);
		extern void glTexCoord1i(GLint s);
		extern void glTexCoord1iv(const GLint * v);
		extern void glTexCoord1s(GLshort s);
		extern void glTexCoord1sv(const GLshort * v);
		extern void glTexCoord2d(GLdouble s, GLdouble t);
		extern void glTexCoord2dv(const GLdouble * v);
		extern void glTexCoord2f(GLfloat s, GLfloat t);
		extern void glTexCoord2fv(const GLfloat * v);
		extern void glTexCoord2i(GLint s, GLint t);
		extern void glTexCoord2iv(const GLint * v);
		extern void glTexCoord2s(GLshort s, GLshort t);
		extern void glTexCoord2sv(const GLshort * v);
		extern void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r);
		extern void glTexCoord3dv(const GLdouble * v);
		extern void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
		extern void glTexCoord3fv(const GLfloat * v);
		extern void glTexCoord3i(GLint s, GLint t, GLint r);
		extern void glTexCoord3iv(const GLint * v);
		extern void glTexCoord3s(GLshort s, GLshort t, GLshort r);
		extern void glTexCoord3sv(const GLshort * v);
		extern void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
		extern void glTexCoord4dv(const GLdouble * v);
		extern void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
		extern void glTexCoord4fv(const GLfloat * v);
		extern void glTexCoord4i(GLint s, GLint t, GLint r, GLint q);
		extern void glTexCoord4iv(const GLint * v);
		extern void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q);
		extern void glTexCoord4sv(const GLshort * v);
		extern void glTexEnvf(GLenum target, GLenum pname, GLfloat param);
		extern void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params);
		extern void glTexEnvi(GLenum target, GLenum pname, GLint param);
		extern void glTexEnviv(GLenum target, GLenum pname, const GLint * params);
		extern void glTexGend(GLenum coord, GLenum pname, GLdouble param);
		extern void glTexGendv(GLenum coord, GLenum pname, const GLdouble * params);
		extern void glTexGenf(GLenum coord, GLenum pname, GLfloat param);
		extern void glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params);
		extern void glTexGeni(GLenum coord, GLenum pname, GLint param);
		extern void glTexGeniv(GLenum coord, GLenum pname, const GLint * params);
		extern void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
		extern void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
		extern void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
		extern void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params);
		extern void glTexParameteri(GLenum target, GLenum pname, GLint param);
		extern void glTexParameteriv(GLenum target, GLenum pname, const GLint * params);
		extern void glTranslated(GLdouble x, GLdouble y, GLdouble z);
		extern void glTranslatef(GLfloat x, GLfloat y, GLfloat z);
		extern void glVertex2d(GLdouble x, GLdouble y);
		extern void glVertex2dv(const GLdouble * v);
		extern void glVertex2f(GLfloat x, GLfloat y);
		extern void glVertex2fv(const GLfloat * v);
		extern void glVertex2i(GLint x, GLint y);
		extern void glVertex2iv(const GLint * v);
		extern void glVertex2s(GLshort x, GLshort y);
		extern void glVertex2sv(const GLshort * v);
		extern void glVertex3d(GLdouble x, GLdouble y, GLdouble z);
		extern void glVertex3dv(const GLdouble * v);
		extern void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
		extern void glVertex3fv(const GLfloat * v);
		extern void glVertex3i(GLint x, GLint y, GLint z);
		extern void glVertex3iv(const GLint * v);
		extern void glVertex3s(GLshort x, GLshort y, GLshort z);
		extern void glVertex3sv(const GLshort * v);
		extern void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
		extern void glVertex4dv(const GLdouble * v);
		extern void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
		extern void glVertex4fv(const GLfloat * v);
		extern void glVertex4i(GLint x, GLint y, GLint z, GLint w);
		extern void glVertex4iv(const GLint * v);
		extern void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w);
		extern void glVertex4sv(const GLshort * v);
		extern void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
		
		// Extension: 1.1
		extern GLboolean glAreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences);
		extern void glArrayElement(GLint i);
		extern void glBindTexture(GLenum target, GLuint texture);
		extern void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
		extern void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
		extern void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
		extern void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
		extern void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
		extern void glDeleteTextures(GLsizei n, const GLuint * textures);
		extern void glDisableClientState(GLenum ren_array);
		extern void glDrawArrays(GLenum mode, GLint first, GLsizei count);
		extern void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);
		extern void glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer);
		extern void glEnableClientState(GLenum ren_array);
		extern void glGenTextures(GLsizei n, GLuint * textures);
		extern void glGetPointerv(GLenum pname, GLvoid ** params);
		extern void glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer);
		extern void glIndexub(GLubyte c);
		extern void glIndexubv(const GLubyte * c);
		extern void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid * pointer);
		extern GLboolean glIsTexture(GLuint texture);
		extern void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer);
		extern void glPolygonOffset(GLfloat factor, GLfloat units);
		extern void glPopClientAttrib();
		extern void glPrioritizeTextures(GLsizei n, const GLuint * textures, const GLfloat * priorities);
		extern void glPushClientAttrib(GLbitfield mask);
		extern void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
		extern void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels);
		extern void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
		extern void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
		
		// Extension: 1.2
		extern void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
		extern void glBlendEquation(GLenum mode);
		extern void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
		extern void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices);
		extern void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
		extern void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
		
		// Extension: 1.3
		extern void glActiveTexture(GLenum texture);
		extern void glClientActiveTexture(GLenum texture);
		extern void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data);
		extern void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
		extern void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data);
		extern void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data);
		extern void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
		extern void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data);
		extern void glGetCompressedTexImage(GLenum target, GLint level, GLvoid * img);
		extern void glLoadTransposeMatrixd(const GLdouble * m);
		extern void glLoadTransposeMatrixf(const GLfloat * m);
		extern void glMultTransposeMatrixd(const GLdouble * m);
		extern void glMultTransposeMatrixf(const GLfloat * m);
		extern void glMultiTexCoord1d(GLenum target, GLdouble s);
		extern void glMultiTexCoord1dv(GLenum target, const GLdouble * v);
		extern void glMultiTexCoord1f(GLenum target, GLfloat s);
		extern void glMultiTexCoord1fv(GLenum target, const GLfloat * v);
		extern void glMultiTexCoord1i(GLenum target, GLint s);
		extern void glMultiTexCoord1iv(GLenum target, const GLint * v);
		extern void glMultiTexCoord1s(GLenum target, GLshort s);
		extern void glMultiTexCoord1sv(GLenum target, const GLshort * v);
		extern void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t);
		extern void glMultiTexCoord2dv(GLenum target, const GLdouble * v);
		extern void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
		extern void glMultiTexCoord2fv(GLenum target, const GLfloat * v);
		extern void glMultiTexCoord2i(GLenum target, GLint s, GLint t);
		extern void glMultiTexCoord2iv(GLenum target, const GLint * v);
		extern void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t);
		extern void glMultiTexCoord2sv(GLenum target, const GLshort * v);
		extern void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r);
		extern void glMultiTexCoord3dv(GLenum target, const GLdouble * v);
		extern void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
		extern void glMultiTexCoord3fv(GLenum target, const GLfloat * v);
		extern void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r);
		extern void glMultiTexCoord3iv(GLenum target, const GLint * v);
		extern void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r);
		extern void glMultiTexCoord3sv(GLenum target, const GLshort * v);
		extern void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
		extern void glMultiTexCoord4dv(GLenum target, const GLdouble * v);
		extern void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
		extern void glMultiTexCoord4fv(GLenum target, const GLfloat * v);
		extern void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q);
		extern void glMultiTexCoord4iv(GLenum target, const GLint * v);
		extern void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
		extern void glMultiTexCoord4sv(GLenum target, const GLshort * v);
		extern void glSampleCoverage(GLfloat value, GLboolean invert);
		
		// Extension: 1.4
		extern void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
		extern void glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer);
		extern void glFogCoordd(GLdouble coord);
		extern void glFogCoorddv(const GLdouble * coord);
		extern void glFogCoordf(GLfloat coord);
		extern void glFogCoordfv(const GLfloat * coord);
		extern void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
		extern void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const GLvoid *const* indices, GLsizei drawcount);
		extern void glPointParameterf(GLenum pname, GLfloat param);
		extern void glPointParameterfv(GLenum pname, const GLfloat * params);
		extern void glPointParameteri(GLenum pname, GLint param);
		extern void glPointParameteriv(GLenum pname, const GLint * params);
		extern void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue);
		extern void glSecondaryColor3bv(const GLbyte * v);
		extern void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue);
		extern void glSecondaryColor3dv(const GLdouble * v);
		extern void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue);
		extern void glSecondaryColor3fv(const GLfloat * v);
		extern void glSecondaryColor3i(GLint red, GLint green, GLint blue);
		extern void glSecondaryColor3iv(const GLint * v);
		extern void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue);
		extern void glSecondaryColor3sv(const GLshort * v);
		extern void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue);
		extern void glSecondaryColor3ubv(const GLubyte * v);
		extern void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue);
		extern void glSecondaryColor3uiv(const GLuint * v);
		extern void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue);
		extern void glSecondaryColor3usv(const GLushort * v);
		extern void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
		extern void glWindowPos2d(GLdouble x, GLdouble y);
		extern void glWindowPos2dv(const GLdouble * v);
		extern void glWindowPos2f(GLfloat x, GLfloat y);
		extern void glWindowPos2fv(const GLfloat * v);
		extern void glWindowPos2i(GLint x, GLint y);
		extern void glWindowPos2iv(const GLint * v);
		extern void glWindowPos2s(GLshort x, GLshort y);
		extern void glWindowPos2sv(const GLshort * v);
		extern void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z);
		extern void glWindowPos3dv(const GLdouble * v);
		extern void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z);
		extern void glWindowPos3fv(const GLfloat * v);
		extern void glWindowPos3i(GLint x, GLint y, GLint z);
		extern void glWindowPos3iv(const GLint * v);
		extern void glWindowPos3s(GLshort x, GLshort y, GLshort z);
		extern void glWindowPos3sv(const GLshort * v);
		
		// Extension: 1.5
		extern void glBeginQuery(GLenum target, GLuint id);
		extern void glBindBuffer(GLenum target, GLuint buffer);
		extern void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
		extern void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
		extern void glDeleteBuffers(GLsizei n, const GLuint * buffers);
		extern void glDeleteQueries(GLsizei n, const GLuint * ids);
		extern void glEndQuery(GLenum target);
		extern void glGenBuffers(GLsizei n, GLuint * buffers);
		extern void glGenQueries(GLsizei n, GLuint * ids);
		extern void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params);
		extern void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid ** params);
		extern void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);
		extern void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params);
		extern void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params);
		extern void glGetQueryiv(GLenum target, GLenum pname, GLint * params);
		extern GLboolean glIsBuffer(GLuint buffer);
		extern GLboolean glIsQuery(GLuint id);
		extern void * glMapBuffer(GLenum target, GLenum access);
		extern GLboolean glUnmapBuffer(GLenum target);
		
		// Extension: 2.0
		extern void glAttachShader(GLuint program, GLuint shader);
		extern void glBindAttribLocation(GLuint program, GLuint index, const GLchar * name);
		extern void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
		extern void glCompileShader(GLuint shader);
		extern GLuint glCreateProgram();
		extern GLuint glCreateShader(GLenum type);
		extern void glDeleteProgram(GLuint program);
		extern void glDeleteShader(GLuint shader);
		extern void glDetachShader(GLuint program, GLuint shader);
		extern void glDisableVertexAttribArray(GLuint index);
		extern void glDrawBuffers(GLsizei n, const GLenum * bufs);
		extern void glEnableVertexAttribArray(GLuint index);
		extern void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
		extern void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
		extern void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
		extern GLint glGetAttribLocation(GLuint program, const GLchar * name);
		extern void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
		extern void glGetProgramiv(GLuint program, GLenum pname, GLint * params);
		extern void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
		extern void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
		extern void glGetShaderiv(GLuint shader, GLenum pname, GLint * params);
		extern GLint glGetUniformLocation(GLuint program, const GLchar * name);
		extern void glGetUniformfv(GLuint program, GLint location, GLfloat * params);
		extern void glGetUniformiv(GLuint program, GLint location, GLint * params);
		extern void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer);
		extern void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params);
		extern void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params);
		extern void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params);
		extern GLboolean glIsProgram(GLuint program);
		extern GLboolean glIsShader(GLuint shader);
		extern void glLinkProgram(GLuint program);
		extern void glShaderSource(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length);
		extern void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
		extern void glStencilMaskSeparate(GLenum face, GLuint mask);
		extern void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
		extern void glUniform1f(GLint location, GLfloat v0);
		extern void glUniform1fv(GLint location, GLsizei count, const GLfloat * value);
		extern void glUniform1i(GLint location, GLint v0);
		extern void glUniform1iv(GLint location, GLsizei count, const GLint * value);
		extern void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
		extern void glUniform2fv(GLint location, GLsizei count, const GLfloat * value);
		extern void glUniform2i(GLint location, GLint v0, GLint v1);
		extern void glUniform2iv(GLint location, GLsizei count, const GLint * value);
		extern void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
		extern void glUniform3fv(GLint location, GLsizei count, const GLfloat * value);
		extern void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
		extern void glUniform3iv(GLint location, GLsizei count, const GLint * value);
		extern void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
		extern void glUniform4fv(GLint location, GLsizei count, const GLfloat * value);
		extern void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
		extern void glUniform4iv(GLint location, GLsizei count, const GLint * value);
		extern void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
		extern void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
		extern void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
		extern void glUseProgram(GLuint program);
		extern void glValidateProgram(GLuint program);
		extern void glVertexAttrib1d(GLuint index, GLdouble x);
		extern void glVertexAttrib1dv(GLuint index, const GLdouble * v);
		extern void glVertexAttrib1f(GLuint index, GLfloat x);
		extern void glVertexAttrib1fv(GLuint index, const GLfloat * v);
		extern void glVertexAttrib1s(GLuint index, GLshort x);
		extern void glVertexAttrib1sv(GLuint index, const GLshort * v);
		extern void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
		extern void glVertexAttrib2dv(GLuint index, const GLdouble * v);
		extern void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
		extern void glVertexAttrib2fv(GLuint index, const GLfloat * v);
		extern void glVertexAttrib2s(GLuint index, GLshort x, GLshort y);
		extern void glVertexAttrib2sv(GLuint index, const GLshort * v);
		extern void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
		extern void glVertexAttrib3dv(GLuint index, const GLdouble * v);
		extern void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
		extern void glVertexAttrib3fv(GLuint index, const GLfloat * v);
		extern void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
		extern void glVertexAttrib3sv(GLuint index, const GLshort * v);
		extern void glVertexAttrib4Nbv(GLuint index, const GLbyte * v);
		extern void glVertexAttrib4Niv(GLuint index, const GLint * v);
		extern void glVertexAttrib4Nsv(GLuint index, const GLshort * v);
		extern void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
		extern void glVertexAttrib4Nubv(GLuint index, const GLubyte * v);
		extern void glVertexAttrib4Nuiv(GLuint index, const GLuint * v);
		extern void glVertexAttrib4Nusv(GLuint index, const GLushort * v);
		extern void glVertexAttrib4bv(GLuint index, const GLbyte * v);
		extern void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
		extern void glVertexAttrib4dv(GLuint index, const GLdouble * v);
		extern void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
		extern void glVertexAttrib4fv(GLuint index, const GLfloat * v);
		extern void glVertexAttrib4iv(GLuint index, const GLint * v);
		extern void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
		extern void glVertexAttrib4sv(GLuint index, const GLshort * v);
		extern void glVertexAttrib4ubv(GLuint index, const GLubyte * v);
		extern void glVertexAttrib4uiv(GLuint index, const GLuint * v);
		extern void glVertexAttrib4usv(GLuint index, const GLushort * v);
		extern void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
		
		// Extension: 2.1
		extern void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
		extern void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
		extern void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
		extern void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
		extern void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
		extern void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
		
		// Extension: 3.0
		extern void glBeginConditionalRender(GLuint id, GLenum mode);
		extern void glBeginTransformFeedback(GLenum primitiveMode);
		extern void glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
		extern void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
		extern void glBindFragDataLocation(GLuint program, GLuint color, const GLchar * name);
		extern void glBindFramebuffer(GLenum target, GLuint framebuffer);
		extern void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
		extern void glBindVertexArray(GLuint ren_array);
		extern void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
		extern GLenum glCheckFramebufferStatus(GLenum target);
		extern void glClampColor(GLenum target, GLenum clamp);
		extern void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
		extern void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value);
		extern void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value);
		extern void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value);
		extern void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
		extern void glDeleteFramebuffers(GLsizei n, const GLuint * framebuffers);
		extern void glDeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers);
		extern void glDeleteVertexArrays(GLsizei n, const GLuint * arrays);
		extern void glDisablei(GLenum target, GLuint index);
		extern void glEnablei(GLenum target, GLuint index);
		extern void glEndConditionalRender();
		extern void glEndTransformFeedback();
		extern void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
		extern void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
		extern void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
		extern void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
		extern void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
		extern void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
		extern void glGenFramebuffers(GLsizei n, GLuint * framebuffers);
		extern void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers);
		extern void glGenVertexArrays(GLsizei n, GLuint * arrays);
		extern void glGenerateMipmap(GLenum target);
		extern void glGetBooleani_v(GLenum target, GLuint index, GLboolean * data);
		extern GLint glGetFragDataLocation(GLuint program, const GLchar * name);
		extern void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params);
		extern void glGetIntegeri_v(GLenum target, GLuint index, GLint * data);
		extern void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params);
		extern const GLubyte * glGetStringi(GLenum name, GLuint index);
		extern void glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params);
		extern void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params);
		extern void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
		extern void glGetUniformuiv(GLuint program, GLint location, GLuint * params);
		extern void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint * params);
		extern void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params);
		extern GLboolean glIsEnabledi(GLenum target, GLuint index);
		extern GLboolean glIsFramebuffer(GLuint framebuffer);
		extern GLboolean glIsRenderbuffer(GLuint renderbuffer);
		extern GLboolean glIsVertexArray(GLuint ren_array);
		extern void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
		extern void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
		extern void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
		extern void glTexParameterIiv(GLenum target, GLenum pname, const GLint * params);
		extern void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint * params);
		extern void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);
		extern void glUniform1ui(GLint location, GLuint v0);
		extern void glUniform1uiv(GLint location, GLsizei count, const GLuint * value);
		extern void glUniform2ui(GLint location, GLuint v0, GLuint v1);
		extern void glUniform2uiv(GLint location, GLsizei count, const GLuint * value);
		extern void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
		extern void glUniform3uiv(GLint location, GLsizei count, const GLuint * value);
		extern void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
		extern void glUniform4uiv(GLint location, GLsizei count, const GLuint * value);
		extern void glVertexAttribI1i(GLuint index, GLint x);
		extern void glVertexAttribI1iv(GLuint index, const GLint * v);
		extern void glVertexAttribI1ui(GLuint index, GLuint x);
		extern void glVertexAttribI1uiv(GLuint index, const GLuint * v);
		extern void glVertexAttribI2i(GLuint index, GLint x, GLint y);
		extern void glVertexAttribI2iv(GLuint index, const GLint * v);
		extern void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y);
		extern void glVertexAttribI2uiv(GLuint index, const GLuint * v);
		extern void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
		extern void glVertexAttribI3iv(GLuint index, const GLint * v);
		extern void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
		extern void glVertexAttribI3uiv(GLuint index, const GLuint * v);
		extern void glVertexAttribI4bv(GLuint index, const GLbyte * v);
		extern void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w);
		extern void glVertexAttribI4iv(GLuint index, const GLint * v);
		extern void glVertexAttribI4sv(GLuint index, const GLshort * v);
		extern void glVertexAttribI4ubv(GLuint index, const GLubyte * v);
		extern void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
		extern void glVertexAttribI4uiv(GLuint index, const GLuint * v);
		extern void glVertexAttribI4usv(GLuint index, const GLushort * v);
		extern void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
		
		// Extension: 3.1
		extern void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
		extern void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
		extern void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices, GLsizei instancecount);
		extern void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
		extern void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
		extern void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName);
		extern void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
		extern GLuint glGetUniformBlockIndex(GLuint program, const GLchar * uniformBlockName);
		extern void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices);
		extern void glPrimitiveRestartIndex(GLuint index);
		extern void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer);
		extern void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
		
		#ifdef __cplusplus
		}
		#endif /*__cplusplus*/
		
		#endif //OPENGL_NOLOAD_STYLE_H
