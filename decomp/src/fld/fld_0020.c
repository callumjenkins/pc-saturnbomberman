#include "krnl.h"

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002001A4(int r4, int r5, int r6, int r7)
{
    int r0, r3;

    r0 = GCALL4(0x002001BE, 0, 0, r6, r7);
    r4 = r0;
    if ((r4 & r4) == 0) {
        return r0;
    } else {
        r3 = LD32(0x0600026C);
        r0 = GJUMP1(r3, r4);
        return r0;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002001BE(int r4, int r5, int r6, int r7)
{
    int r0, r1, r3;
    int v8;
    int v12;

    r1 = LD16(0x06000CCE);
    v8 = r1 & 0xFFFF;
    r3 = LD32(0x060002B0);
    v12 = r3;
    r0 = GCALL6(0x002006E8, 0, 0, r6, r7, v12, v8);
    r0 = GCALL6(0x00200208, v8, 2, 0, 0, v12, v8);
    r4 = r0;
    if ((r4 & r4) == 0) {
        r0 = GCALL6(0x0020033E, 2, v12, 0, 0, v12, v8);
        if (r0 >= 0) {
            return 0;
        } else {
            return -1;
        }
    } else {
        return r4;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200208(int r4, int r5)
{
    int r0, r13, r14;
    FRAME(sp, 20);

    r14 = r4;
    ST32(sp - 20, r5);
    r0 = GCALL5(0x0020060A, (sp - 16), 0, 0, 0, LD32((sp - 20)));
    r4 = r0;
    if ((r4 & r4) == 0) {
        r0 = GCALL5(0x00200912, 1, 0, 0, 0, LD32((sp - 20)));
        if ((r0 & r0) == 0) {
            r0 = GCALL5(0x002005B4, 64, 0, 0, 0, LD32((sp - 20)));
            if ((r0 & r0) == 0) {
                r0 = GCALL5(0x002002F2, 0, 0, 0, 0, LD32((sp - 20)));
                r4 = r0;
                if ((r4 & r4) == 0) {
                    r0 = GCALL5(0x00200F10, 0, r14, 0, 0, LD32((sp - 20)));
                    if ((r0 & r0) == 0) {
                        r13 = 0x200;
                        r0 = GCALL5(0x002005B4, 0x200, 0, 0, 0, LD32((sp - 20)));
                        if ((r0 & r0) == 0) {
                            if (!(r14 >= 2)) {
                                r5 = LD32(sp - 20);
                                r0 = GCALL5(0x00200F10, 0, r5, 0, 0, LD32((sp - 20)));
                                if ((r0 & r0) == 0) {
                                    r0 = GCALL5(0x002005B4, r13, 0, 0, 0, LD32((sp - 20)));
                                    if ((r0 & r0) == 0) {
                                        r5 = LD32(sp - 20);
                                        r0 = GCALL5(0x00200FD8, 0, r5, 0, 0, LD32((sp - 20)));
                                        if ((r0 & r0) == 0) {
                                            r0 = 0;
                                        } else {
                                            r0 = -1;
                                        }
                                    } else {
                                        r0 = -1;
                                    }
                                } else {
                                    r0 = -1;
                                }
                            } else {
                                r0 = GCALL5(0x00200EE8, 0, r14, 0, 0, LD32((sp - 20)));
                                if ((r0 & r0) == 0) {
                                    r0 = GCALL5(0x002005B4, r13, 0, 0, 0, LD32((sp - 20)));
                                    if ((r0 & r0) == 0) {
                                        r5 = LD32(sp - 20);
                                        r0 = GCALL5(0x00200F10, 0, r5, 0, 0, LD32((sp - 20)));
                                        if ((r0 & r0) == 0) {
                                            r0 = GCALL5(0x002005B4, r13, 0, 0, 0, LD32((sp - 20)));
                                            if ((r0 & r0) == 0) {
                                                r5 = LD32(sp - 20);
                                                r0 = GCALL5(0x00200FD8, 0, r5, 0, 0, LD32((sp - 20)));
                                                if ((r0 & r0) == 0) {
                                                    r0 = 0;
                                                } else {
                                                    r0 = -1;
                                                }
                                            } else {
                                                r0 = -1;
                                            }
                                        } else {
                                            r0 = -1;
                                        }
                                    } else {
                                        r0 = -1;
                                    }
                                } else {
                                    r0 = -1;
                                }
                            }
                        } else {
                            r0 = -1;
                        }
                    } else {
                        r0 = -1;
                    }
                } else {
                    r0 = r4;
                }
            } else {
                r0 = -1;
            }
        } else {
            r0 = -1;
        }
    } else {
        r0 = r4;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002002F2(void)
{
    int r0;

    r0 = GCALL2(0x00200EE8, 23, -1);
    r0 = GCALL0(0x00201002);
    r0 = GCALL1(0x002005B4, 0x200);
    if ((r0 & r0) == 0) {
        r0 = GCALL2(0x00200EE8, 0, -1);
        if ((r0 & r0) == 0) {
            r0 = GCALL1(0x002005B4, 0x200);
            if ((r0 & r0) == 0) {
                return 0;
            } else {
                return -1;
            }
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0020033E(int r4, int r5)
{
    int r0, r12, r13, r14;
    FRAME(sp, 52);

    ST32(sp - 48, r4);
    ST32(sp - 44, r5);
    r0 = GCALL1(0x00200724, (sp - 40));
    r0 = GCALL1(0x00200724, (sp - 40));
    r0 = GCALL1(0x0020060A, (sp - 52));
    r4 = r0;
    if ((r4 & r4) == 0) {
        r4 = LD32(sp - 48);
        r0 = GCALL2(0x00200F88, r4, (sp - 28));
        if ((r0 & r0) == 0) {
            r12 = LD32(sp - 44);
            r13 = LD32(sp - 24);
            r0 = GCALL2(0x002003DC, r12, r13);
            r14 = r0;
            if ((r14 & r14) == 0) {
                r0 = GCALL3(0x00200410, 0x200, r13, r12);
                r14 = r0;
            }
            r0 = GCALL0(0x00201002);
            if (!(r14 >= 0)) {
                r0 = r14;
            } else {
                if (r14 >= r13) {
                    r0 = r14;
                } else {
                    r0 = -78;
                }
            }
        } else {
            r0 = -77;
        }
    } else {
        r0 = r4;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002003DC(int r4, int r5)
{
    r4 = r4 & 0x1FFFFFFF;
    r5 = r5 + r4;
    if ((unsigned)r5 > (unsigned)r4) {
        if (!((unsigned)r4 >= (unsigned)0x06003000)) {
            if (!((unsigned)r4 >= (unsigned)0x00200000)) {
                return -79;
            } else {
                if ((unsigned)r5 > (unsigned)0x00300000) {
                    return -79;
                } else {
                    return 0;
                }
            }
        } else {
            if ((unsigned)r5 > (unsigned)0x06100000) {
                if (!((unsigned)r4 >= (unsigned)0x00200000)) {
                    return -79;
                } else {
                    if ((unsigned)r5 > (unsigned)0x00300000) {
                        return -79;
                    } else {
                        return 0;
                    }
                }
            } else {
                return 0;
            }
        }
    } else {
        return -79;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200410(int r4, int r5, int r6)
{
    int r0, r2, r8, r9, r10, r11, r12, r13, r14, c5;
    FRAME(sp, 44);

    r12 = 0;
    r10 = r6;
    r13 = (int)((unsigned)(r5 + 3) >> 2);
    r9 = 0xBB8;
    r8 = 0;
    ST32(sp - 36, r4);
    r11 = 0;
    if (!(r13 > 0)) {
        r0 = r8 << 2;
    } else {
        while (1) {
            r0 = GCALL1(0x0020060A, (sp - 40));
            r4 = r0;
            if ((r4 & r4) == 0) {
                r0 = GCALL2(0x00200BA6, 0, (sp - 44));
                if ((r0 & r0) == 0) {
                    r2 = LD32(sp - 44);
                    if (!((r2 & r2) == 0)) {
                        r4 = LD32(sp - 44);
                        r4 = (r4 << 8) << 1;
                        r11 = r12;
                        if (r4 >= r13) {
                            r14 = r13;
                        } else {
                            r14 = r4;
                        }
                        r4 = LD32(sp - 44);
                        r0 = GCALL3(0x00200522, r4, r14, r10);
                        r4 = r0;
                        if ((r4 & r4) == 0) {
                            r10 = r10 + (r14 << 2);
                            r8 = r8 + r14;
                            r13 = r13 - r14;
                            if (r13 > 0) {
                                POLL();
                                continue;
                            } else {
                                r0 = r8 << 2;
                                break;
                            }
                        } else {
                            r0 = r4;
                            break;
                        }
                    } else {
                        r5 = LD32(sp - 36);
                        r4 = LD32(sp - 40);
                        r0 = GCALL2(0x002004E6, r4, r5);
                        if (!((r0 & r0) == 0)) {
                            r0 = r8 << 2;
                            break;
                        } else {
                            c5 = r11 > r9;
                            r11 = r11 + 1;
                            if (!(c5)) {
                                if (r13 > 0) {
                                    POLL();
                                    continue;
                                } else {
                                    r0 = r8 << 2;
                                    break;
                                }
                            } else {
                                r0 = -61;
                                break;
                            }
                        }
                    }
                } else {
                    r0 = -60;
                    break;
                }
            } else {
                r0 = r4;
                break;
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002004E6(int r4, int r5)
{
    int r0;
    int v8;

    r0 = r4;
    v8 = r5;
    if (r0 == 1) {
        r0 = GCALL5(0x002005EE, v8, 0, 0, 0, v8);
        if ((r0 & r0) == 0) {
            return 0;
        } else {
            return 1;
        }
    } else {
        if (r0 == 2) {
            r0 = GCALL5(0x002005EE, v8, 0, 0, 0, v8);
            if ((r0 & r0) == 0) {
                return 0;
            } else {
                return 1;
            }
        } else {
            if (r0 == 9) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002005B4(int r4)
{
    int r0, r5, r13, r14;
    int v16;

    r5 = 0x002C4020;
    r13 = r5;
    v16 = r4;
    r14 = 0;
    if (0 >= r13) {
        r0 = -1;
    } else {
        while (1) {
            r0 = GCALL5(0x002005EE, v16, 0, 0, 0, v16);
            if ((r0 & r0) == 0) {
                r14 = r14 + 1;
                if (!(r14 >= r13)) {
                    POLL();
                    continue;
                } else {
                    r0 = -1;
                    break;
                }
            } else {
                r0 = 0;
                break;
            }
            POLL();
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002005EE(int r4)
{
    int r0;
    int v8;

    v8 = r4;
    r0 = GCALL5(0x00201046, 0, 0, 0, 0, v8);
    return (((r0 & v8) & (r0 & v8)) == 0) ^ 1;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0020060A(int r4)
{
    int r0, r5, r11, r12, r13, r14, c4;
    FRAME(sp, 40);

    ST32(sp - 4, r4);
    r5 = r4;
    r4 = 0;
    r13 = r5;
    ST32(r13, -1);
    if ((r4 & r4) == 0) {
        r11 = 0x00200764;
        r12 = 0;
        r14 = 0x00015F90;
        while (1) {
            r0 = GCALL1(r11, (sp - 32));
            r4 = r0;
            if ((r4 & r4) == 0) {
                r0 = LD8((sp - 32));
                r0 = (r0 & 255) & 15;
                ST32(r13, r0);
                if (r0 == 6) {
                    r0 = -2;
                    break;
                } else {
                    if (r0 == 7) {
                        r0 = -2;
                        break;
                    } else {
                        if (r0 == 10) {
                            ST32((sp - 40), 0);
                            r0 = GCALL1(0x002005EE, 32);
                            if (!((r0 & r0) == 0)) {
                                r0 = -2;
                                break;
                            } else {
                                r0 = GCALL1(0x00200AFA, (sp - 40));
                                r0 = -2;
                                break;
                            }
                        } else {
                            r0 = GCALL1(0x002005EE, 32);
                            if ((r0 & r0) == 0) {
                                r0 = 0;
                                break;
                            } else {
                                r0 = -2;
                                break;
                            }
                        }
                    }
                }
            } else {
                if (r4 == -8) {
                    c4 = r12 > r14;
                    r12 = r12 + 1;
                    if (!(c4)) {
                        POLL();
                        continue;
                    } else {
                        r0 = -103;
                        break;
                    }
                } else {
                    r0 = -102;
                    break;
                }
            }
            POLL();
        }
    } else {
        r0 = GCALL1(0x00200724, (sp - 32));
        if ((r0 & r0) == 0) {
            r0 = LD8((sp - 32));
            r0 = (r0 & 255) & 15;
            ST32(r13, r0);
            if (r0 == 6) {
                r0 = -2;
            } else {
                if (r0 == 7) {
                    r0 = -2;
                } else {
                    if (r0 == 10) {
                        ST32((sp - 40), 0);
                        r0 = GCALL1(0x002005EE, 32);
                        if ((r0 & r0) == 0) {
                            r0 = GCALL1(0x00200AFA, (sp - 40));
                        }
                        r0 = -2;
                    } else {
                        r0 = GCALL1(0x002005EE, 32);
                        if ((r0 & r0) == 0) {
                            r0 = 0;
                        } else {
                            r0 = -2;
                        }
                    }
                }
            }
        } else {
            r0 = -101;
        }
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200700(int r4, int r5, int r6, int r7)
{
    int r0, r1;

    r0 = GCALL4(0x060022E4, r4, r5, r6, r7);
    r1 = 0x06002D80;
    r0 = LD32(0x06002D80);
    if (!(r0 >= 0)) {
        r0 = r0 ^ r0;
    }
    ST32(r1, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200724(int r4)
{
    int r0, r5, r13;
    FRAME(sp, 36);

    ST32(sp - 36, r4);
    r5 = (sp - 36) + 16;
    r13 = (sp - 36) + 8;
    ST32(r5, 0);
    ST32(r5 + 4, 0);
    ST8(r5, 0);
    r0 = GCALL5(0x00201276, 0, r5, r13, 1, LD32((sp - 36)));
    ST32(sp - 32, r0);
    r5 = LD32(sp - 36);
    r0 = GCALL6(0x00201310, r13, r5, 0, 0, LD32((sp - 36)), LD32((sp - 32)));
    r0 = LD32(sp - 32);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200764(int r4)
{
    int r0, r5, r13, r14;
    FRAME(sp, 24);

    ST32(sp - 24, r4);
    r13 = (sp - 24) + 4;
    r0 = GCALL5(0x002007A8, r13, 0, 0, 0, LD32((sp - 24)));
    r14 = r0;
    if ((r14 & r14) == 0) {
        r5 = LD32(sp - 24);
        r0 = GCALL5(0x00201310, r13, r5, 0, 0, LD32((sp - 24)));
        r4 = LD32(sp - 24);
        r4 = LD8(r4);
        r4 = r4 & 255;
        if (r4 == 255) {
            r14 = -8;
        } else {
            if ((32 & r4) == 0) {
                r14 = -8;
            }
        }
        r0 = r14;
    } else {
        r0 = r14;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002007A8(int r4)
{
    int r0, r1, r2, r3, r5, r8, r9, r10, r11, r12, r13, r14;
    FRAME(sp, 40);

    r11 = 0;
    r14 = 0x0020122A;
    r10 = r4;
    r13 = 0;
    r9 = -3;
    r12 = sp - 40;
    while (1) {
        r0 = SR();
        r8 = ((int)((unsigned)((int)((unsigned)r0 >> 2)) >> 2)) & 15;
        r0 = SR();
        SETSR(((r0 & -241) | 240));
        r0 = GCALL1(r14, r10);
        r0 = GCALL1(r14, r12);
        r2 = SR();
        SETSR(((((r8 & 15) << 2) << 2) | (r2 & -241)));
        r5 = r10;
        r4 = r12;
        r3 = LD32(r5);
        r2 = LD32(r4);
        if (!(r3 == r2)) {
            r13 = r13 + 1;
            if (!(r13 >= 100)) {
                POLL();
                continue;
            } else {
                break;
            }
        } else {
            r0 = LD32(r4 + 4);
            r1 = LD32(r5 + 4);
            if (!(r1 == r0)) {
                r13 = r13 + 1;
                if (!(r13 >= 100)) {
                    POLL();
                    continue;
                } else {
                    break;
                }
            } else {
                r9 = r11;
                break;
            }
        }
        POLL();
    }
    return r9;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0020082A(int r4)
{
    int r0, r5, r13, r14;
    FRAME(sp, 32);

    r13 = r4;
    r5 = (sp - 32) + 8;
    ST32(r5, 0);
    r14 = sp - 32;
    ST32(r5 + 4, 0);
    ST8(r5, 1);
    r0 = GCALL3(0x00201260, 0, r5, r14);
    r4 = r0;
    r0 = LD8(r14 + 2);
    ST8(r13, r0);
    r0 = LD8(r14 + 3);
    ST8(r13 + 1, r0);
    r0 = LD8(r14 + 5);
    ST8(r13 + 2, r0);
    r0 = LD8(r14 + 6);
    ST8(r13 + 3, r0);
    r0 = LD8(r14 + 7);
    ST8(r13 + 4, r0);
    return r4;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0020088C(int r4)
{
    int r0, r5, r14;
    FRAME(sp, 32);

    ST32(sp - 32, r4);
    r5 = (sp - 32) + 12;
    r14 = (sp - 32) + 4;
    ST32(r5, 0);
    ST32(r5 + 4, 0);
    ST8(r5, 2);
    r0 = GCALL5(0x00201260, 0, r5, r14, 0, LD32((sp - 32)));
    r4 = r0;
    if ((r4 & r4) == 0) {
        r4 = LD32(r14);
        r5 = LD32(sp - 32);
        r0 = GCALL5(0x00201096, (r4 & 0x00FFFFFF), r5, 0, 0, LD32((sp - 32)));
    } else {
        r0 = r4;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002008D0(int r4, int r5)
{
    int r0, r2, r3, r12, r14;
    FRAME(sp, 36);

    ST32(sp - 36, r5);
    r14 = (sp - 36) + 12;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    r12 = (sp - 36) + 4;
    ST8(r14, 3);
    ST8(r14 + 1, r4);
    r0 = GCALL5(0x00201260, 0, r14, r12, 0, LD32((sp - 36)));
    r2 = LD32(sp - 36);
    r3 = LD32(r12 + 4);
    ST32(r2, r3);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200912(int r4, int r5, int r6, int r7)
{
    int r0, r13, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 4);
    ST8(r14 + 1, r4);
    ST16(r14 + 2, r5);
    ST8(r14 + 6, r6);
    ST8(r14 + 7, r7);
    if (!((129 & r4) == 1)) {
        r0 = GCALL2(0x00201264, 0, r14);
        r13 = r0;
    } else {
        r0 = GCALL1(0x0020132E, 0x2904);
        r0 = GCALL1(0x00201078, 65);
        r0 = GCALL2(0x00201264, 64, r14);
        r13 = r0;
        if ((r13 & r13) == 0) {
            r0 = GCALL0(0x00201066);
        }
    }
    return r13;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0020097C(void)
{
    int r0, r5;
    FRAME(sp, 16);

    r5 = sp - 16;
    ST32(r5, 0);
    ST32(r5 + 4, 0);
    ST8(r5, 5);
    r0 = GCALL2(0x00201264, 0, r5);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002009BC(int r4)
{
    int r0, r14;
    FRAME(sp, 20);

    ST32(sp - 16, r4);
    r0 = LD32(sp - 16);
    r4 = 2;
    if (r0 == 1) {
        r4 = 130;
    }
    r0 = GCALL2(0x002011E0, r4, (sp - 20));
    r14 = r0;
    r0 = LD32(sp - 16);
    if (r0 == 1) {
        if ((r14 & r14) == 0) {
            r0 = LD32(sp - 20);
            if (!((r0 & 128) == 0)) {
                r14 = -4;
            }
        }
    }
    if (!((r14 & r14) == 0)) {
        r0 = GCALL1(0x00200A06, (sp - 12));
    }
    r0 = GCALL1(0x00201060, -3);
    return r14;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200A06(int r4)
{
    int r0, r1, r3, r5, r14;
    FRAME(sp, 36);

    ST32(sp - 36, r4);
    r5 = (sp - 36) + 16;
    ST32(r5, 0);
    r14 = (sp - 36) + 8;
    ST32(r5 + 4, 0);
    ST8(r5, 6);
    r0 = GCALL5(0x00201260, 0, r5, r14, 0, LD32((sp - 36)));
    ST32(sp - 32, r0);
    r3 = LD32(sp - 36);
    r1 = LD32(r14);
    ST32(r3, (r1 & 0x00FFFFFF));
    r0 = GCALL6(0x00201060, -3, 0, 0, 0, LD32((sp - 36)), LD32((sp - 32)));
    r0 = LD32(sp - 32);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200A5C(int r4)
{
    int r0, r13, r14;
    FRAME(sp, 24);

    r13 = r4;
    r14 = sp - 24;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 16);
    r0 = GCALL2(0x00200AA0, r13, (r14 + 1));
    r0 = LD8(16 + r13);
    ST8(r14 + 4, r0);
    r0 = GCALL2(0x00200AA0, (r13 + 8), (r14 + 5));
    r0 = GCALL2(0x00201264, 0, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200AA0(int r4, int r5)
{
    int r0, r1, r6, r7;

    r0 = LD32(r4);
    r1 = 0;
    r6 = r5 + 1;
    r7 = r5 + 2;
    if (r0 == 0) {
        ST8(r5, r1);
        ST8(r6, r1);
        ST8(r7, r1);
        return r0;
    } else {
        if (r0 == 1) {
            r0 = LD8((r4 + 4) + 1);
            ST8(r5, (r0 | 128));
            r0 = LD8((r4 + 4) + 2);
            ST8(r6, r0);
            r0 = LD8((r4 + 4) + 3);
            ST8(r7, r0);
            return r0;
        } else {
            if (r0 == 2) {
                ST8(r5, r1);
                r0 = LD8(r4 + 4);
                ST8(r6, r0);
                r0 = LD8(r4 + 5);
                ST8(r7, r0);
                return r0;
            } else {
                if (r0 == 3) {
                    ST8(r5, 255);
                    ST8(r6, 255);
                    ST8(r7, 255);
                    return r0;
                } else {
                    ST8(r5, r1);
                    ST8(r6, r1);
                    ST8(r7, r1);
                    return r0;
                }
            }
        }
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200AFA(int r4)
{
    int r0, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 17);
    r0 = GCALL2(0x00200AA0, r4, (r14 + 1));
    r0 = GCALL2(0x00201264, 0, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200B26(int r4)
{
    int r0, r14;
    FRAME(sp, 20);

    r14 = sp - 20;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 18);
    ST8(r14 + 1, r4);
    r0 = GCALL2(0x00201264, 0, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200B58(int r4, int r5, int r6)
{
    int r0, r3, r14;
    FRAME(sp, 40);

    ST32(sp - 36, r4);
    r14 = (sp - 40) + 12;
    ST32(sp - 40, r5);
    ST32(sp - 32, r6);
    r5 = (sp - 40) + 20;
    ST32(r5, 0);
    ST32(r5 + 4, 0);
    ST8(r5, 80);
    r0 = GCALL7(0x00201260, 0, r5, r14, 0, LD32((sp - 40)), LD32((sp - 36)), LD32((sp - 32)));
    r3 = LD32(sp - 32);
    r4 = r0;
    r0 = LD16(r14 + 2);
    ST32(r3, (r0 & 0xFFFF));
    r3 = LD32(sp - 40);
    r0 = LD8(r14 + 4);
    ST32(r3, (r0 & 255));
    r3 = LD32(sp - 36);
    r0 = LD16(r14 + 6);
    ST32(r3, (r0 & 0xFFFF));
    return r4;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200BA6(int r4, int r5)
{
    int r0, r2, r12, r14;
    FRAME(sp, 36);

    ST32(sp - 36, r5);
    r14 = (sp - 36) + 12;
    r12 = (sp - 36) + 4;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 81);
    ST8(r14 + 4, r4);
    r0 = GCALL5(0x00201260, 0, r14, r12, 0, LD32((sp - 36)));
    r4 = r0;
    r2 = LD32(sp - 36);
    r0 = LD16(r12 + 6);
    ST32(r2, (r0 & 0xFFFF));
    return r4;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200BEA(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 82);
    ST16(r14 + 2, r5);
    ST8(r14 + 4, r4);
    ST16(r14 + 6, r6);
    r0 = GCALL2(0x00201264, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200C18(int r4)
{
    int r0, r1, r3, r14;
    FRAME(sp, 28);

    ST32(sp - 28, r4);
    r14 = (sp - 28) + 4;
    r4 = (sp - 28) + 12;
    ST32(r4, 0);
    ST32(r4 + 4, 0);
    ST8(r4, 83);
    r0 = GCALL5(0x00200C4C, r4, r14, 0, 0, LD32((sp - 28)));
    r3 = LD32(sp - 28);
    r1 = LD32(r14);
    ST32(r3, (r1 & 0x00FFFFFF));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200C4C(int r4, int r5)
{
    int r0;
    int v8;
    int v12;

    v8 = r4;
    v12 = r5;
    r0 = GCALL6(0x00201046, 0, 0, 0, 0, v12, v8);
    if (!((r0 & 64) == 0)) {
        r0 = GCALL6(0x00201260, 0, v8, v12, 0, v12, v8);
        return r0;
    } else {
        return -1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200C7C(int r4, int r5, int r6)
{
    int r0, r2, r12, r13, r14;
    FRAME(sp, 36);

    r12 = r6;
    r14 = (sp - 36) + 8;
    ST32(r14, 0);
    r13 = sp - 36;
    ST32(r14 + 4, 0);
    ST8(r14, 84);
    ST16(r14 + 2, r5);
    ST8(r14 + 4, r4);
    r0 = GCALL3(0x00201260, 0, r14, r13);
    r4 = r0;
    r2 = LD32(r13);
    ST32(r12, (r2 & 0x00FFFFFF));
    r0 = LD8(r13 + 4);
    ST8(r12 + 4, r0);
    r0 = LD8(r13 + 5);
    ST8(r12 + 5, r0);
    r0 = LD8(r13 + 6);
    ST8(r12 + 6, r0);
    r0 = LD8(r13 + 7);
    ST8(r12 + 7, r0);
    return r4;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200CD6(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 85);
    ST16(r14 + 2, r5);
    ST32(r14 + 4, r6);
    ST8(r14 + 4, r4);
    r0 = GCALL2(0x00201264, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200D02(int r4, int r5, int r6)
{
    int r0, r1, r3, r14;
    FRAME(sp, 36);

    ST32(sp - 36, r4);
    r14 = (sp - 36) + 12;
    ST32(sp - 28, r5);
    ST32(sp - 32, r6);
    r4 = (sp - 36) + 20;
    ST32(r4, 0);
    ST32(r4 + 4, 0);
    ST8(r4, 86);
    r0 = GCALL7(0x00200C4C, r4, r14, 0, 0, LD32((sp - 36)), LD32((sp - 32)), LD32((sp - 28)));
    r3 = LD32(sp - 28);
    r4 = r0;
    r0 = LD16(r14 + 2);
    ST32(r3, (r0 & 0xFFFF));
    r3 = LD32(sp - 36);
    r0 = LD8(r14 + 4);
    ST32(r3, (r0 & 255));
    r3 = LD32(sp - 32);
    r1 = LD32(r14 + 4);
    ST32(r3, (r1 & 0x00FFFFFF));
    return r4;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200D5C(int r4, int r5)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 96);
    ST8(r14 + 1, r4);
    ST8(r14 + 2, r5);
    r0 = GCALL2(0x00201264, 64, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200D86(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 97);
    ST16(r14 + 2, r5);
    ST8(r14 + 4, r4);
    ST16(r14 + 6, r6);
    r0 = GCALL2(0x00201264, 128, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200DB4(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 98);
    ST16(r14 + 2, r5);
    ST8(r14 + 4, r4);
    ST16(r14 + 6, r6);
    r0 = GCALL2(0x00201264, 128, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200DE2(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 99);
    ST16(r14 + 2, r5);
    ST8(r14 + 4, r4);
    ST16(r14 + 6, r6);
    r0 = GCALL2(0x00201264, 128, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200E10(int r4, int r5)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 100);
    ST8(r14 + 4, r4);
    ST16(r14 + 6, r5);
    r0 = GCALL2(0x00201264, 128, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200E3A(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 101);
    ST8(r14 + 1, r7);
    ST16(r14 + 2, r5);
    ST8(r14 + 4, r4);
    ST16(r14 + 6, r6);
    r0 = GCALL2(0x00201264, 0x100, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200E6E(int r4, int r5, int r6, int r7)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 102);
    ST8(r14 + 1, r7);
    ST16(r14 + 2, r5);
    ST8(r14 + 4, r4);
    ST16(r14 + 6, r6);
    r0 = GCALL2(0x00201264, 0x100, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200EA2(int r4)
{
    int r0, r3, r5, r14;
    FRAME(sp, 32);

    ST32(sp - 32, r4);
    r5 = (sp - 32) + 12;
    ST32(r5, 0);
    r14 = (sp - 32) + 4;
    ST32(r5 + 4, 0);
    ST8(r5, 103);
    r0 = GCALL5(0x00201260, 0, r5, r14, 0, LD32((sp - 32)));
    r4 = r0;
    r3 = LD32(sp - 32);
    r0 = LD8(r14 + 1);
    ST32(r3, (r0 & 255));
    return r4;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200EE8(int r4, int r5)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 112);
    ST32(r14 + 4, r5);
    ST8(r14 + 4, r4);
    r0 = GCALL2(0x00201264, 0x200, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200F10(int r4, int r5)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 113);
    ST32(r14 + 4, r5);
    ST8(r14 + 4, r4);
    r0 = GCALL2(0x00201264, 0x200, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200F38(int r4, int r5, int r6)
{
    int r0, r1, r3, r14;
    FRAME(sp, 40);

    ST32(sp - 36, r4);
    r14 = (sp - 40) + 12;
    ST32(sp - 32, r5);
    ST32(sp - 40, r6);
    r5 = (sp - 40) + 20;
    ST32(r5, 0);
    ST32(r5 + 4, 0);
    ST8(r5, 114);
    r0 = GCALL7(0x00201260, 0, r5, r14, 0, LD32((sp - 40)), LD32((sp - 36)), LD32((sp - 32)));
    r3 = LD32(sp - 32);
    r4 = r0;
    r0 = LD16(r14 + 2);
    ST32(r3, (r0 & 0xFFFF));
    r3 = LD32(sp - 40);
    r0 = LD8(r14 + 4);
    ST32(r3, (r0 & 255));
    r3 = LD32(sp - 36);
    r1 = LD32(r14 + 4);
    ST32(r3, (r1 & 0x00FFFFFF));
    return r4;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200F88(int r4, int r5)
{
    int r0, r12, r14;
    FRAME(sp, 36);

    ST32(sp - 36, r5);
    r14 = (sp - 36) + 12;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    r12 = (sp - 36) + 4;
    ST8(r14, 115);
    ST32(r14 + 4, r4);
    ST8(r14 + 4, 0);
    r0 = GCALL5(0x00201260, 0, r14, r12, 0, LD32((sp - 36)));
    r4 = r0;
    if ((r4 & r4) == 0) {
        r4 = LD32(r12);
        r5 = LD32(sp - 36);
        r0 = GCALL5(0x00201096, (r4 & 0x00FFFFFF), r5, 0, 0, LD32((sp - 36)));
    } else {
        r0 = r4;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00200FD8(int r4, int r5, int r6)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST32(r14, r6);
    ST8(r14, 116);
    ST32(r14 + 4, r5);
    ST8(r14 + 4, r4);
    r0 = GCALL2(0x00201264, 0x200, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00201002(void)
{
    int r0, r14;
    FRAME(sp, 16);

    r14 = sp - 16;
    ST32(r14, 0);
    ST32(r14 + 4, 0);
    ST8(r14, 117);
    r0 = GCALL1(0x00201078, 0x200);
    r0 = GCALL2(0x00201264, 0x200, r14);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00201040(void)
{
    return 0x25818000;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00201046(void)
{
    int r0;

    r0 = LD16(0x25890008);
    return r0 & 0xFFFF;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f00201060(int r4)
{
    ST16(0x25890008, r4);
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00201066(void)
{
    int r0;

    r0 = GCALL1(0x00201060, 0xBE1);
    ST16(0x00201378, 0xBE1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f00201078(int r4)
{
    int r3;

    r3 = LD16(0x00201378);
    ST16(0x00201378, (r3 | r4));
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00201096(int r4, int r5)
{
    int r0, r2, r3, r6, r14;
    FRAME(sp, 16);

    r14 = r4;
    ST32(sp - 12, r5);
    r0 = GCALL1(0x002009BC, 0);
    r4 = r0;
    if ((r4 & r4) == 0) {
        r6 = 0x25898000;
        r4 = LD32(sp - 12);
        r5 = 0;
        if (!(0 >= r14)) {
            do {
                r5 = r5 + 1;
                r2 = LD16(r6);
                ST16(r4, r2);
                r4 = r4 + 2;
            } while (AGAIN(!(r5 >= r14)));
        }
        r0 = GCALL1(0x00200A06, (sp - 16));
        r4 = r0;
        if ((r4 & r4) == 0) {
            r3 = LD32(sp - 16);
            if (!(r14 == r3)) {
                r4 = -7;
            }
        }
        return r4;
    } else {
        return r4;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002010EE(int r4, int r5, int r6)
{
    int r0, r3;
    int v8;

    r0 = SR();
    v8 = ((int)((unsigned)((int)((unsigned)r0 >> 2)) >> 2)) & 15;
    r0 = SR();
    SETSR(((r0 & -241) | 240));
    r0 = GCALL5(0x00201126, r4, r5, r6, 0, v8);
    r3 = SR();
    SETSR(((((v8 & 15) << 2) << 2) | (r3 & -241)));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00201126(int r4, int r5, int r6)
{
    int r0, r2, r3, r12, r13, r14;
    FRAME(sp, 28);

    r12 = r4;
    r14 = 0x00201378;
    ST32(sp - 20, r5);
    ST32(sp - 28, r6);
    r3 = LD16(0x25890008);
    r2 = LD16(0x00201378);
    ST16(0x00201378, (r2 | r3));
    r4 = LD16(0x00201378);
    r4 = r4 & 0xFFFF;
    if ((r4 & r12) == r12) {
        r13 = 1;
        if (!((r4 & 1) == 0)) {
            r0 = GCALL5(0x00201060, (~(r12 | r13)), 0, 0, 0, LD32((sp - 28)));
            r2 = LD16(r14);
            ST16(r14, (r2 & 0xFFFE));
            r4 = LD32(sp - 20);
            r0 = GCALL5(0x00201210, r4, 0, 0, 0, LD32((sp - 28)));
            r0 = GCALL5(0x002011E0, r13, (sp - 24), 0, 0, LD32((sp - 28)));
            r13 = r0;
            if ((r13 & r13) == 0) {
                r4 = LD32(sp - 28);
                r0 = GCALL5(0x0020122A, r4, 0, 0, 0, LD32((sp - 28)));
                r4 = LD32(sp - 28);
                r4 = LD8(r4);
                r4 = r4 & 255;
                if (!(r4 == 255)) {
                    if (!((r4 & 128) == 0)) {
                        r13 = -6;
                    }
                } else {
                    r13 = -5;
                }
                r0 = r13;
                if ((r13 & r13) == 0) {
                    r3 = LD16(r14);
                    ST16(r14, (r3 & (~r12)));
                }
            } else {
                r0 = r13;
            }
        } else {
            r0 = -2;
        }
    } else {
        r0 = -1;
    }
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f002011E0(int r4, int r5)
{
    int r1, r6, r7, r11, r12, r14;

    r14 = 0;
    r1 = 0x00240000;
    r7 = 0;
    r12 = -3;
    r11 = 0x25890008;
    while (1) {
        r6 = LD16(r11);
        r6 = r6 & 0xFFFF;
        if ((r4 & r6) == 0) {
            r7 = r7 + 1;
            if (!(r7 >= r1)) {
                POLL();
                continue;
            } else {
                break;
            }
        } else {
            r12 = r14;
            ST32(r5, r6);
            break;
        }
        POLL();
    }
    return r12;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00201210(int r4)
{
    int r0, r3;

    r3 = LD16(r4);
    ST16(0x25890018, r3);
    r0 = LD16(r4 + 2);
    ST16(0x2589001C, r0);
    r0 = LD16(r4 + 4);
    ST16(0x25890020, r0);
    r0 = LD16(r4 + 6);
    ST16(0x25890024, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f0020122A(int r4)
{
    int r0, r3;

    r3 = LD16(0x25890018);
    ST16(r4, r3);
    r0 = LD16(0x2589001C);
    ST16(r4 + 2, r0);
    r0 = LD16(0x25890020);
    ST16(r4 + 4, r0);
    r0 = LD16(0x25890024);
    ST16(r4 + 6, r0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00201260(int r4, int r5, int r6, int r7)
{
    int r0;

    r0 = GJUMP4(0x00201276, r4, r5, r6, 0);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00201264(int r4, int r5)
{
    int r0;
    FRAME(sp, 12);

    r0 = GCALL4(0x00201276, r4, r5, (sp - 12), 1);
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00201310(int r4, int r5)
{
    int r0, r2, r3;

    r3 = LD8(r4);
    ST8(r5, r3);
    r0 = LD8(r4 + 1);
    ST8(r5 + 4, r0);
    r0 = LD8(r4 + 2);
    ST8(r5 + 5, r0);
    r0 = LD8(r4 + 3);
    ST8(r5 + 6, r0);
    r0 = LD8(r4 + 4);
    ST8(r5 + 7, r0);
    r2 = LD32(r4 + 4);
    ST32(r5 + 8, (r2 & 0x00FFFFFF));
    return r0;
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
void f0020132E(int r4)
{
    int v4;

    v4 = r4;
    while (v4 > 0) {
        POLL();
        v4 = v4 - 1;
    }
}

/* Lifted by decomp/lift.py, not yet rewritten by hand. */
int f00201276(int r4, int r5, int r6, int r7)
{
    int r0, r2, r3, r13, r14;
    int v16;
    int v20;

    r13 = r6;
    v20 = r7;
    r0 = GCALL5(0x002010EE, r4, r5, r13, 0, v20);
    r14 = r0;
    if ((r14 & r14) == 0) {
        r0 = (SR() & ~1) | 1;
        v16 = ((int)((unsigned)((int)((unsigned)r0 >> 2)) >> 2)) & 15;
        r0 = (SR() & ~1) | 1;
        SETSR(((r0 & -241) | 240));
        r5 = 0x0020137C;
        if ((v20 & v20) == 0) {
            r3 = LD8(r13);
            ST8(r5, r3);
        } else {
            r0 = GCALL6(0x00201310, r13, r5, 0, 0, v20, v16);
        }
        r2 = SR();
        SETSR(((((v16 & 15) << 2) << 2) | (r2 & -241)));
        r0 = r14;
    } else {
        r0 = r14;
    }
    return r0;
}
