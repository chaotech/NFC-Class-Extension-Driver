/*
*          Modifications Copyright (c) Microsoft. All rights reserved.
*
*              Original code Copyright (c), NXP Semiconductors
*/

#pragma once

#define PHHCINFC_MAX_OPENPIPE                   0x6FU
#define PHHCINFC_MAX_PIPE                       0x6FU

#define PHHCINFC_MIN_PIPE                       0x02U
#define PHHCI_MIN_HCI_PACKET_PAYLOAD            0x02U

#define PHHCI_HCP_MSG_TYPE_OFFSET               0x06U
#define PHHCI_HCP_MSG_TYPE_LEN                  0x02U

#define PHHCINFC_MAX_CMD_REGS                   (6U)
#define PHHCINFC_MAX_RSP_REGS                   (6U)
#define PHHCINFC_MAX_EVT_REGS                   (6U)

#define PHHCINFC_APDU_PIPE_INDEX                0x01
#define PHHCINFC_APDU_GATE_ATR_REG_ID           0x01
#define PHHCINFC_APDU_GATE_ATR_LEN              (25U)

#define PHHCINFC_HCI_INDEX_ATR_TB1              0x03U

#define PHHCINFC_DEFAULT_HCI_TX_RX_TIME_OUT                 5000U /* 5 Secs*/
#define PHHCINFC_FIRST_TIME_HCI_NWK_FORMATION_TIME_OUT      2000U /* 2 Secs*/
#define PHHCINFC_HCI_NWK_FORMATION_TIME_OUT                 500U /* 0.5 Secs*/

#define PHHCINFC_HCI_NWK_INIT_RETRY_COUNT           1

#define PHHCINFC_HCI_CONNECTIVITY_GATE_PIPE_ID      0x16
#define PHHCINFC_HCI_APDU_GATE_PIPE_ID              0x19

#define PHHCINFC_HCI_CONN_GATE_PIPE_ID_INDEX        0x2
#define PHHCINFC_HCI_APDU_GATE_PIPE_ID_INDEX        0x1

#define PHHCINFC_HCI_MAX_NO_OF_HOSTS                0x2

typedef enum phHciNfc_Status
{
    phHciNfc_e_NfcstatusHciGateNotSupported     = 0x71u,
    phHciNfc_e_NfcstatusHciInvalidCommand       = 0x72u,
    phHciNfc_e_NfcstatusHciCommandNotSupported  = 0x73u,
    phHciNfc_e_NfcstatusHciInvalidResponse      = 0x74u,
    phHciNfc_e_NfcstatusHciInvalidInstruction   = 0x75u,
    phHciNfc_e_NfcstatusHciInvalidSequence      = 0x78u,
    phHciNfc_e_NfcstatusHciInvalidPipeid        = 0x80u,
    phHciNfc_e_NfcstatusHciUnknownResponse      = 0x81u,
    phHciNfc_e_NfcstatusHciInvalidMsgType       = 0x82u
} phHciNfc_Status_t;

typedef enum phHciNfc_MsgType
{
    phHciNfc_e_HcpMsgTypeCommand        = 0x00u,
    phHciNfc_e_HcpMsgTypeEvent          = 0x01u,
    phHciNfc_e_HcpMsgTypeResponse       = 0x02u,
    phHciNfc_e_HcpMsgTypeReserved       = 0x03u
} phHciNfc_MsgType_t;

typedef enum phHciNfc_GenCmdType
{
    phHciNfc_e_AnySetParameter           = 0x01u,
    phHciNfc_e_AnyGetParameter           = 0x02u,
    phHciNfc_e_AnyOpenPipe               = 0x03u,
    phHciNfc_e_AnyClosePipe              = 0x04u,
    phHciNfc_e_AnyHciMaxGenCmd           = 0x05
} phHciNfc_GenCmdType_t;

typedef enum phHciNfc_AdmCmdType
{
    phHciNfc_e_AdmCreatePipe             = 0x10u,
    phHciNfc_e_AdmDeletePipe             = 0x11u,
    phHciNfc_e_AdmNotifyPipeCreated      = 0x12u,
    phHciNfc_e_AdmNotifyPipeDeleted      = 0x13u,
    phHciNfc_e_AdmClearAllPipe           = 0x14u,
    phHciNfc_e_AdmNotifyAllPipeCleared   = 0x15u,
    phHciNfc_e_AnyHciMaxAdmCmd           = 0x16u
} phHciNfc_AdmCmdType_t;

typedef enum phHciNfc_PropCmdType
{
    phHciNfc_e_AnyHciPropCmdStart       = 0x10u,
    phHciNfc_e_AnyHciPropCmdEnd         = 0x3fu
} phHciNfc_PropCmdType_t;

typedef enum phHciNfc_RspType
{
    phHciNfc_e_RspAnyOk                   = 0x00u,
    phHciNfc_e_RspAnyENotConnected        = 0x01u,
    phHciNfc_e_RspAnyECmdParUnknown       = 0x02u,
    phHciNfc_e_RspAnyENok                 = 0x03u,
    phHciNfc_e_RspAnyEPipesFull           = 0x04u,
    phHciNfc_e_RspAnyERegParUnknown       = 0x05u,
    phHciNfc_e_RspAnyEPipeNotOpened       = 0x06u,
    phHciNfc_e_RspAnyECmdNotSupported     = 0x07u,
    phHciNfc_e_RspAnyEInhibited           = 0x08u,
    phHciNfc_e_RspAnyETimeout             = 0x09u,
    phHciNfc_e_RspAnyERegAccessDenied     = 0x0au,
    phHciNfc_e_RspAnyEPipeAccessDenied    = 0x0bu
} phHciNfc_RspType_t;

typedef enum phHciNfc_EvtType
{
    phHciNfc_e_EvtHciEndOfOperation      = 0x01,
    phHciNfc_e_EvtPostData               = 0x02,
    phHciNfc_e_EvtHotPlug                = 0x03,
    phHciNfc_e_EvtTxData                 = 0x10,
    phHciNfc_e_PropEvtWtxReq             = 0x11
} phHciNfc_EvtType_t;

typedef NFCSTATUS (*pphHciNfc_PipeReceiveCb_t) (
                                                  void *phNciNfcContext,
                                                  void *pReceiveParams
                                                );

typedef enum phHciNfc_HostID
{
    phHciNfc_e_HostControllerID                   = 0x00U,
    phHciNfc_e_TerminalHostID                     = 0x01U,
    phHciNfc_e_UICCHostID                         = 0x02U,
    phHciNfc_e_SEHostID                           = 0xC0U

} phHciNfc_HostID_t;

typedef enum phHciNfc_GateID{
    phHciNfc_e_LoopBackGate                       = 0x04U,
    phHciNfc_e_ConnectivityGate                   = 0x41U,
    phHciNfc_e_ApduGate                           = 0xF0U
} phHciNfc_GateID_t;

typedef enum phHciNfc_PipeID
{
    phHciNfc_e_HciLinkmgmtPipeId                = 0x00u,
    phHciNfc_e_HciAdminPipeId                   = 0x01u
} phHciNfc_PipeID_t;

typedef struct phHciNfc_GateInfo
{
    /**< HCI Host Identifier  */
    uint8_t     bHostId;
    /**< HCI Gate Identifier  */
    uint8_t     bGateId;
} phHciNfc_GateInfo_t;

typedef struct phHciNfc_PipeInfo
{
    /**< HCI Source Gate Information for the pipe  */
    phHciNfc_GateInfo_t    tSourceGateInfo;
    /**< HCI Destination Gate Information for the pipe  */
    phHciNfc_GateInfo_t    tDestgateInfo;
    /**< HCI Pipe Identifier  */
    uint8_t                bPipeId;
} phHciNfc_PipeInfo_t;

typedef struct phHciNfc_PipeContext
{
    /**< Structure containing the created dynamic pipe information */
    phHciNfc_PipeInfo_t           tPipeInfo;
    /**< Pointer to a Pipe specific Receive Response function */
    pphHciNfc_PipeReceiveCb_t    tPipeRcvRspCb;
    /**< Pointer to a Pipe specific Receive Event function */
    pphHciNfc_PipeReceiveCb_t    tPipeRcvEventCb;
    /**< Pointer to a Pipe specific Receive Command function */
    pphHciNfc_PipeReceiveCb_t    tPipeRcvCmdCb;
} phHciNfc_PipeContext_t;

typedef struct phHciNfc_PipeGateInfo
{
    /**< HCI Pipe Identifier  */
    uint8_t bPipeId;
    /**< HCI Pipe Type Identifier  */
    uint8_t bGateId;
}phHciNfc_PipeGateInfo_t;

typedef void(*pphHciNfc_RspCb_t) (void *pContext, NFCSTATUS Status, void *pinfo);

typedef struct phHciNfc_CB_Info
{
    /* Hci call back & its context */
    pphHciNfc_RspCb_t       pClientInitCb;
    void                    *pClientCntx;
}phHciNfc_CB_Info_t;

typedef struct phHciNfc_TimerInfo
{
    uint32_t dwRspTimerId;      /**< HCI Timer Id */
    uint8_t  dwTimerStatus;     /**< Status of Timer*/
    uint32_t dwTimeOut;         /**< Timeout in Milliseconds*/
}phHciNfc_TimerInfo_t;

typedef struct phHciNfc_RegInfo
{
    uint8_t bEnabled;            /**< 0 - entry free; 1 - entry not available */
    uint8_t bPipeId;             /**< Group ID */
    void    *pContext;           /**< Upper layer context */
    pphHciNfc_RspCb_t pNotifyCb; /**< Function to be invoked upon response or notification */
}phHciNfc_RegInfo_t, *pphHciNfc_RegInfo_t; /**< pointer to #phHciNfc_RegInfo_t */

typedef struct phHciNfc_HciContext
{
    /**< HCI Core Context */
    phHciNfc_HciCoreContext_t        pHciCoreContext;
    /**< HCI command parameters */
    phHciNfc_SendParams_t            *pSendParams;
    /**< HCI Upper Layer Call back info */
    phHciNfc_CB_Info_t               Cb_Info;
    /**< HCI command receive Call back info */
    phHciNfc_CB_Info_t               SendCb_Info;
    /**< HCI command Reg List */
    phHciNfc_RegInfo_t               aHciCmdRegList[PHHCINFC_MAX_CMD_REGS];
    /**< HCI response Reg List */
    phHciNfc_RegInfo_t               aHciRspRegList[PHHCINFC_MAX_RSP_REGS];
    /**< HCI Event Reg List */
    phHciNfc_RegInfo_t               aHciEvtRegList[PHHCINFC_MAX_EVT_REGS];
    void                             *pNciContext;
    void                             *pSeHandle;
    uint8_t                          aGetHciSessionId[8];
    phHciNfc_PipeGateInfo_t          aSEPipeList[3];
    phHciNfc_PipeGateInfo_t          aUICCPipeList[1];
    phHciNfc_TimerInfo_t             tHciSeTxRxTimerInfo;
    uint8_t                          aHostList[PHHCINFC_HCI_MAX_NO_OF_HOSTS];
    uint8_t                          bNoOfHosts;
    uint8_t                          bClearpipes;
    uint8_t                          bCreatePipe;
} phHciNfc_HciContext_t,*pphHciNfc_HciContext_t;

extern phHciNfc_HciContext_t volatile *gppHciContext;

typedef struct phHciNfc_AnySetParams
{
    /* index of the parameter in the registry */
    uint8_t     bRegIndex;
    /* Length of the parameter in the registry */
    uint8_t     bLenOfParam;
    /*Value of the parameter*/
    uint8_t     *pData;
} phHciNfc_AnySetParams_t;

typedef struct phHciNfc_AnyGetParams
{
    /* index of the parameter in the registry */
    uint8_t     bRegIndex;
} phHciNfc_AnyGetParams_t;

typedef struct phHciNfc_AdmCreatePipeCmdParams
{
    uint8_t     bSourceGID;
    uint8_t     bDestHID;
    uint8_t     bDestGID;
} phHciNfc_AdmCreatePipeCmdParams_t;

typedef struct phHciNfc_AdmCreatePipeRspParams
{
    uint8_t     bSourceHID;
    uint8_t     bSourceGID;
    uint8_t     bDestHID;
    uint8_t     bDestGID;
    uint8_t     bPipeID;
} phHciNfc_AdmCreatePipeRspParams_t;

typedef struct phHciNfc_AdmDelPipeCmdParams
{
    uint8_t     bPipeID;
} phHciNfc_AdmDelPipeCmdParams_t;

typedef struct phHciNfc_AdmNotfDelPipeCmdParams
{
    uint8_t     bPipeID;
} phHciNfc_AdmNotfDelPipeCmdParams_t;

typedef struct phHciNfc_AdmClrAllPipeCmdParams
{
    /* Identity reference data */
    uint16_t     wRefData;
} phHciNfc_AdmClrAllPipeCmdParams_t;

typedef struct phHciNfc_AdmNtfClrAllPipeCmdParams
{
    /* HID of requesting host */
    uint8_t     bSourceHID;
} phHciNfc_AdmNtfClrAllPipeCmdParams_t;

typedef struct phHciNfc_EventPostDataParams
{
    /* Length of Data */
    uint32_t     dwLenOfData;
    uint8_t      *pData;
} phHciNfc_EventPostDataParams_t;

typedef struct phHciNfc_AnyOkParams
{
    /* Length of Data */
    uint32_t     dwLenOfData;
    uint8_t      *pData;
} phHciNfc_AnyOkParams_t;
