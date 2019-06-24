#include <stdio.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "TimeDoctor.h"
#include "main.h"

static char buffer[2048];
static int buffer_used = 0;

UART_HandleTypeDef *g_huart;

void TimeDoctor_ConfigOutputUART( UART_HandleTypeDef* huart )
{
	g_huart = huart;
}


/* Implementations of CONTROL MACROS */

void TimeDoctor_traceSTART()
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "SPEED %lu\r\n", HAL_RCC_GetHCLKFreq() );
	buffer_used += sprintf( buffer+buffer_used, "MEMSPEED %lu\r\n", HAL_RCC_GetHCLKFreq() );
	buffer_used += sprintf( buffer+buffer_used, "TIME %d\r\n", 1000 );
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceEND()
{
	HAL_UART_Transmit( g_huart, (uint8_t *) buffer, buffer_used, HAL_MAX_DELAY );
}


/* Implementations of TASK MACROS */

void TimeDoctor_traceTASK_CREATE(  uint32_t uxTaskNumber, char* taskName )
{
	if ( buffer_used > sizeof( buffer )-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "CRE 0 %lu %lu\r\n", uxTaskNumber, HAL_GetTick() );
	buffer_used += sprintf( buffer+buffer_used, "NAM 0 %lu %s\r\n", uxTaskNumber, taskName );
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceTASK_SWITCHED_IN( uint32_t uxTaskNumber )
{
	if ( buffer_used > sizeof( buffer )-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "STA 0 %lu %lu\r\n", uxTaskNumber, HAL_GetTick() );
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceTASK_SWITCHED_OUT( uint32_t uxTaskNumber )
{
	if ( buffer_used > sizeof( buffer )-64 )
		return; // buffer full, do not write

	UBaseType_t state  = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "STO 0 %lu %lu\r\n", uxTaskNumber, HAL_GetTick() );
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceTASK_DELETE( uint32_t uxTaskNumber )
{
	if ( buffer_used > sizeof( buffer )-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "DEL 0 %lu %lu\r\n", uxTaskNumber, HAL_GetTick() );
	taskEXIT_CRITICAL_FROM_ISR( state) ;

}

void TimeDoctor_traceTASK_SUSPEND ( uint32_t uxTaskNumber )
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "STO 0 %lu %lu\r\n", uxTaskNumber, HAL_GetTick() );
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceTASK_RESUME(  uint32_t uxTaskNumber )
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "STA 0 %lu %lu\r\n", uxTaskNumber, HAL_GetTick() );
	taskEXIT_CRITICAL_FROM_ISR( state );
}


/* Implementations of TASK MACROS */

void TimeDoctor_traceQUEUE_CREATE( void *pxNewQueue )
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "CRE 3 %d %lu \r\n", (uint16_t) ((uint32_t)pxNewQueue  & 0xffff), HAL_GetTick() );
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceQUEUE_REGISTRY_ADD( void *xQueue, const char* pcQueueName )
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "NAM 3 %d %s\r\n", (uint16_t) ((uint32_t)xQueue & 0xffff), pcQueueName );
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceQUEUE_SEND( void *pxQueue, uint32_t uxMessagesWaiting )
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used,  "STA 3 %d %lu %lu\r\n", (uint16_t) ((uint32_t)pxQueue & 0xffff), HAL_GetTick(), uxMessagesWaiting+1 );
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceQUEUE_RECEIVE( void *pxQueue, uint32_t uxMessagesWaiting ) /*The number of items currently in the queue. */
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "STO 3 %d %lu %lu \r\n", (uint16_t) ((uint32_t)pxQueue & 0xffff), HAL_GetTick(), uxMessagesWaiting );
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceQUEUE_DELETE( void *pxQueue )
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "DEL 3 %d %lu\r\n", (uint16_t) ((uint32_t)pxQueue & 0xffff), HAL_GetTick());
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceQUEUE_SEND_FROM_ISR( void *pxQueue, uint32_t uxMessagesWaiting )
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "STA 3 %d %lu %lu\r\n", (uint16_t) ((uint32_t)pxQueue & 0xffff), HAL_GetTick(), uxMessagesWaiting);
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceQUEUE_RECEIVE_FROM_ISR( void *pxQueue, uint32_t uxMessagesWaiting )
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "STO 3 %d %lu %lu\r\n", (uint16_t) ((uint32_t)pxQueue & 0xffff), HAL_GetTick(), uxMessagesWaiting );
	taskEXIT_CRITICAL_FROM_ISR( state );
}


/* Implementations of SEMAPHORE and MUTEX MACROS */

/* Please note that the call of semaphore functions
 * 		xSemaphoreCreateCounting()
 * 		vSemaphoreCreateBinary()
 * 		xSemaphoreTake()
 * 		xSemaphoreGive()
 * use the tracing functions
 *      TimeDoctor_traceQUEUE_CREATE()
 *      TimeDoctor_traceQUEUE_CREATE()
 *      TimeDoctor_traceQUEUE_RECEIVE()
 *      TimeDoctor_traceQUEUE_SEND()
 * respectively to record tracing data.
 */

void TimeDoctor_traceTAKE_MUTEX_RECURSIVE( void *pxMutex )
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "STA 2 %d %lu\r\n", (uint16_t) ((uint32_t)pxMutex & 0xffff), HAL_GetTick() );
	taskEXIT_CRITICAL_FROM_ISR( state );
}

void TimeDoctor_traceGIVE_MUTEX_RECURSIVE( void *pxMutex  )
{
	if ( buffer_used > sizeof(buffer)-64 )
		return; // buffer full, do not write

	BaseType_t state = taskENTER_CRITICAL_FROM_ISR();
	buffer_used += sprintf( buffer+buffer_used, "STO 2 %d %lu\r\n", (uint16_t) ((uint32_t)pxMutex & 0xffff), HAL_GetTick() );
	taskEXIT_CRITICAL_FROM_ISR( state );
}
