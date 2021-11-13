/**
  ******************************************************************************
  * @file    garbage.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Thu Jul 22 15:33:45 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "garbage.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"



#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 2
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_garbage
 
#undef AI_GARBAGE_MODEL_SIGNATURE
#define AI_GARBAGE_MODEL_SIGNATURE     "4008159b6c61f06bc7bfcaa7a95f8069"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Thu Jul 22 15:33:45 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_GARBAGE_N_BATCHES
#define AI_GARBAGE_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2d_5_scratch2_array;   /* Array #0 */
AI_STATIC ai_array conv2d_5_scratch1_array;   /* Array #1 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #2 */
AI_STATIC ai_array conv2d_4_scratch1_array;   /* Array #3 */
AI_STATIC ai_array conv2d_4_scratch0_array;   /* Array #4 */
AI_STATIC ai_array conv2d_3_scratch1_array;   /* Array #5 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #6 */
AI_STATIC ai_array conv2d_1_scratch2_array;   /* Array #7 */
AI_STATIC ai_array conv2d_1_scratch1_array;   /* Array #8 */
AI_STATIC ai_array conv2d_1_scratch0_array;   /* Array #9 */
AI_STATIC ai_array dense_8_bias_array;   /* Array #10 */
AI_STATIC ai_array dense_8_weights_array;   /* Array #11 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #12 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #13 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #14 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #15 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #16 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #17 */
AI_STATIC ai_array conv2d_1_bias_array;   /* Array #18 */
AI_STATIC ai_array conv2d_1_weights_array;   /* Array #19 */
AI_STATIC ai_array input_17_output_array;   /* Array #20 */
AI_STATIC ai_array conversion_0_output_array;   /* Array #21 */
AI_STATIC ai_array conv2d_1_output_array;   /* Array #22 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #23 */
AI_STATIC ai_array conv2d_4_output_array;   /* Array #24 */
AI_STATIC ai_array conv2d_5_output_array;   /* Array #25 */
AI_STATIC ai_array pool_7_output_array;   /* Array #26 */
AI_STATIC ai_array dense_8_output_array;   /* Array #27 */
AI_STATIC ai_array dense_8_fmt_output_array;   /* Array #28 */
AI_STATIC ai_array nl_9_output_array;   /* Array #29 */
AI_STATIC ai_array nl_9_fmt_output_array;   /* Array #30 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2d_5_scratch2;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_5_scratch1;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_4_scratch1;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_4_scratch0;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_3_scratch1;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_1_scratch2;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_1_scratch1;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_1_scratch0;   /* Tensor #9 */
AI_STATIC ai_tensor dense_8_bias;   /* Tensor #10 */
AI_STATIC ai_tensor dense_8_weights;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #17 */
AI_STATIC ai_tensor conv2d_1_bias;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_1_weights;   /* Tensor #19 */
AI_STATIC ai_tensor input_17_output;   /* Tensor #20 */
AI_STATIC ai_tensor conversion_0_output;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_1_output;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_4_output;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_5_output;   /* Tensor #25 */
AI_STATIC ai_tensor pool_7_output;   /* Tensor #26 */
AI_STATIC ai_tensor dense_8_output;   /* Tensor #27 */
AI_STATIC ai_tensor dense_8_fmt_output;   /* Tensor #28 */
AI_STATIC ai_tensor nl_9_output;   /* Tensor #29 */
AI_STATIC ai_tensor nl_9_fmt_output;   /* Tensor #30 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conversion_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_1_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_4_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_5_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain pool_7_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain dense_8_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain dense_8_fmt_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain nl_9_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain nl_9_fmt_chain;   /* Chain #9 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_nl conversion_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_1_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_4_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_5_layer; /* Layer #4 */
AI_STATIC ai_layer_pool pool_7_layer; /* Layer #5 */
AI_STATIC ai_layer_dense dense_8_layer; /* Layer #6 */
AI_STATIC ai_layer_nl dense_8_fmt_layer; /* Layer #7 */
AI_STATIC ai_layer_nl nl_9_layer; /* Layer #8 */
AI_STATIC ai_layer_nl nl_9_fmt_layer; /* Layer #9 */


/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8320, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8320, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6304, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 652, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  dense_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 4, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  dense_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 216, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  input_17_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 12288, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  pool_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  dense_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  dense_8_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  nl_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  nl_9_fmt_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 4, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_scratch2_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_scratch2_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.122883183299564e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003943587653338909f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.264164479332976e-05f, 2.9378434192040004e-05f, 3.083553383476101e-05f, 2.5545217795297503e-05f, 2.836394742189441e-05f, 2.3524493371951394e-05f, 2.0758308892254718e-05f, 2.789975405903533e-05f, 1.8894304957939312e-05f, 2.916575249400921e-05f, 2.3720758690615185e-05f, 2.1412493879324757e-05f, 3.123793430859223e-05f, 3.0334285838762298e-05f, 2.2305874153971672e-05f, 2.9937844374217093e-05f, 2.513685103622265e-05f, 2.8175662009743974e-05f, 2.5689434551168233e-05f, 2.6337818781030364e-05f, 3.516557262628339e-05f, 2.9288523364812136e-05f, 2.9434149837470613e-05f, 2.9885957701480947e-05f, 2.1647585526807234e-05f, 2.4549131921958178e-05f, 2.905164183175657e-05f, 2.8399706934578717e-05f, 2.818650500557851e-05f, 3.198032209184021e-05f, 2.7893980586668476e-05f, 2.7120766389998607e-05f, 2.2850190362078138e-05f, 2.8886815925943665e-05f, 2.5550303689669818e-05f, 2.5573132006684318e-05f, 3.2309086236637086e-05f, 2.837595275195781e-05f, 2.808403041854035e-05f, 3.273804031778127e-05f, 2.5340172214782797e-05f, 2.4797755031613633e-05f, 2.6391402570880018e-05f, 2.498467620171141e-05f, 3.115612344117835e-05f, 2.729020889091771e-05f, 2.9970880859764293e-05f, 2.7943129680352286e-05f, 3.1461237085750327e-05f, 2.560838038334623e-05f, 2.7028649128624238e-05f, 2.4303668396896683e-05f, 2.693056558200624e-05f, 2.5545419703121297e-05f, 3.0120550945866853e-05f, 2.6385736418887973e-05f, 3.2624302548356354e-05f, 3.01514573948225e-05f, 2.7208137908019125e-05f, 2.850618511729408e-05f, 2.991615838254802e-05f, 2.2447271476266906e-05f, 2.48448304773774e-05f, 2.7985133783658966e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013872699346393347f, 0.0012485834304243326f, 0.0013105102116242051f, 0.0010856717126443982f, 0.0012054677354171872f, 0.0009997909655794501f, 0.0008822280797176063f, 0.0011857395293191075f, 0.0008030079188756645f, 0.001239544479176402f, 0.0010081322398036718f, 0.000910030968952924f, 0.001327612204477191f, 0.0012892071390524507f, 0.0009479996515437961f, 0.0012723583495244384f, 0.0010683161672204733f, 0.0011974655790254474f, 0.0010918009793385863f, 0.0011193573009222746f, 0.0014945368748158216f, 0.0012447622139006853f, 0.0012509513180702925f, 0.0012701532104983926f, 0.0009200223721563816f, 0.0010433380957692862f, 0.0012346947332844138f, 0.0012069875374436378f, 0.0011979264672845602f, 0.001359163667075336f, 0.0011854941258206964f, 0.001152632525190711f, 0.0009711330640129745f, 0.0012276896741241217f, 0.0010858878958970308f, 0.0010868581011891365f, 0.0013731361832469702f, 0.0012059779837727547f, 0.0011935712536796927f, 0.0013913667062297463f, 0.0010769573273137212f, 0.001053904532454908f, 0.001121634617447853f, 0.001061848714016378f, 0.001324135228060186f, 0.0011598338605836034f, 0.001273762434720993f, 0.001187582965940237f, 0.0013371024979278445f, 0.0010883561335504055f, 0.001148717594332993f, 0.0010329058859497309f, 0.0011445489944890141f, 0.0010856803273782134f, 0.0012801233679056168f, 0.0011213937541469932f, 0.0013865327928215265f, 0.00128143688198179f, 0.0011563458247110248f, 0.0012115128338336945f, 0.0012714366894215345f, 0.0009540090104565024f, 0.0010559052461758256f, 0.001189368194900453f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.339777347515337e-05f, 2.1618361643049866e-05f, 2.2327847545966506e-05f, 2.5922870918293484e-05f, 2.490730184945278e-05f, 2.7697904442902654e-05f, 2.1169233150430955e-05f, 2.2462005290435627e-05f, 1.9682109268615022e-05f, 2.1028719856985845e-05f, 2.6573507057037205e-05f, 3.0385041100089438e-05f, 2.6464049369678833e-05f, 1.805999272619374e-05f, 2.1720990844187327e-05f, 2.4999251763802022e-05f, 2.1905620087636635e-05f, 2.601474625407718e-05f, 2.9360002372413874e-05f, 3.163511792081408e-05f, 2.5492903660051525e-05f, 2.560030588938389e-05f, 2.7189007596462034e-05f, 2.2887190425535664e-05f, 2.3631904696230777e-05f, 2.3669665097258985e-05f, 2.2830634407000616e-05f, 2.1639169062837027e-05f, 1.9476561647024937e-05f, 2.6951083782478236e-05f, 2.878208579204511e-05f, 3.1577597837895155e-05f, 3.199228740413673e-05f, 3.216284676454961e-05f, 2.328871050849557e-05f, 3.0150355087243952e-05f, 2.027340633503627e-05f, 2.431756911391858e-05f, 2.035025136137847e-05f, 2.5200002710334957e-05f, 2.210983984696213e-05f, 2.9357879611779936e-05f, 2.733557266765274e-05f, 1.763771433616057e-05f, 2.159258110623341e-05f, 2.229998426628299e-05f, 2.1152218323550187e-05f, 2.9155442462069914e-05f, 2.0951483747921884e-05f, 2.1620993720716797e-05f, 2.9352204364840873e-05f, 2.8369731808197685e-05f, 2.5942405045498163e-05f, 2.2682970666210167e-05f, 3.3802385587478057e-05f, 2.7012370992451906e-05f, 2.5142233425867744e-05f, 2.8624443075386807e-05f, 1.8968048607348464e-05f, 2.3103517378331162e-05f, 1.892763793875929e-05f, 2.013228186115157e-05f, 2.6630701540852897e-05f, 2.6519126549828798e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009944053599610925f, 0.00091878033708781f, 0.0009489335352554917f, 0.0011017220094799995f, 0.0010585603304207325f, 0.0011771608842536807f, 0.0008996924152597785f, 0.0009546352084726095f, 0.000836489605717361f, 0.0008937205420807004f, 0.0011293740244582295f, 0.001291364198550582f, 0.0011247220681980252f, 0.0007675496744923294f, 0.0009231420699506998f, 0.001062468159943819f, 0.0009309888118878007f, 0.0011056266957893968f, 0.0012478000717237592f, 0.0013444924261420965f, 0.0010834484128281474f, 0.0010880129411816597f, 0.0011555327801033854f, 0.0009727056021802127f, 0.0010043559595942497f, 0.001005960744805634f, 0.0009703019168227911f, 0.0009196646860800683f, 0.0008277538581751287f, 0.0011454210616648197f, 0.0012232386507093906f, 0.0013420478207990527f, 0.001359672169201076f, 0.0013669210020452738f, 0.0009897701675072312f, 0.0012813900830224156f, 0.000861619773786515f, 0.0010334966937080026f, 0.0008648856310173869f, 0.0010710001224651933f, 0.0009396681562066078f, 0.0012477098498493433f, 0.0011617618147283792f, 0.0007496028556488454f, 0.0009176846942864358f, 0.0009477493003942072f, 0.0008989692432805896f, 0.0012391062919050455f, 0.0008904380374588072f, 0.0009188922122120857f, 0.0012474686373025179f, 0.0012057136045768857f, 0.0011025521671399474f, 0.0009640261996537447f, 0.0014366013929247856f, 0.0011480257380753756f, 0.0010685449233278632f, 0.0012165388325229287f, 0.0008061420521698892f, 0.000981899444013834f, 0.0008044245769269764f, 0.0008556219981983304f, 0.001131804776377976f, 0.0011270628310739994f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.611267548985779e-05f, 8.778773917583749e-05f, 9.067166683962569e-05f, 9.613266593078151e-05f, 9.032268280861899e-05f, 0.00012080591113772243f, 0.00011043602717109025f, 0.00012676311598625034f, 8.727780368644744e-05f, 0.00013200557441450655f, 8.347971743205562e-05f, 0.00010242622374789789f, 0.00012617050379049033f, 0.00011196628474863246f, 8.663332118885592e-05f, 8.942335261963308e-05f, 6.729143933625892e-05f, 0.00010465058585396037f, 6.798333197366446e-05f, 8.915652142604813e-05f, 0.0001014176887110807f, 8.942148997448385e-05f, 0.00010470159031683579f, 9.705173579277471e-05f, 7.55118380766362e-05f, 8.594716200605035e-05f, 9.05215711100027e-05f, 9.782516281120479e-05f, 7.887898391345516e-05f, 7.958195055834949e-05f, 8.350156713277102e-05f, 9.178148320643231e-05f, 8.314599836012349e-05f, 9.338378004031256e-05f, 7.407317752949893e-05f, 0.00012466967746149749f, 7.818270387360826e-05f, 0.00011061998520744964f, 0.00010766454943222925f, 9.007062180899084e-05f, 8.180185250239447e-05f, 9.879150456981733e-05f, 9.62222256930545e-05f, 0.00010230831685476005f, 7.523731619585305e-05f, 8.279652683995664e-05f, 0.00012654672900680453f, 0.00011285402433713898f, 7.745117181912065e-05f, 0.00011182712478330359f, 0.00012027829507132992f, 0.00010209674655925483f, 0.00010989134170813486f, 9.913108078762889e-05f, 8.971292118076235e-05f, 7.811742398189381e-05f, 9.538802987663075e-05f, 0.00010425037908134982f, 0.00014459331578109413f, 0.00010588476288830861f, 9.277582284994423e-05f, 7.069407729431987e-05f, 0.00011186880146851763f, 8.252573024947196e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003659788751974702f, 0.0037309788167476654f, 0.003853545757010579f, 0.004085638094693422f, 0.0038387139793485403f, 0.005134250968694687f, 0.0046935309655964375f, 0.005387432407587767f, 0.003709306474775076f, 0.005610236898064613f, 0.003547887783497572f, 0.004353114403784275f, 0.005362246185541153f, 0.0047585670836269855f, 0.003681916045024991f, 0.0038004922680556774f, 0.002859886037185788f, 0.004447649698704481f, 0.0028892916161566973f, 0.003789152018725872f, 0.00431025167927146f, 0.003800413105636835f, 0.004449817351996899f, 0.00412469869479537f, 0.0032092530746012926f, 0.0036527542397379875f, 0.0038471666630357504f, 0.004157569259405136f, 0.0033523566089570522f, 0.0033822329714894295f, 0.0035488165449351072f, 0.0039007130544632673f, 0.0035337049048393965f, 0.00396881066262722f, 0.003148110117763281f, 0.005298461299389601f, 0.00332276476547122f, 0.004701349418610334f, 0.004575743339955807f, 0.0038280014414340258f, 0.0034765785094350576f, 0.0041986387223005295f, 0.004089444410055876f, 0.0043481034226715565f, 0.003197585931047797f, 0.0035188524052500725f, 0.005378236062824726f, 0.004796295892447233f, 0.003291674889624119f, 0.00475265271961689f, 0.00511182751506567f, 0.004339111503213644f, 0.004670382011681795f, 0.004213070962578058f, 0.0038127992302179337f, 0.0033199903555214405f, 0.004053991287946701f, 0.004430640954524279f, 0.006145215593278408f, 0.004500102251768112f, 0.003942972514778376f, 0.003004498081281781f, 0.004754424095153809f, 0.003507343353703618f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.017685806611553e-05f, 2.8267950256122276e-05f, 7.457642641384155e-05f, 5.501643317984417e-05f, 4.644433647627011e-05f, 4.991302193957381e-05f, 5.0992766773561016e-05f, 4.405746585689485e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022995097562670708f, 0.007208326831459999f, 0.019016986712813377f, 0.014029189944267273f, 0.011843305081129074f, 0.012727819383144379f, 0.013003154657781124f, 0.011234653182327747f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(input_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(pool_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010454650968313217f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07085452973842621f),
    AI_PACK_INTQ_ZP(-56)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_9_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_UINTQ_ZP(0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch2, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 2), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_5_scratch2_array, &conv2d_5_scratch2_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 2), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_5_scratch1_array, &conv2d_5_scratch1_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8320, 8320),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_4_scratch1_array, &conv2d_4_scratch1_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8320, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8320, 8320),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_3_scratch1_array, &conv2d_3_scratch1_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 6304, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6304, 6304),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch2, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 32, 2), AI_STRIDE_INIT(4, 1, 1, 8, 256),
  1, &conv2d_1_scratch2_array, &conv2d_1_scratch2_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch1, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 32, 2), AI_STRIDE_INIT(4, 1, 1, 8, 256),
  1, &conv2d_1_scratch1_array, &conv2d_1_scratch1_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 652, 1, 1), AI_STRIDE_INIT(4, 1, 1, 652, 652),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  dense_8_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &dense_8_bias_array, &dense_8_bias_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  dense_8_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 4, 1, 1), AI_STRIDE_INIT(4, 1, 64, 256, 256),
  1, &dense_8_weights_array, &dense_8_weights_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_4_bias_array, &conv2d_4_bias_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 64, 3, 3, 64), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_4_weights_array, &conv2d_4_weights_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 3, 3, 64), AI_STRIDE_INIT(4, 1, 8, 24, 72),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_1_bias_array, &conv2d_1_bias_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 3, 3, 3, 8), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &conv2d_1_weights_array, &conv2d_1_weights_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  input_17_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 64, 64), AI_STRIDE_INIT(4, 1, 1, 3, 192),
  1, &input_17_output_array, &input_17_output_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 64, 64), AI_STRIDE_INIT(4, 1, 1, 3, 192),
  1, &conversion_0_output_array, &conversion_0_output_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 16, 16), AI_STRIDE_INIT(4, 1, 1, 8, 128),
  1, &conv2d_1_output_array, &conv2d_1_output_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 16, 16), AI_STRIDE_INIT(4, 1, 1, 64, 1024),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 8, 8), AI_STRIDE_INIT(4, 1, 1, 64, 512),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  pool_7_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &pool_7_output_array, &pool_7_output_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  dense_8_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4, 4),
  1, &dense_8_output_array, &dense_8_output_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  dense_8_fmt_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &dense_8_fmt_output_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  nl_9_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &nl_9_output_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  nl_9_fmt_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 1, 1, 4, 4),
  1, &nl_9_fmt_output_array, &nl_9_fmt_output_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE,
  nl, node_convert_integer,
  &AI_NET_OBJ_INSTANCE, &conv2d_1_layer, AI_STATIC,
  .tensors = &conversion_0_chain, 
)


AI_STATIC_CONST ai_i8 conv2d_1_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_1_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_1_nl_params_data, conv2d_1_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_scratch0, &conv2d_1_scratch1, &conv2d_1_scratch2)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 1,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_3_layer, AI_STATIC,
  .tensors = &conv2d_1_chain, 
  .groups = 1, 
  .nl_params = &conv2d_1_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_INT8, 
)


AI_STATIC_CONST ai_i8 conv2d_3_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_3_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_3_nl_params_data, conv2d_3_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_3_scratch0, &conv2d_3_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_4_layer, AI_STATIC,
  .tensors = &conv2d_3_chain, 
  .groups = 1, 
  .nl_params = &conv2d_3_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_4_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_4_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_4_nl_params_data, conv2d_4_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_4_scratch0, &conv2d_4_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 4,
  CONV2D_TYPE,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &conv2d_5_layer, AI_STATIC,
  .tensors = &conv2d_4_chain, 
  .groups = 1, 
  .nl_params = &conv2d_4_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_i8 conv2d_5_nl_params_data[] = { -128, 127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_5_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_5_nl_params_data, conv2d_5_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_scratch0, &conv2d_5_scratch1, &conv2d_5_scratch2)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 5,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &AI_NET_OBJ_INSTANCE, &pool_7_layer, AI_STATIC,
  .tensors = &conv2d_5_chain, 
  .groups = 1, 
  .nl_params = &conv2d_5_nl_params, 
  .nl_func = nl_func_clip_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  pool_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_7_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pool_7_layer, 7,
  POOL_TYPE,
  pool, forward_ap_integer_INT8,
  &AI_NET_OBJ_INSTANCE, &dense_8_layer, AI_STATIC,
  .tensors = &pool_7_chain, 
  .pool_size = AI_SHAPE_2D_INIT(8, 8), 
  .pool_stride = AI_SHAPE_2D_INIT(8, 8), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pool_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_8_weights, &dense_8_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_8_layer, 8,
  DENSE_TYPE,
  dense, forward_dense_integer_SSSA,
  &AI_NET_OBJ_INSTANCE, &dense_8_fmt_layer, AI_STATIC,
  .tensors = &dense_8_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_8_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_8_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_8_fmt_layer, 8,
  NL_TYPE,
  nl, node_convert,
  &AI_NET_OBJ_INSTANCE, &nl_9_layer, AI_STATIC,
  .tensors = &dense_8_fmt_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_8_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_9_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_9_layer, 9,
  NL_TYPE,
  nl, forward_sm,
  &AI_NET_OBJ_INSTANCE, &nl_9_fmt_layer, AI_STATIC,
  .tensors = &nl_9_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_9_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_9_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_9_fmt_layer, 9,
  NL_TYPE,
  nl, node_convert,
  &AI_NET_OBJ_INSTANCE, &nl_9_fmt_layer, AI_STATIC,
  .tensors = &nl_9_fmt_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 79624, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 28064, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_GARBAGE_IN_NUM, &input_17_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_GARBAGE_OUT_NUM, &nl_9_fmt_output),
  &conversion_0_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool garbage_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, AI_GARBAGE_ACTIVATIONS_ALIGNMENT));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    conv2d_5_scratch2_array.data = AI_PTR(activations + 17696);
    conv2d_5_scratch2_array.data_start = AI_PTR(activations + 17696);
    conv2d_5_scratch1_array.data = AI_PTR(activations + 17696);
    conv2d_5_scratch1_array.data_start = AI_PTR(activations + 17696);
    conv2d_5_scratch0_array.data = AI_PTR(activations + 19744);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations + 19744);
    conv2d_4_scratch1_array.data = AI_PTR(activations + 1152);
    conv2d_4_scratch1_array.data_start = AI_PTR(activations + 1152);
    conv2d_4_scratch0_array.data = AI_PTR(activations + 19744);
    conv2d_4_scratch0_array.data_start = AI_PTR(activations + 19744);
    conv2d_3_scratch1_array.data = AI_PTR(activations + 3328);
    conv2d_3_scratch1_array.data_start = AI_PTR(activations + 3328);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 21760);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 21760);
    conv2d_1_scratch2_array.data = AI_PTR(activations + 5748);
    conv2d_1_scratch2_array.data_start = AI_PTR(activations + 5748);
    conv2d_1_scratch1_array.data = AI_PTR(activations + 19200);
    conv2d_1_scratch1_array.data_start = AI_PTR(activations + 19200);
    conv2d_1_scratch0_array.data = AI_PTR(activations + 6260);
    conv2d_1_scratch0_array.data_start = AI_PTR(activations + 6260);
    input_17_output_array.data = AI_PTR(NULL);
    input_17_output_array.data_start = AI_PTR(NULL);
    conversion_0_output_array.data = AI_PTR(activations + 6912);
    conversion_0_output_array.data_start = AI_PTR(activations + 6912);
    conv2d_1_output_array.data = AI_PTR(activations + 19712);
    conv2d_1_output_array.data_start = AI_PTR(activations + 19712);
    conv2d_3_output_array.data = AI_PTR(activations + 3328);
    conv2d_3_output_array.data_start = AI_PTR(activations + 3328);
    conv2d_4_output_array.data = AI_PTR(activations + 1152);
    conv2d_4_output_array.data_start = AI_PTR(activations + 1152);
    conv2d_5_output_array.data = AI_PTR(activations + 0);
    conv2d_5_output_array.data_start = AI_PTR(activations + 0);
    pool_7_output_array.data = AI_PTR(activations + 4096);
    pool_7_output_array.data_start = AI_PTR(activations + 4096);
    dense_8_output_array.data = AI_PTR(activations + 0);
    dense_8_output_array.data_start = AI_PTR(activations + 0);
    dense_8_fmt_output_array.data = AI_PTR(activations + 4);
    dense_8_fmt_output_array.data_start = AI_PTR(activations + 4);
    nl_9_output_array.data = AI_PTR(activations + 20);
    nl_9_output_array.data_start = AI_PTR(activations + 20);
    nl_9_fmt_output_array.data = AI_PTR(NULL);
    nl_9_fmt_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool garbage_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    dense_8_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_8_bias_array.data = AI_PTR(weights + 79608);
    dense_8_bias_array.data_start = AI_PTR(weights + 79608);
    dense_8_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_8_weights_array.data = AI_PTR(weights + 79352);
    dense_8_weights_array.data_start = AI_PTR(weights + 79352);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights + 79096);
    conv2d_5_bias_array.data_start = AI_PTR(weights + 79096);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights + 42232);
    conv2d_5_weights_array.data_start = AI_PTR(weights + 42232);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(weights + 41976);
    conv2d_4_bias_array.data_start = AI_PTR(weights + 41976);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(weights + 5112);
    conv2d_4_weights_array.data_start = AI_PTR(weights + 5112);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights + 4856);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 4856);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights + 248);
    conv2d_3_weights_array.data_start = AI_PTR(weights + 248);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(weights + 216);
    conv2d_1_bias_array.data_start = AI_PTR(weights + 216);
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(weights + 0);
    conv2d_1_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_garbage_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_GARBAGE_MODEL_NAME,
      .model_signature   = AI_GARBAGE_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 20443668,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_garbage_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_garbage_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_garbage_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_garbage_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= garbage_configure_weights(net_ctx, &params->params);
  ok &= garbage_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_garbage_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_garbage_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}




#undef AI_GARBAGE_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

