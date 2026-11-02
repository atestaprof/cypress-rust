void __cdecl FUN_0040f8e0(int param_1,undefined **param_2)

{
  undefined **ppuVar1;
  byte *pbVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  short *psVar8;
  int *piVar9;
  undefined **ppuVar10;
  char *pcVar11;
  void *this;
  uint uVar12;
  uint uVar13;
  void *this_00;
  uint extraout_ECX;
  uint *puVar14;
  uint uVar15;
  char cVar16;
  char cVar17;
  char cVar18;
  int *unaff_EBX;
  int *unaff_ESI;
  int *unaff_EDI;
  char *pcVar19;
  undefined **ppuVar20;
  uint *puVar21;
  bool bVar22;
  byte bVar23;
  undefined8 uVar24;
  byte in_stack_007e0045;
  int *in_stack_ffffffa4;
  int *in_stack_ffffffa8;
  int in_stack_ffffffac;
  uint local_44;
  uint *local_40;
  undefined8 local_3c;
  uint local_34;
  short *local_30;
  int local_2c;
  uint *local_28;
  int local_24;
  undefined **local_20;
  int local_1c;
  int *local_18;
  undefined *local_14;
  uint local_10;
  short *local_c;
  uint *local_8;
  
  pbVar2 = (byte *)FUN_00420199((uchar *)s_ESPTIMEOUT_0042fe34);
  if ((pbVar2 != (byte *)0x0) && (iVar3 = FUN_0041f45f(this,pbVar2), 0 < iVar3)) {
    DAT_0042fbb0 = iVar3 * 1000;
  }
  local_40 = (uint *)FUN_0041b360();
  local_28 = (uint *)0x0;
  FUN_004110a0();
  local_1c = 0;
  local_10 = 1;
  DAT_00435400 = 0;
  DAT_00435570 = 0;
  DAT_004354c4 = (uint *)0x1;
  DAT_004353d0 = 0;
  DAT_00435408 = 0;
  local_c = (short *)0x0;
  local_20 = (undefined **)0xffffffff;
  local_14 = (undefined *)0xffffffff;
  DAT_004354c8 = 1;
  DAT_0043556c = 1;
  DAT_00435370 = 1;
  DAT_00435574 = 0;
  DAT_00435410 = 0;
  DAT_00435460 = 0;
  DAT_004353cc = 0;
  DAT_00435404 = 0;
  DAT_004353fc = 0;
  DAT_0043540c = 1;
  DAT_00435464 = 1;
  local_30 = (short *)0x0;
  DAT_004330b4 = FUN_0040a880(1,0x5b);
  puVar4 = (uint *)s_MINOPT_EXE_01_NOV_1999__v4_02___0042fe40;
  puVar21 = DAT_004330b4;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar21 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar21 = puVar21 + 1;
  }
  *(undefined2 *)puVar21 = *(undefined2 *)puVar4;
  uVar12 = 0xffffffff;
  pcVar11 = PTR_s_6_3_IR_35_0042fba0;
  do {
    pcVar19 = pcVar11;
    if (uVar12 == 0) break;
    uVar12 = uVar12 - 1;
    pcVar19 = pcVar11 + 1;
    cVar16 = *pcVar11;
    pcVar11 = pcVar19;
  } while (cVar16 != '\0');
  uVar12 = ~uVar12;
  iVar3 = -1;
  puVar4 = DAT_004330b4;
  do {
    puVar21 = puVar4;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    puVar21 = (uint *)((int)puVar4 + 1);
    cVar16 = *(char *)puVar4;
    puVar4 = puVar21;
  } while (cVar16 != '\0');
  pcVar11 = pcVar19 + -uVar12;
  ppuVar20 = (undefined **)((int)puVar21 + -1);
  for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
    *ppuVar20 = *(undefined **)pcVar11;
    pcVar11 = pcVar11 + 4;
    ppuVar20 = ppuVar20 + 1;
  }
  for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(char *)ppuVar20 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    ppuVar20 = (undefined **)((int)ppuVar20 + 1);
  }
  if (param_1 < 3) {
    FUN_0040a9d0(s__MOCHA__RPT_0042fe68);
    FUN_00411230(unaff_EDI,unaff_ESI);
  }
  ppuVar10 = param_2;
  puVar4 = FUN_00411910(&param_1,param_2,(byte *)s__rr_esp_0042fe74,(uint *)0x0);
  if (puVar4 != (uint *)0x0) {
    DAT_0042fbac = FUN_0041f45f(this_00,(byte *)puVar4);
  }
  DAT_00435360 = (char *)FUN_00411910(&param_1,ppuVar10,&DAT_0042fe7c,(uint *)DAT_00435360);
  if ((uint *)DAT_00435360 == (uint *)0x0) {
    DAT_00435360 = s__MOCHA__RPT_0042fe84;
  }
  DAT_00435364 = (char *)FUN_00411910(&param_1,ppuVar10,&DAT_0042fe90,(uint *)DAT_00435364);
  if ((uint *)DAT_00435364 == (uint *)0x0) {
    DAT_00435364 = s__MOCHA__PLX_0042fe98;
  }
  FUN_0040a9d0(DAT_00435360);
  DAT_00435368 = (FILE *)FUN_0041ec37(DAT_00435364,&DAT_0042fea4);
  if (DAT_00435368 == (FILE *)0x0) {
    FUN_0040aa50(4,0x1e);
  }
  FUN_00411550(&param_1,(int *)ppuVar10,&local_1c);
  iVar3 = FUN_0040ceb0(param_1,(int)ppuVar10,s_D_S_de_o_r_stv_x_q_0042fea8);
  while (iVar3 != -1) {
    switch(iVar3) {
    case 0x44:
      iVar7 = 0;
      ppuVar10 = (undefined **)PTR_s_OPTIMIZE_0042f6d0;
      iVar3 = local_1c;
      if ((undefined **)PTR_s_OPTIMIZE_0042f6d0 != (undefined **)0x0) {
        ppuVar20 = &PTR_s_OPTIMIZE_0042f6d0;
        pbVar2 = DAT_0043559c;
LAB_0040fb33:
        do {
          bVar23 = *pbVar2;
          bVar22 = bVar23 < *(byte *)ppuVar10;
          if (bVar23 == *(byte *)ppuVar10) {
            if (bVar23 != 0) {
              bVar23 = pbVar2[1];
              bVar22 = bVar23 < *(byte *)((int)ppuVar10 + 1);
              if (bVar23 != *(byte *)((int)ppuVar10 + 1)) goto LAB_0040fb57;
              ppuVar10 = (undefined **)((int)ppuVar10 + 2);
              pbVar2 = pbVar2 + 2;
              if (bVar23 != 0) goto LAB_0040fb33;
            }
            iVar5 = 0;
          }
          else {
LAB_0040fb57:
            iVar5 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
          }
          iVar3 = iVar7;
          if (iVar5 == 0) break;
          ppuVar10 = (undefined **)ppuVar20[5];
          ppuVar20 = ppuVar20 + 5;
          iVar7 = iVar7 + 1;
          pbVar2 = DAT_0043559c;
          iVar3 = local_1c;
        } while (ppuVar10 != (undefined **)0x0);
      }
      local_1c = iVar3;
      if ((&PTR_s_OPTIMIZE_0042f6d0)[iVar7 * 5] == (undefined *)0x0) {
        FUN_0040aa50(4,0xc);
        FUN_0041ef48(1);
LAB_0040fe83:
        FUN_0040aa50(4,0xd);
        FUN_0041ef48(1);
LAB_0040fea1:
        FUN_0040aa50(4,0xe);
        FUN_0041ef48(1);
LAB_0040febe:
        FUN_0040aa50(4,0xf);
        FUN_0041ef48(1);
LAB_0040fedc:
        FUN_0040aa50(4,0x10);
        unaff_EBX = (int *)0x1;
        FUN_0041ef48(1);
        goto switchD_0040fb07_caseD_45;
      }
      break;
    default:
switchD_0040fb07_caseD_45:
      FUN_00411230(unaff_EBX,in_stack_ffffffa4);
      unaff_EBX = (int *)0x40ff05;
      FUN_0041ef48(0x40ff05);
      goto LAB_0040ff05;
    case 0x53:
      local_c = (short *)FUN_0041f45f(DAT_0043559c,DAT_0043559c);
      break;
    case 100:
      DAT_00435408 = 1;
      DAT_00435400 = DAT_0042fa84;
    case 0x73:
      DAT_004353d0 = 1;
      break;
    case 0x65:
      iVar3 = 0;
      ppuVar10 = (undefined **)PTR_DAT_0042fb08;
      if ((undefined **)PTR_DAT_0042fb08 != (undefined **)0x0) {
        ppuVar20 = &PTR_DAT_0042fb08;
        pbVar2 = DAT_0043559c;
LAB_0040fc17:
        do {
          bVar23 = *pbVar2;
          bVar22 = bVar23 < *(byte *)ppuVar10;
          if (bVar23 == *(byte *)ppuVar10) {
            if (bVar23 != 0) {
              bVar23 = pbVar2[1];
              bVar22 = bVar23 < *(byte *)((int)ppuVar10 + 1);
              if (bVar23 != *(byte *)((int)ppuVar10 + 1)) goto LAB_0040fc3b;
              ppuVar10 = (undefined **)((int)ppuVar10 + 2);
              pbVar2 = pbVar2 + 2;
              if (bVar23 != 0) goto LAB_0040fc17;
            }
            iVar7 = 0;
          }
          else {
LAB_0040fc3b:
            iVar7 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
          }
          if (iVar7 == 0) {
            *(undefined4 *)(&PTR_DAT_0042fb0c)[iVar3 * 3] = (&DAT_0042fb10)[iVar3 * 3];
            break;
          }
          ppuVar10 = (undefined **)ppuVar20[3];
          ppuVar20 = ppuVar20 + 3;
          iVar3 = iVar3 + 1;
          pbVar2 = DAT_0043559c;
        } while (ppuVar10 != (undefined **)0x0);
      }
      if ((&PTR_DAT_0042fb08)[iVar3 * 3] == (undefined *)0x0) goto LAB_0040fea1;
      break;
    case 0x6f:
      iVar3 = 0;
      if (PTR_DAT_0042ed08 != (undefined *)0x0) {
        ppuVar20 = &PTR_DAT_0042ed08;
        puVar6 = PTR_DAT_0042ed08;
        do {
          ppuVar10 = (undefined **)(puVar6 + 1);
          pbVar2 = DAT_0043559c;
          do {
            bVar23 = *pbVar2;
            bVar22 = bVar23 < *(byte *)ppuVar10;
            if (bVar23 != *(byte *)ppuVar10) {
LAB_0040fbc8:
              iVar7 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
              goto LAB_0040fbcd;
            }
            if (bVar23 == 0) break;
            bVar23 = pbVar2[1];
            bVar22 = bVar23 < *(byte *)((int)ppuVar10 + 1);
            if (bVar23 != *(byte *)((int)ppuVar10 + 1)) goto LAB_0040fbc8;
            pbVar2 = pbVar2 + 2;
            ppuVar10 = (undefined **)((int)ppuVar10 + 2);
          } while (bVar23 != 0);
          iVar7 = 0;
LAB_0040fbcd:
          if (iVar7 == 0) {
            local_10 = (&DAT_0042ed0c)[iVar3 * 2];
            break;
          }
          puVar6 = ppuVar20[2];
          ppuVar20 = ppuVar20 + 2;
          iVar3 = iVar3 + 1;
        } while (puVar6 != (undefined *)0x0);
      }
      if ((&PTR_DAT_0042ed08)[iVar3 * 2] == (undefined *)0x0) goto LAB_0040fe83;
      break;
    case 0x71:
      DAT_0042e060 = 0;
      break;
    case 0x72:
      iVar3 = FUN_0041f265((char *)DAT_0043559c,(byte *)s__d__d_0042febc);
      if (iVar3 < 2) goto LAB_0040fedc;
      break;
    case 0x74:
      DAT_00435408 = 1;
      break;
    case 0x76:
      iVar3 = 0;
      DAT_00435570 = 1;
      ppuVar10 = (undefined **)PTR_DAT_0042fa80;
      if ((undefined **)PTR_DAT_0042fa80 != (undefined **)0x0) {
        ppuVar20 = &PTR_DAT_0042fa80;
        pbVar2 = DAT_0043559c;
LAB_0040fcba:
        do {
          bVar23 = *pbVar2;
          bVar22 = bVar23 < *(byte *)ppuVar10;
          if (bVar23 == *(byte *)ppuVar10) {
            if (bVar23 != 0) {
              bVar23 = pbVar2[1];
              bVar22 = bVar23 < *(byte *)((int)ppuVar10 + 1);
              if (bVar23 != *(byte *)((int)ppuVar10 + 1)) goto LAB_0040fcde;
              ppuVar10 = (undefined **)((int)ppuVar10 + 2);
              pbVar2 = pbVar2 + 2;
              if (bVar23 != 0) goto LAB_0040fcba;
            }
            iVar7 = 0;
          }
          else {
LAB_0040fcde:
            iVar7 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
          }
          if (iVar7 == 0) {
            DAT_00435400 = DAT_00435400 | (&DAT_0042fa84)[iVar3 * 2];
            break;
          }
          ppuVar10 = (undefined **)ppuVar20[2];
          ppuVar20 = ppuVar20 + 2;
          iVar3 = iVar3 + 1;
          pbVar2 = DAT_0043559c;
        } while (ppuVar10 != (undefined **)0x0);
      }
      if ((&PTR_DAT_0042fa80)[iVar3 * 2] == (undefined *)0x0) goto LAB_0040febe;
      break;
    case 0x78:
      DAT_004354c4 = (uint *)0x0;
    }
    iVar3 = FUN_0040ceb0(param_1,(int)param_2,s_D_S_de_o_r_stv_x_q_0042fea8);
  }
  if ((DAT_004353d0 != 0) || (DAT_00435408 != 0)) {
    FUN_0041b470(&DAT_0042fec4);
    iVar3 = 0;
    ppuVar20 = param_2;
    if (0 < param_1) {
      do {
        FUN_0041b470(&DAT_0042fec8);
        iVar3 = iVar3 + 1;
        ppuVar10 = ppuVar20 + 1;
        ppuVar20 = ppuVar10;
      } while (iVar3 < param_1);
    }
    FUN_0041b470(&DAT_0042fecc);
    FUN_0041b470((byte *)s____s_0042ff0c);
  }
  FUN_0040aa50(2,3);
  FUN_0040a940();
  FUN_0040aa50(2,4);
  FUN_0040a950();
  FUN_0040aa50(2,0x11);
  FUN_0040aa50(2,7);
  ppuVar20 = (undefined **)0x0;
  if (PTR_DAT_0042fb08 != (undefined *)0x0) {
    ppuVar10 = &PTR_DAT_0042fb08;
    do {
      iVar3 = FUN_00407400(&DAT_0042ff14,*ppuVar10);
      if (iVar3 == 0) goto LAB_0040ff05;
      ppuVar1 = ppuVar10 + 3;
      ppuVar10 = ppuVar10 + 3;
      ppuVar20 = (undefined **)((int)ppuVar20 + 1);
    } while (*ppuVar1 != (undefined *)0x0);
  }
LAB_0040ff23:
  puVar4 = (uint *)0x1;
  puVar21 = (uint *)0x0;
  if (DAT_004330b8 != 0) {
    FUN_0040aa50(2,0x13);
  }
  local_18 = (int *)0x0;
  local_8 = (uint *)0x0;
  if (*(int *)(&DAT_0042f6d8 + local_1c * 0x14) == 1) {
    if (DAT_0043309c + 1 < param_1) {
      FUN_00408c40((int *)s_trailing_arguments_on_command_li_0042ff40,(uint)unaff_EBX);
    }
    iVar3 = DAT_0043309c;
    DAT_0043309c = DAT_0043309c + 1;
    FUN_00410ee0(iVar3,param_1,(int)param_2,local_1c,(int *)&local_8,local_10);
  }
  else if (*(int *)(&DAT_0042f6d8 + local_1c * 0x14) == 2) {
    if (DAT_0043309c + 2 < param_1) {
      FUN_00408c40((int *)s_trailing_arguments_on_command_li_0042ff1c,(uint)unaff_EBX);
    }
    ppuVar10 = param_2;
    iVar3 = DAT_0043309c;
    DAT_0043309c = DAT_0043309c + 1;
    FUN_00410ee0(iVar3,param_1,(int)param_2,local_1c,(int *)&local_8,local_10);
    iVar3 = DAT_0043309c;
    DAT_0043309c = DAT_0043309c + 1;
    FUN_00410ee0(iVar3,param_1,(int)ppuVar10,local_1c,(int *)&local_18,local_10);
  }
  if (DAT_0043309c < param_1) {
    FUN_00408c40((int *)s_trailing_arguments_on_command_li_0042ff64,(uint)unaff_EBX);
  }
  if ((DAT_004353d0 != 0) || (DAT_00435408 != 0)) {
    if (local_8 != (uint *)0x0) {
      FUN_00406d90((int *)local_8);
    }
    if (local_18 != (int *)0x0) {
      FUN_00406d90(local_18);
    }
  }
  ppuVar20 = DAT_00435534;
  piVar9 = local_18;
  switch(*(undefined4 *)(&DAT_0042f6d4 + local_1c * 0x14)) {
  case 0:
    do {
      DAT_004330c4 = FUN_0041b360();
      local_24 = 1;
      if (DAT_004330bc == 0) {
        iVar3 = __setjmp3((undefined4 *)&DAT_00435320,0,unaff_EBX,in_stack_ffffffa4);
        if (iVar3 == 0) {
          iVar3 = 1;
          if (DAT_004330bc == 0) {
            iVar3 = FUN_004073f0();
          }
          if (iVar3 == 0) {
            FUN_0041b200((int *)local_8);
            local_24 = 0;
            if (((int)local_c < 0) || (1 < (int)local_c)) {
              local_c = (short *)0x0;
            }
            FUN_00408490((int *)local_8,(int)local_c);
          }
          else if (iVar3 == 2) {
            FUN_0041b200((int *)local_8);
            local_24 = 0;
            if (((int)local_c < 0) || (1 < (int)local_c)) {
              local_c = (short *)0x0;
            }
            FUN_004084f0((int *)local_8,(int)local_c);
          }
        }
        else if (((DAT_004330bc == 0) && (local_24 == 0)) && (DAT_00435574 == 0)) {
          DAT_00435574 = 1;
          DAT_004330c4 = FUN_0041b360();
          iVar3 = __setjmp3((undefined4 *)&DAT_00435320,0,unaff_EBX,in_stack_ffffffa4);
          if (iVar3 == 0) {
            iVar3 = FUN_004073f0();
            if (iVar3 == 0) {
              if (((int)local_c < 0) || (1 < (int)local_c)) {
                local_c = (short *)0x0;
              }
              FUN_00408490((int *)local_8,(int)local_c);
            }
            else if (iVar3 == 2) {
              if (((int)local_c < 0) || (1 < (int)local_c)) {
                local_c = (short *)0x0;
              }
              FUN_004084f0((int *)local_8,(int)local_c);
            }
          }
          DAT_00435574 = 0;
        }
      }
      if (DAT_004354c4 != (uint *)0x0) {
        FUN_00408c60((int *)DAT_00435368,local_8,local_10);
        FUN_0041f0ff((int *)DAT_00435368);
      }
      local_34 = local_8[4];
      FUN_00406ff0(local_8);
      FUN_00405270();
      if (DAT_00435534 != (undefined **)0x0) {
        FUN_0041b8c0((int)DAT_00435534);
        DAT_00435534 = (undefined **)0x0;
      }
      DAT_00432d94 = 0;
      local_2c = 1;
      DAT_004330bc = 0;
      DAT_004330c4 = FUN_0041b360();
      iVar3 = __setjmp3((undefined4 *)&DAT_00435320,0,unaff_EBX,in_stack_ffffffa4);
      if (iVar3 == 0) {
        local_2c = FUN_00406a00(DAT_004330b0,1,1,local_34,&local_8);
      }
      else {
        DAT_004330bc = 1;
      }
    } while (local_2c != -1);
    if (DAT_00435368 != (FILE *)0x0) {
      FUN_0041ea29(DAT_00435368);
    }
    iVar3 = FUN_0040aa30();
    if (iVar3 == 0) {
      FUN_0040aa50(2,0xc);
    }
    FUN_0040aa50(3,(int)unaff_EBX);
    iVar3 = FUN_0040aa20();
    if (iVar3 == 0) {
      iVar3 = 5;
    }
    else {
      iVar3 = 6;
    }
    FUN_0040aa50(2,iVar3);
    FUN_0040aa10();
    return;
  case 1:
    ppuVar10 = (undefined **)FUN_00417a20(*local_8);
    puVar4 = FUN_0040ac70((uint *)*local_8,local_8[1],(short *)local_8[2]);
    *local_8 = (uint)puVar4;
    puVar21 = (uint *)FUN_0041b360();
    puVar4 = (uint *)FUN_0041ae90(*local_8,(int)ppuVar10,local_8[1]);
    local_28 = puVar4;
    FUN_00408bb0((int)puVar21,0xe,*local_8,(undefined4 *)&stack0xffffffa4);
    if (puVar4 != (uint *)0x0) {
      DAT_004354c4 = (uint *)0x0;
      *local_8 = (uint)ppuVar10;
      FUN_0041b200((int *)local_8);
      break;
    }
    goto LAB_0041065f;
  case 2:
    iVar3 = FUN_0041b360();
    iVar7 = FUN_0041afd0((int *)local_8,local_18);
    FUN_00408bb0(iVar3,0xe,*local_8,(undefined4 *)&stack0xffffffa4);
    if (iVar7 != 0) {
      FUN_0041b470((byte *)s_PLA_comparison_failed__the_PLA_s_0042ffd0);
      FUN_0041ef48(1);
    }
    FUN_0041b470((byte *)s_PLA_s_compared_equal_00430008);
    piVar9 = (int *)FUN_0041ef48(0);
  case 0x27:
    puVar4 = (uint *)*piVar9;
    uVar12 = *local_8;
    puVar21 = (uint *)local_8[1];
    local_34 = FUN_0041b360();
    ppuVar10 = (undefined **)FUN_0041ae90((int)puVar4,uVar12,(int)puVar21);
    FUN_00408bb0(local_34,0xe,*local_8,(undefined4 *)&stack0xffffffa4);
    if (ppuVar10 != (undefined **)0x0) {
      FUN_0041b470((byte *)s_PLA_comparison_failed__the_PLA_s_00430020);
      FUN_0041ef48(1);
    }
    FUN_0041b470((byte *)s_PLA_s_compared_equal_00430058);
    unaff_EBX = (int *)0x0;
    FUN_0041ef48(0);
switchD_00410077_caseD_3:
    FUN_0041b200((int *)local_8);
    DAT_004354c4 = puVar21;
    break;
  case 3:
    goto switchD_00410077_caseD_3;
  case 4:
    puVar14 = FUN_004044e0((short *)*local_8);
    *local_8 = (uint)puVar14;
    break;
  case 5:
    if (((int)local_20 < 0) || (DAT_00435524 <= (int)local_20)) {
      local_20 = (undefined **)0x0;
    }
    if (((int)local_14 < 0) || (DAT_00435524 <= (int)local_14)) {
      local_14 = (undefined *)(DAT_00435524 + -1);
    }
    ppuVar10 = local_20;
    if ((int)local_20 <= (int)local_14) {
      do {
        uVar12 = FUN_00404720((short *)*local_8,(int)ppuVar10);
        ppuVar10 = (undefined **)((int)ppuVar10 + 1);
        *local_8 = uVar12;
      } while ((int)ppuVar10 <= (int)local_14);
    }
    break;
  case 6:
    puVar14 = FUN_004196b0(*local_8);
    *local_8 = (uint)puVar14;
    break;
  case 7:
    puVar14 = FUN_00419700(*local_8,*local_18);
    *local_8 = (uint)puVar14;
    break;
  case 8:
    FUN_0040aa50(2,0x12);
    break;
  case 9:
    uVar12 = *local_8;
    puVar14 = *(uint **)(uVar12 + 0x18);
    puVar21 = puVar14 + *(int *)(uVar12 + 0x10) * *(int *)(uVar12 + 4);
    for (; puVar14 < puVar21; puVar14 = puVar14 + *(int *)(*local_8 + 4)) {
      *puVar14 = *puVar14 & 0xffffbfff | 0x400;
    }
    ppuVar10 = (undefined **)FUN_0041b360();
    puVar21 = FUN_0040b020(local_8,local_8 + 1);
    FUN_00408bb0((int)ppuVar10,3,*local_8,(undefined4 *)&stack0xffffffa4);
    FUN_00417a40((short *)puVar21);
    break;
  case 10:
    local_30 = (short *)0x1;
  case 0x1b:
    ppuVar10 = (undefined **)FUN_00417a20(*local_8);
    uVar12 = FUN_0040b380(*local_8,local_8[1],local_8[2],local_30);
    *local_8 = uVar12;
    puVar21 = (uint *)FUN_0041b360();
    puVar4 = (uint *)FUN_0041ae90(*local_8,(int)ppuVar10,local_8[1]);
    local_28 = puVar4;
    FUN_00408bb0((int)puVar21,0xe,*local_8,(undefined4 *)&stack0xffffffa4);
    if (puVar4 != (uint *)0x0) {
      DAT_004354c4 = (uint *)0x0;
      *local_8 = (uint)ppuVar10;
      FUN_0041b200((int *)local_8);
    }
LAB_0041065f:
    FUN_00417a40((short *)ppuVar10);
    break;
  case 0xb:
    ppuVar10 = (undefined **)FUN_0041b360();
    puVar14 = FUN_0040b8a0((short *)*local_8,local_8[2],0);
    *local_8 = (uint)puVar14;
    FUN_00408bb0((int)ppuVar10,4,*local_8,(undefined4 *)&stack0xffffffa4);
    break;
  case 0xc:
    uVar12 = FUN_0040cc50(*local_8,(short *)local_8[1],local_8[2],(undefined4 *)&stack0xffffffa4);
    *local_8 = uVar12;
    break;
  case 0xd:
    uVar12 = FUN_00419a60(*local_8,*local_18);
    *local_8 = uVar12;
    break;
  case 0xe:
    ppuVar10 = (undefined **)FUN_0041b360();
    uVar12 = FUN_0040e9b0((int *)*local_8,(short *)local_8[1]);
    *local_8 = uVar12;
    FUN_00408bb0((int)ppuVar10,5,*local_8,(undefined4 *)&stack0xffffffa4);
    break;
  case 0xf:
    puVar14 = FUN_00407cc0((short *)*local_8);
    *local_8 = (uint)puVar14;
    break;
  case 0x10:
    puVar14 = FUN_00419e50(*local_8,local_8[1],local_8[2]);
    *local_8 = (uint)puVar14;
    break;
  case 0x11:
    FUN_00411b30(*local_8);
    DAT_004354c4 = (uint *)0x0;
    break;
  case 0x12:
    FUN_0040d190((int *)local_8);
    local_10 = 3;
    break;
  case 0x13:
    local_3c = (double)((ulonglong)local_3c & 0xffffffff);
    FUN_00401920(*local_8,(uint *)((int)&local_3c + 4));
    FUN_0041b470((byte *)s_Euler_Poincaire_Characteristic_M_00430070);
    break;
  case 0x14:
    uVar12 = FUN_00401d00(*local_8,local_8[1]);
    *local_8 = uVar12;
    ppuVar10 = (undefined **)FUN_00401920(*local_8,&local_44);
    local_3c._4_4_ = ppuVar10;
    FUN_00401220((int *)*local_8);
    local_34 = *(uint *)(*local_8 + 0x10);
    if (local_34 == 0) {
      local_3c = -99999.0;
    }
    else {
      local_3c = (double)(int)local_3c._4_4_ / (double)(int)local_34;
    }
    FUN_0041b470((byte *)s___EULER__Cubes___d_Components____004300a4);
    break;
  case 0x15:
    if (((int)local_20 < 0) || (DAT_00435524 <= (int)local_20)) {
      local_20 = (undefined **)0x0;
    }
    if (((int)local_14 < 0) || (DAT_00435524 <= (int)local_14)) {
      local_14 = (undefined *)(DAT_00435524 + -1);
    }
    puVar14 = FUN_00407950((short *)*local_8,(int)local_20,(int)local_14);
    puVar14 = FUN_004045f0((short *)puVar14);
    *local_8 = (uint)puVar14;
    break;
  case 0x16:
    FUN_00413310(local_8,(uint)local_c);
    break;
  case 0x17:
    if (((int)local_20 < 0) || ((int)DAT_00435534[DAT_00435568] <= (int)local_20)) {
      local_20 = (undefined **)0x0;
    }
    if (((int)local_14 < 0) || ((int)DAT_00435534[DAT_00435568] <= (int)local_14)) {
      local_14 = DAT_00435534[DAT_00435568] + -1;
    }
    FUN_00414330(local_8,(int)local_20,(int)local_14,local_c);
    ppuVar10 = ppuVar20;
    break;
  case 0x18:
    FUN_00414d10(local_8,(uint)local_c);
    break;
  case 0x19:
    FUN_00415540((int *)local_8,local_c);
    break;
  case 0x1a:
    ppuVar10 = (undefined **)FUN_0041b360();
    puVar14 = FUN_00402a00(*local_8,local_8[1]);
    piVar9 = FUN_00415e80((int *)puVar14);
    *local_8 = (uint)piVar9;
    if (DAT_00435408 == 0) goto LAB_00410cbb;
    FUN_0041b360();
    FUN_00408b70(*local_8);
    break;
  case 0x1c:
    ppuVar10 = (undefined **)FUN_0041b360();
    uVar12 = FUN_004163f0((uint *)*local_8,local_8[1]);
    *local_8 = uVar12;
    FUN_00408bb0((int)ppuVar10,6,*local_8,(undefined4 *)&stack0xffffffa4);
    break;
  case 0x1d:
    puVar14 = FUN_00419430(*local_8,*local_18);
    *local_8 = (uint)puVar14;
    break;
  case 0x1e:
    goto switchD_00410077_caseD_1e;
  case 0x1f:
    if (((int)local_c < 0) || (psVar8 = local_c, 1 < (int)local_c)) {
      psVar8 = (short *)0x0;
    }
    FUN_00408490((int *)local_8,(int)psVar8);
    break;
  case 0x20:
    if (((int)local_c < 0) || (psVar8 = local_c, 1 < (int)local_c)) {
      psVar8 = (short *)0x0;
    }
    FUN_004084f0((int *)local_8,(int)psVar8);
    break;
  case 0x21:
    if (DAT_004353d0 == 0) {
      FUN_00406d90((int *)local_8);
    }
    DAT_004354c4 = (uint *)0x0;
    break;
  case 0x22:
    uVar12 = FUN_0040cdf0(*local_8,(short *)local_8[1],local_8[2],(undefined4 *)&stack0xffffffa4);
    *local_8 = uVar12;
    break;
  case 0x23:
    puVar14 = FUN_00402950(*local_8);
    FUN_0040ef70((int *)puVar14);
    FUN_0041b470((byte *)s_ON_set_is_sa_tautology_0042ffb8);
    DAT_004354c4 = (uint *)0x0;
    break;
  case 0x24:
    uVar12 = local_8[1];
    puVar4 = FUN_004177d0(uVar12,local_8[2],(int)unaff_EBX);
    puVar21 = FUN_00417930(10,DAT_00435520,uVar12);
    FUN_00417a40((short *)*local_8);
    iVar3 = FUN_0041b360();
    puVar14 = FUN_00402950((int)puVar4);
    puVar14 = FUN_00403160(puVar14);
    *local_8 = (uint)puVar14;
    FUN_00408bb0(iVar3,1,*local_8,(undefined4 *)&stack0xffffffa4);
    iVar3 = FUN_0041b360();
    puVar14 = FUN_0040b8a0((short *)*local_8,(int)puVar4,0);
    *local_8 = (uint)puVar14;
    FUN_00408bb0(iVar3,4,*local_8,(undefined4 *)&stack0xffffffa4);
    iVar3 = FUN_0041b360();
    uVar12 = FUN_0040e9b0((int *)*local_8,(short *)puVar21);
    *local_8 = uVar12;
    FUN_00408bb0(iVar3,5,*local_8,(undefined4 *)&stack0xffffffa4);
    FUN_00417a40((short *)puVar4);
    ppuVar10 = (undefined **)FUN_004177d0(*local_8,local_8[2],(int)puVar4);
    iVar3 = FUN_0041b360();
    puVar4 = FUN_0040b8a0((short *)local_8[1],(int)ppuVar10,0);
    local_8[1] = (uint)puVar4;
    FUN_00408bb0(iVar3,4,local_8[1],(undefined4 *)&stack0xffffffa4);
    puVar4 = (uint *)FUN_0041b360();
    uVar12 = FUN_0040e9b0((int *)local_8[1],(short *)puVar21);
    local_8[1] = uVar12;
    FUN_00408bb0((int)puVar4,5,local_8[1],(undefined4 *)&stack0xffffffa4);
    FUN_00417a40((short *)ppuVar10);
    FUN_00417a40((short *)puVar21);
    break;
  case 0x25:
    FUN_0040a4c0((int)local_8);
    DAT_004354c4 = (uint *)0x0;
    break;
  case 0x26:
    puVar14 = FUN_00404630((short *)*local_8,(short *)*local_18);
    *local_8 = (uint)puVar14;
    break;
  case 0x28:
    do {
      FUN_0041b360();
      puVar21 = FUN_0040ac70((uint *)*local_8,local_8[1],(short *)local_8[2]);
      *local_8 = (uint)puVar21;
      if (DAT_00435408 != 0) {
        FUN_0041b360();
        FUN_00408b70(*local_8);
      }
      if (DAT_004354c4 != (uint *)0x0) {
        FUN_00408c60((int *)&DAT_00431c98,local_8,local_10);
        FUN_0041f0ff((int *)&DAT_00431c98);
      }
      uVar12 = local_8[4];
      FUN_00406ff0(local_8);
      FUN_00405270();
      if (DAT_00435534 != (undefined **)0x0) {
        FUN_0041b8c0((int)DAT_00435534);
        DAT_00435534 = (undefined **)0x0;
      }
      iVar3 = FUN_00406a00(DAT_004330b0,1,1,uVar12,&local_8);
    } while (iVar3 != -1);
    FUN_0041ef48(0);
switchD_00410077_caseD_1e:
    puVar21 = (uint *)0x0;
    ppuVar10 = (undefined **)FUN_0041b360();
    puVar14 = FUN_00402950(*local_8);
    puVar14 = FUN_004040f0(puVar14);
    *local_8 = (uint)puVar14;
    if (DAT_00435408 == 0) goto LAB_00410cbb;
    FUN_0041b360();
    FUN_00408b70(*local_8);
    break;
  case 0x29:
    puVar14 = FUN_00402a00(local_8[1],local_8[2]);
    puVar14 = FUN_00403160(puVar14);
    *local_8 = (uint)puVar14;
    break;
  case 0x2a:
    ppuVar10 = (undefined **)FUN_00419a60(*local_8,local_18[2]);
    puVar21 = (uint *)FUN_00419a60(*local_18,local_8[2]);
    psVar8 = (short *)*local_8;
    FUN_00417a40(psVar8);
    puVar14 = FUN_004177d0((int)ppuVar10,(int)puVar21,(int)psVar8);
    puVar14 = FUN_004044e0((short *)puVar14);
    *local_8 = (uint)puVar14;
    FUN_00417a40((short *)ppuVar10);
    FUN_00417a40((short *)puVar21);
    break;
  case 0x2b:
    ppuVar10 = (undefined **)0x0;
    if (0 < DAT_00435528) {
      do {
        uVar12 = FUN_00404720((short *)*local_8,(int)ppuVar10);
        ppuVar10 = (undefined **)((int)ppuVar10 + 1);
        *local_8 = uVar12;
      } while ((int)ppuVar10 < DAT_00435528);
    }
    break;
  case 0x2c:
    FUN_0040e080(local_8,DAT_004353d0,(int)unaff_EBX,in_stack_ffffffa4,in_stack_ffffffa8,
                 in_stack_ffffffac);
    DAT_004354c4 = (uint *)0x0;
  }
  if (DAT_00435408 != 0) {
    FUN_00411020();
  }
LAB_00410cbb:
  if ((DAT_004353d0 != 0) || (DAT_00435408 != 0)) {
    FUN_0041b360();
    puVar21 = local_40;
    FUN_00408b70(*local_8);
  }
  if (DAT_004354c4 != (uint *)0x0) {
    ppuVar10 = (undefined **)FUN_0041b360();
    FUN_00408c60((int *)DAT_00435368,local_8,local_10);
    FUN_00408bb0((int)ppuVar10,0xf,*local_8,(undefined4 *)&stack0xffffffa4);
    if (DAT_00435368 != (FILE *)0x0) {
      FUN_0041ea29(DAT_00435368);
    }
    FUN_0040aa50(3,(int)unaff_EBX);
    iVar3 = FUN_0040aa20();
    if (iVar3 == 0) {
      iVar3 = 5;
    }
    else {
      iVar3 = 6;
    }
    FUN_0040aa50(2,iVar3);
    FUN_0040aa10();
  }
  if (local_28 != (uint *)0x0) {
    FUN_00408c40((int *)s_cover_verification_failed_004300f4,(uint)unaff_EBX);
  }
  FUN_00406ff0(local_8);
  bVar23 = false;
  if (DAT_00435534 != (undefined **)0x0) {
    FUN_0041b8c0((int)DAT_00435534);
    bVar23 = (undefined *)0xfffffffb < &stack0xffffff9c;
    DAT_00435534 = (undefined **)0x0;
  }
  FUN_00405270();
  FUN_00417ac0();
  FUN_00412a40();
  uVar24 = FUN_0041ef48(0);
  iVar3 = ((int)uVar24 + -0x330040fb) - (uint)bVar23;
  cVar16 = (char)iVar3;
  *(char *)(extraout_ECX + 0x10040fc) = *(char *)(extraout_ECX + 0x10040fc) + cVar16 + '\x01';
  *(char *)(puVar4 + (int)puVar21 * 2 + -0x13c7ff0) =
       *(char *)(puVar4 + (int)puVar21 * 2 + -0x13c7ff0) + (char)extraout_ECX;
  *(char *)((int)puVar21 + -3) = *(char *)((int)puVar21 + -3) + cVar16 + '\x03';
  cVar16 = (char)((ulonglong)uVar24 >> 0x20);
  *(char *)(puVar4 + 0x7c0103f) = *(char *)(puVar4 + 0x7c0103f) + cVar16;
  *(byte *)(ppuVar10 + 0x9c0103f) = *(byte *)(ppuVar10 + 0x9c0103f) + (char)puVar4;
  pcVar11 = (char *)(iVar3 + 6);
  cVar18 = (char)((uint)puVar4 >> 8);
  cVar16 = cVar16 + cVar18;
  iVar7 = CONCAT31((int3)((ulonglong)uVar24 >> 0x28),cVar16);
  *pcVar11 = *pcVar11 + '\x01';
  *(char *)puVar4 = *(char *)puVar4 + (char)extraout_ECX;
  puVar14 = (uint *)(extraout_ECX | *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4);
  uVar12 = (uint)pcVar11 | *puVar14;
  uVar15 = (uint)puVar14 | *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4 |
           *puVar4 | *puVar4 | *puVar4 | *puVar4 | *puVar4;
  uVar12 = CONCAT31((int3)(uVar12 >> 8),(char)uVar12 + *(char *)puVar4) |
           *(uint *)((int)puVar4 + uVar15);
  uVar13 = uVar12 + 0xb080706;
  *puVar4 = *puVar4 | uVar15;
  iVar3 = CONCAT31((int3)(uVar15 >> 8),(byte)uVar15 | in_stack_007e0045);
  puVar14 = (uint *)(iVar3 + 1);
  pcVar11 = (char *)(iVar7 + 0x45004102);
  cVar17 = (char)((ulonglong)uVar24 >> 0x28);
  *pcVar11 = *pcVar11 + cVar17;
  *puVar14 = *puVar14 | uVar13;
  *puVar14 = *puVar14 | uVar13;
  *(byte *)puVar14 = *(byte *)puVar14 | (byte)uVar13;
  *(byte *)ppuVar10 = *(byte *)ppuVar10 + cVar16;
  *(char *)(puVar4 + 1) = *(char *)(puVar4 + 1) + cVar18;
  *(char *)((int)puVar21 + -0x3effbefb) = *(char *)((int)puVar21 + -0x3effbefb) + (char)puVar4;
  pbVar2 = (byte *)(iVar3 + 6);
  pcVar11 = (char *)(iVar7 + 0x45004104);
  *pcVar11 = *pcVar11 + cVar17;
  *pbVar2 = *pbVar2 | (char)uVar12 + 0x47U;
  return;
LAB_0040ff05:
  if (*(int *)(&PTR_DAT_0042fb0c)[(int)ppuVar20 * 3] == (&DAT_0042fb10)[(int)ppuVar20 * 3]) {
    DAT_004330b8 = 1;
  }
  goto LAB_0040ff23;
}



