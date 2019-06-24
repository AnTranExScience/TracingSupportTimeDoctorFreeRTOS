#ifndef TIMEDOCTOR_H
#define TIMEDOCTOR_H

#include <main.h>

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_ConfigOutputUART( UART_HandleTypeDef* huart )</pre>
 *
 * Configures the UART channel to which the tracing output will be sent. It is
 * expected that the UART channel has been pre-configured at this point and is
 * usable for writing to as it is.
 *
 * @param huart Handle to the channel. Should be of type UART_HandleTypeDef*.
 */
void TimeDoctor_ConfigOutputUART( UART_HandleTypeDef* huart );

/* Implementations of CONTROL MACROS */


/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceSTART()</pre>
 *
 * Records processor speed (SPEED), memory speed (MEMSPEED), and time
 * resolution (TIME) records for visualization in TimeDoctor. These entries
 * should always be present as initial records in TimeDoctor data files.
 */
void TimeDoctor_traceSTART();

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceEND()</pre>
 *
 * In the current implementation, this transmits the content of the data
 * buffer over the UART channel and thus ends the recording process.
 */
void TimeDoctor_traceEND();


/* Implementations of TASK MACROS */

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceTASK_CREATE( uint32_t uxTaskNumber, char* taskName )</pre>
 *
 * Records creation (CRE) and naming (NAM) of a task.
 *
 * @param uxTaskNumber Number assigned to the task by FreeRTOS.
 *
 * @param taskName Name of the task as per the user's declaration.
 */
void TimeDoctor_traceTASK_CREATE( uint32_t uxTaskNumber, char* taskName );

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceDELETE( uint32_t uxTaskNumber )</pre>
 *
 * Records that a task has been deleted (DEL).
 *
 * @param uxTaskNumber Number assigned to the task by FreeRTOS.
 */
void TimeDoctor_traceTASK_DELETE( uint32_t uxTaskNumber	);

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceSWITCHED_OUT( uint32_t uxTaskNumber )</pre>
 *
 * Records that a task has assumed blocked status (STO).
 *
 * @param uxTaskNumber Number assigned to the task by FreeRTOS.
 */
void TimeDoctor_traceTASK_SWITCHED_OUT( uint32_t uxTaskNumber );

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceSWITCHED_IN( uint32_t uxTaskNumber )</pre>
 *
 * Records that a task has assumed running status (STA).
 *
 * @param uxTaskNumber Number assigned to the task by FreeRTOS.
 */
void TimeDoctor_traceTASK_SWITCHED_IN( uint32_t uxTaskNumber );

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceTASK_SUSPEND( uint32_t uxTaskNumber )</pre>
 *
 * Records that a task has been suspended (STO). A suspended task never
 * assumes running state until resumed.
 *
 * @param uxTaskNumber Number assigned to the task by FreeRTOS.
 */
void TimeDoctor_traceTASK_SUSPEND( uint32_t uxTaskNumber );

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceTASK_RESUME( uint32_t uxTaskNumber )</pre>
 *
 * Records that a task has been resumed (STA). A resumed task will be
 * scheduled to run again according to its priority.
 *
 * @param uxTaskNumber Number assigned to the task by FreeRTOS.
 */
void TimeDoctor_traceTASK_RESUME( uint32_t uxTaskNumber );


/* Implementations of QUEUE MACROS */

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceQUEUE_CREATE( void *pxNewQueue )</pre>
 *
 * Records creation (CRE) of a queue. Queues in FreeRTOS do not have names,
 * nor does there exist an automatic numbering scheme for queues created.
 *
 * @param pxNewQueue Handle to the queue that was created.
 */
void TimeDoctor_traceQUEUE_CREATE( void *pxNewQueue );

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceQUEUE_REGISTRY_ADD( void *xQueue , char* pcQueueName)</pre>
 *
 * Records addition of a queue to the registry. As this implies setting the
 * queue's name to a value supplied by the use, it results in a NAM record.
 *
 * @param xQueue Handle to the queue that was created.
 *
 * @param pcQueueName Name of the queue as issued by the user.
 */
void TimeDoctor_traceQUEUE_REGISTRY_ADD( void *xQueue, const char* pcQueueName );

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceQUEUE_DELETE( void *pxQueue )</pre>
 *
 * Records deletion (DEL) of a queue.
 *
 * @param pxQueue Handle to the queue that is being deleted.
 */
void TimeDoctor_traceQUEUE_DELETE( void * pxQueue );

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceQUEUE_SEND( void *pxQueue, uint32_t uxMessagesWaiting )</pre>
 *
 * Records addition of an element to a queue (STA). This will include the
 * number of elements waiting in the queue after the operation.
 *
 * @param pxQueue Handle to the queue to which an element is being added.
 *
 * @param uxMessagesWaiting Number of messages currently waiting in the queue.
 */
void TimeDoctor_traceQUEUE_SEND( void *pxQueue, uint32_t uxMessagesWaiting );

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceQUEUE_RECEIVE( void *pxQueue, uint32_t uxMessagesWaiting )</pre>
 *
 * Records removal of an element from a queue (STO). This will include the
 * number of elements still waiting in the queue after the operation.
 *
 * @param pxQueue Handle to the queue from which an element is being removed.
 *
 * @param uxMessagesWaiting Number of messages currently waiting in the queue.
 */
void TimeDoctor_traceQUEUE_RECEIVE( void *pxQueue, uint32_t uxMessagesWaiting );

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceQUEUE_SEND_FROM_ISR( void *pxQueue, uint32_t uxMessagesWaiting )</pre>
 *
 * Records addition of an element to a queue (STA) when happening in the
 * context of an interrupt handler. This will include the number of elements
 * waiting in the queue after the operation.
 *
 * @param pxQueue Handle to the queue to which an element is being added.
 *
 * @param uxMessagesWaiting Number of messages currently waiting in the queue.
 */
void TimeDoctor_traceQUEUE_SEND_FROM_ISR( void *pxQueue, uint32_t uxMessagesWaiting );

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceQUEUE_RECEIVE( void *pxQueue, uint32_t uxMessagesWaiting )</pre>
 *
 * Records removal of an element from a queue (STO) when happening in the
 * context of an interrupt handler. This will include the number of elements
 * waiting in the queue after the operation.
 *
 * @param pxQueue Handle to the queue from which an element is being removed.
 *
 * @param uxMessagesWaiting Number of messages currently waiting in the queue.
 */
void TimeDoctor_traceQUEUE_RECEIVE_FROM_ISR( void *pxQueue, uint32_t uxMessagesWaiting );


/* Implementations of SEMAPHORE and MUTEX MACROS */

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceTAKE_MUTEX_RECURSIVE( void *pxMutex )</pre>
 *
 * Records that a recursive mutex has been obtained (STA).
 *
 * @param pxMutex Handle to the mutex object being obtained.
 */
void TimeDoctor_traceTAKE_MUTEX_RECURSIVE( void *pxMutex );

/**
 * TimeDoctor. h
 * <pre>void TimeDoctor_traceGIVE_MUTEX_RECURSIVE( void *pxMutex )</pre>
 *
 * Records that a recursive mutex has been released (STO).
 *
 * @param pxMutex Handle to the mutex object being released.
 */
void TimeDoctor_traceGIVE_MUTEX_RECURSIVE( void *pxMutex );

/* CONTROL MACROS */
#define traceSTART() TimeDoctor_traceSTART();
#define traceEND() TimeDoctor_traceEND();

/* TASK MACROS */
#define traceTASK_CREATE(pxNewTCB) TimeDoctor_traceTASK_CREATE( pxNewTCB->uxTCBNumber, pxNewTCB->pcTaskName );
#define traceTASK_DELETE( pxTaskToDelete ) TimeDoctor_traceTASK_DELETE( pxTaskToDelete->uxTCBNumber );
#define traceTASK_SWITCHED_OUT() TimeDoctor_traceTASK_SWITCHED_OUT( pxCurrentTCB->uxTCBNumber );
#define traceTASK_SWITCHED_IN() TimeDoctor_traceTASK_SWITCHED_IN( pxCurrentTCB->uxTCBNumber );
#define traceTASK_SUSPEND( pxTaskToSuspend ) TimeDoctor_traceTASK_SUSPEND( pxTaskToSuspend->uxTCBNumber);
#define traceTASK_RESUME( pxTaskToResume ) TimeDoctor_traceTASK_RESUME( pxTaskToResume->uxTCBNumber );

/* QUEUE MACROS */
#define traceQUEUE_CREATE( pxNewQueue ) TimeDoctor_traceQUEUE_CREATE( pxNewQueue );
#define traceQUEUE_REGISTRY_ADD( xQueue, pcQueueName ) TimeDoctor_traceQUEUE_REGISTRY_ADD( xQueue, pcQueueName );
#define traceQUEUE_DELETE( pxQueue ) TimeDoctor_traceQUEUE_DELETE( pxQueue );
#define traceQUEUE_SEND( pxQueue ) TimeDoctor_traceQUEUE_SEND( pxQueue, pxQueue->uxMessagesWaiting );
#define traceQUEUE_RECEIVE( pxQueue ) TimeDoctor_traceQUEUE_RECEIVE( pxQueue, pxQueue->uxMessagesWaiting );
#define traceQUEUE_SEND_FROM_ISR( pxQueue )  TimeDoctor_traceQUEUE_SEND_FROM_ISR( pxQueue, ((Queue_t *) pxQueue)->uxMessagesWaiting );
#define traceQUEUE_RECEIVE_FROM_ISR( pxQueue ) TimeDoctor_traceQUEUE_RECEIVE_FROM_ISR( pxQueue, ((Queue_t *) pxQueue)->uxMessagesWaiting );

/* SEMAPHORE and MUTEX MACROS */
#define traceTAKE_MUTEX_RECURSIVE( pxMutex ) TimeDoctor_traceTAKE_MUTEX_RECURSIVE( pxMutex );
#define traceGIVE_MUTEX_RECURSIVE( pxMutex ) TimeDoctor_traceGIVE_MUTEX_RECURSIVE( pxMutex );

#endif
