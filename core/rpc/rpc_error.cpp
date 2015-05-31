// rpc_error.cpp

#include "rpc_error.h"
#include "rpc_calls.h"


const std::string CRpcError::GetMsg()
{
  switch (error)
    {
    case OK:              return "OK";
    case TIMEOUT:         return "TIMEOUT";
    case WRITE_ERROR:     return "WRITE_ERROR";
    case READ_ERROR:      return "READ_ERROR";
    case READ_TIMEOUT:    return "READ_TIMEOUT";
    case MSG_UNKNOWN:     return "MSG_UNKNOWN";
    case WRONG_MSG_TYPE:  return "WRONG_MSG_TYPE";
    case WRONG_DATA_SIZE: return "WRONG_DATA_SIZE";
    case ATB_MSG:         return "ATB_MSG";
    case WRONG_CGRP:      return "WRONG_CGRP";
    case WRONG_CMD:       return "WRONG_CMD";
    case CMD_PAR_SIZE:    return "CMD_PAR_SIZE";
    case NO_DATA_MSG:     return "NO_DATA_MSG";
    case NO_CMD_MSG:      return "NO_CMD_MSG";
    case UNKNOWN_CMD:     return "UNKNOWN_CMD";
    case ETH_ERROR:       return "ETH_ERROR";
    case USB_ERROR:       return "USB_ERROR";
    case IF_INIT_ERROR:   return "IF_INIT_ERROR";
    case UNDEF:           return "UNDEF";
    default:              return "?";
    }
}


std::string CRpcError::What() {
  
  if (functionId >= 0) {
    std::string fname(CTestboard::rpc_cmdName[functionId]);
    std::string fname_pretty;
    rpc_TranslateCallName(fname, fname_pretty);
    return std::string(fname_pretty + "\nERROR: " + GetMsg());
  }
  else {
    return std::string("ERROR: " + GetMsg());
  }
}
