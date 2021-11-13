#ifndef __RT_AI_GARBAGE_MODEL_H
#define __RT_AI_GARBAGE_MODEL_H

/* model info ... */

// model name
#define RT_AI_GARBAGE_MODEL_NAME			"garbage"

#define RT_AI_GARBAGE_WORK_BUFFER_BYTES		(28064)

#define AI_GARBAGE_DATA_WEIGHTS_SIZE		(79624)

#define RT_AI_GARBAGE_BUFFER_ALIGNMENT		(4)

#define RT_AI_GARBAGE_IN_NUM				(1)

#define RT_AI_GARBAGE_IN_SIZE_BYTES	{	\
	((64 * 64 * 3) * 1),	\
}
#define RT_AI_GARBAGE_IN_1_SIZE			(64 * 64 * 3)
#define RT_AI_GARBAGE_IN_1_SIZE_BYTES		((64 * 64 * 3) * 1)
#define RT_AI_GARBAGE_IN_TOTAL_SIZE_BYTES		((64 * 64 * 3) * 1)



#define RT_AI_GARBAGE_OUT_NUM				(1)

#define RT_AI_GARBAGE_OUT_SIZE_BYTES	{	\
	((1 * 1 * 4) * 1),	\
}
#define RT_AI_GARBAGE_OUT_1_SIZE			(1 * 1 * 4)
#define RT_AI_GARBAGE_OUT_1_SIZE_BYTES		((1 * 1 * 4) * 1)
#define RT_AI_GARBAGE_OUT_TOTAL_SIZE_BYTES		((1 * 1 * 4) * 1)




#define RT_AI_GARBAGE_TOTAL_BUFFER_SIZE		//unused

#endif	//end
