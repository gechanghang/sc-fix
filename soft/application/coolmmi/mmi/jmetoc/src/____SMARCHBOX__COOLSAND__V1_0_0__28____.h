/*
 * @(#)____SMARCHBOX__COOLSAND__V1_0_0__28____.h 0.100 2009-11-20
 *
 * Copyright 2007 Smarch.
 * All rights reserved.
 */

////////////////////////////////////////////////////// 运行时指针保护 模块 //////////////////////////////////////////////////////
  asm("beq $0,$0,$getpc");
  asm("nop");
asm("$savepc:");
  asm("lui $2,%hi(jmetoc_dy_pc)");
  asm("add $3,$0,$31");
  asm("sw $3,%lo(jmetoc_dy_pc)($2)");
  asm("nop");
  asm("jr $31");
  asm("nop");
asm("$getpc:");
  asm("jal $savepc");
  asm("nop");
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
