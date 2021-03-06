/***********************************************************************
 *
 * MODULE NAME:    rfcomm_test_gen.c
 * PROJECT CODE:   host side stack
 * DESCRIPTION:
 * MAINTAINER:     Dave Airlie
 * CREATION DATE: 
 *
 * SOURCE CONTROL: $Id: rftest_pdu_gen.c 1532 2010-08-23 05:47:34Z huazeng $
 *
 * LICENSE:
 *     This source code is copyright (c) 2000-2001 Parthus Technologies Inc.
 *     All rights reserved.
 *
 * REVISION HISTORY:
 *    02.Feb.2000 -   DA - first import
 *
 *
 * ISSUES:
 *
 ***********************************************************************/
#include "bt.h"
#include "papi.h"

#include "rftest_types.h"
#include "rftest_pdu_gen.h"

#define TEST_BUF_SIZE 10

struct st_l2cap_inst
{
  t_bdaddr bd_addr;
  prh_t_rfcomm_cid cid;  
  int initiator;
};

extern struct st_l2cap_inst *test_l2_inst;
//extern int rftest_enabled;

int rftest_sendua(void *conn_handle, prh_t_rfcomm_dlci dlci, u_int8 fbit, u_int8 cresp)
{
  t_DataBuf *frame;
  int ret;
  ret=RFCOMM_UNIT_GetWriteBuffer( TEST_BUF_SIZE, &frame);
  if (ret==BT_NOERROR)
    {
      prh_rftest_create_ua(frame, dlci, fbit, cresp);
      
      UNIT_STUB_Data_From_L2(conn_handle, frame);
      //      L2_Write( frame);
    }
  return 0;
}

int rftest_sendsabm(void *conn_handle, prh_t_rfcomm_dlci dlci, u_int8 fbit, u_int8 cresp)
{
  t_DataBuf *frame;
  int ret;
  ret=RFCOMM_UNIT_GetWriteBuffer( TEST_BUF_SIZE, &frame);
  if (ret==BT_NOERROR)
    {
      prh_rftest_create_sabm(frame, dlci, fbit, cresp);
      UNIT_STUB_Data_From_L2(conn_handle, frame);
      //L2_Write( frame);
    }
  return 0;
}

int rftest_senddisc(void *conn_handle, prh_t_rfcomm_dlci dlci, u_int8 fbit, u_int8 cresp)
{
  t_DataBuf *frame;
  int ret;
  ret=RFCOMM_UNIT_GetWriteBuffer( TEST_BUF_SIZE, &frame);
  if (ret==BT_NOERROR)
    {
      prh_rftest_create_disc(frame, dlci, fbit, cresp);
      UNIT_STUB_Data_From_L2(conn_handle, frame);

    }
  return 0;
}

int rftest_sendmsc_reply(void *conn_handle, prh_t_rfcomm_dlci dlci, u_int8 cresp, char *inframe)
{
  t_DataBuf *frame;
  int ret;  
  ret=RFCOMM_UNIT_GetWriteBuffer( 20, &frame);
  if (ret==BT_NOERROR)
    {
      frame->data[0]=PRH_RFCOMM_CC_TYPE_MSC | (cresp<<1) | PRH_RFCOMM_EA_BIT;
      frame->data[1]=PRH_RFCOMM_CC_MSC_SHORT_LEN << 1 | PRH_RFCOMM_EA_BIT;
      frame->data[2]=inframe[0];
      frame->data[3]=inframe[1];
      
      frame->dataLen=4;
      
      prh_rftest_create_uih(frame, 0,0, rftest_get_crbit(conn_handle));
      UNIT_STUB_Data_From_L2(conn_handle, frame);
      
    }
  return 0;
}

int rftest_sendmsc(void *conn_handle, prh_t_rfcomm_dlci dlci, u_int8 cresp, prh_t_rfcomm_control_params *ctrl_params)
{
  t_DataBuf *frame;
  int ret;  
  ret=RFCOMM_UNIT_GetWriteBuffer( 20, &frame);
  if (ret==BT_NOERROR)
    {
      prh_rftest_cc_create_msc(frame, cresp, dlci, ctrl_params);
      prh_rftest_create_uih(frame, 0, 0, rftest_get_crbit(conn_handle));
      UNIT_STUB_Data_From_L2(conn_handle, frame);
    }
  return 0;
}

int rftest_sendtest(void *conn_handle, int cresp)
{
  t_DataBuf *frame;
  int x;
  int ret;
  ret=RFCOMM_UNIT_GetWriteBuffer( 20, &frame);
  if (ret==BT_NOERROR)
    {
      for (x=0; x<10; x++)
	frame->data[x]=x+'A';
      
      frame->dataLen=10;
      prh_rftest_cc_create_test(frame, cresp);
      prh_rftest_create_uih(frame, 0, 0, rftest_get_crbit(conn_handle));
      UNIT_STUB_Data_From_L2(conn_handle, frame);
    }
  return 0;
}

int rftest_sendrls(void *conn_handle, prh_t_rfcomm_dlci dlci, u_int8 cresp, prh_t_rfcomm_line_stat_params lsp)
{
  t_DataBuf *frame;
  int ret;
  ret=RFCOMM_UNIT_GetWriteBuffer( 20, &frame);
  if (ret==BT_NOERROR)
    {
      prh_rftest_cc_create_rls(frame, cresp, dlci, lsp);
      prh_rftest_create_uih(frame, 0,0 ,rftest_get_crbit(conn_handle));
      UNIT_STUB_Data_From_L2(conn_handle, frame);
    }
  return 0;
}


int rftest_sendpn(void *conn_handle, prh_t_rfcomm_dlci dlci, u_int8 cresp, u_int16 max_frame_size)
{
  t_DataBuf *frame;
  prh_t_rfcomm_dlc_params dlc_params;
  int ret;
  ret=RFCOMM_UNIT_GetWriteBuffer( 20, &frame);
  if (ret==BT_NOERROR)
    {
      dlc_params.max_frame_size=max_frame_size;
      dlc_params.priority=0;

      prh_rftest_cc_create_pn(frame, cresp, dlci, &dlc_params);
      prh_rftest_create_uih(frame, 0,0,rftest_get_crbit(conn_handle));
      UNIT_STUB_Data_From_L2(conn_handle, frame);
    }
  return 0;
}

int rftest_sendrpnc(void *conn_handle, prh_t_rfcomm_dlci dlci, u_int8 cresp, prh_t_rfcomm_port_params *port_params)
{
  t_DataBuf *frame;
  int ret;
 ret=RFCOMM_UNIT_GetWriteBuffer( 50, &frame);
  if (ret==BT_NOERROR)
    {
      
      prh_rftest_cc_create_rpn_comm(frame, cresp, dlci, port_params);
      prh_rftest_create_uih(frame, 0,0,rftest_get_crbit(conn_handle));
      UNIT_STUB_Data_From_L2(conn_handle, frame);
    }
  return 0;
}

int rftest_sendrpnr(void *conn_handle, prh_t_rfcomm_dlci dlci, u_int8 cresp)
{
  t_DataBuf *frame;
  int ret;
  ret=RFCOMM_UNIT_GetWriteBuffer(50, &frame);
  if (ret==BT_NOERROR)
    {
      
      prh_rftest_cc_create_rpn_req(frame, cresp, dlci);
      prh_rftest_create_uih(frame, 0,0,rftest_get_crbit(conn_handle));
      UNIT_STUB_Data_From_L2(conn_handle, frame);
    }
  return 0;
}

int rftest_send_fcon(void *conn_handle, int cresp)
{
 t_DataBuf *frame;
  int ret;

 ret=RFCOMM_UNIT_GetWriteBuffer( 50, &frame);
  if (ret==BT_NOERROR)
    {
      prh_rftest_cc_create_fcon(frame,cresp);
      prh_rftest_create_uih(frame, 0,0,rftest_get_crbit(conn_handle));
      UNIT_STUB_Data_From_L2(conn_handle, frame);

    }
  return 0;
}

int rftest_send_fcoff(void *conn_handle, int cresp)
{
 t_DataBuf *frame;
  int ret;
 
 ret=RFCOMM_UNIT_GetWriteBuffer( 50, &frame);
  if (ret==BT_NOERROR)
    {
      prh_rftest_cc_create_fcoff(frame,cresp);
      prh_rftest_create_uih(frame, 0,0,rftest_get_crbit(conn_handle));
      UNIT_STUB_Data_From_L2(conn_handle, frame);

    }
  return 0;
}

extern t_pEvent test_ua_event;

void rftest_l2cap_data_ind_cb(u_int16 cid, t_DataBuf *p_buf)
{
  int ret=0;
  prh_t_rfcomm_dlci dlci=0;
  int type;
  int pfbit;
  if ((p_buf->data[PRH_RFCOMM_FR_CTRL_FIELD] & ~PRH_RFCOMM_FR_CTRL_PF_BIT)==PRH_RFCOMM_FR_CTRL_UIH)
    ret=prh_rftest_rx_fcs(p_buf, 2);
  else
    ret=prh_rftest_rx_fcs(p_buf, 3);
  
  if (ret==0)
    {
      
      dlci=(p_buf->data[PRH_RFCOMM_FR_ADDR_FIELD]&0xFC) >> 2;
      type=p_buf->data[PRH_RFCOMM_FR_CTRL_FIELD] & ~PRH_RFCOMM_FR_CTRL_PF_BIT;
      pfbit=(p_buf->data[PRH_RFCOMM_FR_CTRL_FIELD] & PRH_RFCOMM_FR_CTRL_PF_BIT)>>4;
      /* check whether data is an SABM,DISC, UA, DM etc... */
      switch(type)
    {
    case PRH_RFCOMM_FR_CTRL_SABM:
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got SABM %d\n", dlci));
      rftest_gotpdu(p_buf, PRH_RFTEST_PDU_COMMAND);
      break;
    case PRH_RFCOMM_FR_CTRL_UA:
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got UA DLCI: %d, Fbit: %d\n",dlci, pfbit));
      rftest_gotpdu(p_buf, PRH_RFTEST_PDU_COMMAND);
      break;
    case PRH_RFCOMM_FR_CTRL_DM:
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got DM %d\n",dlci));
      rftest_gotpdu(p_buf, PRH_RFTEST_PDU_COMMAND);
      break;
    case PRH_RFCOMM_FR_CTRL_DISC: 
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got DISC DLCI: %d, pbit: %d\n",dlci, pfbit));
      rftest_gotpdu(p_buf, PRH_RFTEST_PDU_COMMAND);
      break;
    case PRH_RFCOMM_FR_CTRL_UIH:
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got UIH %d\n",dlci));
      rftest_handle_uih(p_buf, dlci);
      //      rfcomm_dlc_do_event(instance, PRH_RFCOMM_DLC_UIH, info);
      break;
    default:
      /* Unknown data type .. uggh */
      break;
    }
    }

}

int rftest_handle_uih(t_DataBuf *buffer, prh_t_rfcomm_dlci dlci)
{
  int type;
  int cr_recv;
  int len;
  int dlci_recv;

  if (buffer->data[PRH_RFCOMM_FR_LENGTH_FIELD1] & PRH_RFCOMM_EA_BIT)
    {
      /* length field is single byte */
      len = buffer->data[PRH_RFCOMM_FR_LENGTH_FIELD1] >> 1;
      rftest_data_buf_reserve_header(buffer, 3);
    }
  else
    {
      /* length field is two bytes */
      len = (buffer->data[PRH_RFCOMM_FR_LENGTH_FIELD1] >> 1) + (buffer->data[PRH_RFCOMM_FR_LENGTH_FIELD2] << 7);
      rftest_data_buf_reserve_header(buffer,4);
    }
  
  if (dlci==0)
    {
      type=buffer->data[PRH_RFCOMM_CC_TYPE_FIELD] & 0xFC;
      /* get the Command/Response bit from received command */
      cr_recv=(buffer->data[PRH_RFCOMM_CC_TYPE_FIELD] & 2) >> 1;
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got Control %d\n", type));
      switch(type)
    {
    case PRH_RFCOMM_CC_TYPE_PN:
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got PN\n"));
      rftest_gotpdu(buffer, PRH_RFTEST_PDU_DLCI0);      
      break;
    case PRH_RFCOMM_CC_TYPE_TEST:      
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got Test\n"));
      rftest_gotpdu(buffer, PRH_RFTEST_PDU_DLCI0);      
      //      prh_rfcomm_cc_process_test(self_inst,buffer);
      break;
    case PRH_RFCOMM_CC_TYPE_FCON:
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got FCON\n"));
      rftest_gotpdu(buffer, PRH_RFTEST_PDU_DLCI0);      	
      //      prh_rfcomm_cc_process_fcon(self_inst, buffer);
      break;    
    case PRH_RFCOMM_CC_TYPE_FCOFF:
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got FCOFF\n"));
      rftest_gotpdu(buffer, PRH_RFTEST_PDU_DLCI0);      	
      //      prh_rfcomm_cc_process_fcoff(self_inst, buffer);
      break;
    case PRH_RFCOMM_CC_TYPE_MSC:
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got MSC\n"));
#if 0
      if (cr_recv)
        {
          rftest_sendmsc_reply(dlci, 0, &buffer->data[2]);
        }
      else
#endif
	rftest_gotpdu(buffer, PRH_RFTEST_PDU_DLCI0);      	
      //      prh_rfcomm_cc_process_msc(self_inst, buffer);
      break;
    case PRH_RFCOMM_CC_TYPE_NSC:
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got NSC\n"));
      /* If I got a NSC what do I do? */
      break;
    case PRH_RFCOMM_CC_TYPE_RPN:

      pDebugPrintf((pLOGNOTICE, "RFTEST: Got RPN\n"));
      rftest_gotpdu(buffer, PRH_RFTEST_PDU_DLCI0);
      //      prh_rfcomm_cc_process_rpn(self_inst, buffer);
      break;
    case PRH_RFCOMM_CC_TYPE_RLS:
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got RLS\n"));
      rftest_gotpdu(buffer, PRH_RFTEST_PDU_DLCI0);
      //      prh_rfcomm_cc_process_rls(self_inst, buffer);
      break;
    default:
      /* transmit back an NSC */
      break;
    }
    }
  else
    {
      pDebugPrintf((pLOGNOTICE, "RFTEST: Got Data on dlci\n",dlci));
    }
    
  return BT_NOERROR;
  
}

