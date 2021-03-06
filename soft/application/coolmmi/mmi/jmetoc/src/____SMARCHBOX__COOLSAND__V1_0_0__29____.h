/*
 * @(#)____SMARCHBOX__COOLSAND__V1_0_0__29____.h 0.100 2009-11-20
 *
 * Copyright 2007 Smarch.
 * All rights reserved.
 */

////////////////////////////////////////////////////// 运行时断点还原 模块 //////////////////////////////////////////////////////
void jmetoc_overflow_breakpoint() {
  asm("jal jmetoc_get_overflow_sp");
  asm("add $sp,$0,$2");
  asm("jal jmetoc_get_overflow_pc");
  asm("nop");
  asm("jr $2");
  asm("nop");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
