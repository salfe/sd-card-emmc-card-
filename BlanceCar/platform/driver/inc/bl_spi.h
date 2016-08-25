#ifndef __BL_SPI_H__
#define __BL_SPI_H__

#include "common.h"

/**********************************************************************************************************************
 * Definitions
 *********************************************************************************************************************/

typedef enum _host_request_selection
{
    kLPSPI_HostRequestIsLPSPIHREQ = 0U,
    kLPSPI_HostRequestIsInputTrigger = 1U,
} host_requrst_selection_t;
 
typedef enum _cps_negated_ouput_status
{
    kLPSPI_RetainLastValue = 0U,
    kLPSPI_IsTristated = 1U,
} cps_negated_ouput_status_t;
 
typedef enum _pin_config_mode
{
    kLPSPI_SINAsInputSOUTAsOutput = 0U,     /*!< SIN is used for input data and SOUT for output data. */
    kLPSPI_SINAsInputAndOutput = 1U,        /*!< SIN is used for both input and output data. */
    kLPSPI_SOUTAsInputAndOutput = 2U,       /*!< SOUT is used for both input and output data. */
    kLPSPI_SOUTAsInputSINAsOutput = 3U;     /*!< SOUT is used for input data and SIN for output data. */
} pin_config_mode_t;
 
typedef enum _peripheral_Chip_Polarity_selection
{
     kPLSPI_PCSxIsActiveLow = 0U,           /*!< The PCSx is active low. */
     kLPSPI_PCSxIsActiveHigh = 1U,          /*!< The PCSx is active high. */
} peripheral_Chip_Polarity_selection_t;

typedef enum _host_request_polarity_slelction
{
      
} host_request_polarity_slelction_t;

typedef enum _lpspi_match_config
{
    kLPSPI_Matchdisabled = 0U,
    kLPSPI_Matchmode1 = 2U,   /*!< 1st data word equals MATCH0 OR MATCH1. */
    kLPSPI_Matchmode2 = 3U,   /*!< any data word equals MATCH0 OR MATCH1. */
    kLPSPI_Matchmode3 = 4U,   /*!< 1st data word equals MATCH0 AND 2nd data word equals MATCH1. */
    kLPSPI_Matchmode4 = 5U,   /*!< any data word equals MATCH0 AND next data word equals MATCH1. */
    kLPSPI_Matchmode5 = 6U,   /*!< 1st data word AND MATCH1 equals MATCH0 AND MATCH1. */
    kLPSPI_Matchmode6 = 7U,   /*!< any data word AND MATCH1 equals MATCH0 AND MATCH1. */
} lpspi_match_config_t;
 
typedef struct _lpspi_config
{
    bool enableDebugMode;
    bool enableDozeMode;
    bool enableCircularFIFOMode;
    bool enable4BitTransfers;
    cps_negated_ouput_status_t ouputStatus;
    pin_config_mode_t pinConfig;
    peripheral_Chip_Polarity_selection_t PSCPolarity;
    bool enableStall;
    bool enableAutomaticPCS;
} lpspi_config_t;
 
typedef struct _lpspi_match_config
{
    bool enableMatchMode;
    lpspi_match_config_t matchMode;
    uint32_t matchValue0;
    uint32_t matchValue1;
}
 
typedef struct _lpspi_master_config
{
    
    host_requrst_selection_t requestSelection;
} lpspi_master_config_t;
 
 /**********************************************************************************************************************
 * API
 *********************************************************************************************************************/
void LPSPI_Init(LPSPI_Type *base, lpspi_config_t *config);
 
void LPSPI_SetMatchConfig(LPSPI_Type *base, lpspi_match_config_t *config);
 
void LPSPI_SetMasterConfig(LPSPI_Type *base, lpspi_master_config_t *config);
 
#endif/* __BL_SPI_H__ */