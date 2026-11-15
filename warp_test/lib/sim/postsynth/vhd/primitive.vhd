    --									--
    --      Copyright Cypress Semiconductor Corporation, 1994-2001	--
    --      as an unpublished work.					--
    --									--

library ieee;
use ieee.std_logic_1164.all;

package primitive is

    type reg_def   is (reg, comb, dblreg);	
    type polarity  is (invt, ninv);
    type fb_type   is (xpin, xreg, xadj, adj);
    type oreg_type is (dreg, treg, oltch, cmb);
    type ireg_type is (comb, ireg, dblireg, iltch);
    type src_type  is (src_ptm, src_adj);
    type clk_type  is (nopt, ckpt);
    type slw_type  is (fast, slow);
    type pwr_type  is (hipw, lopw);
    type clmem     is array (1023 downto 0) of	std_logic_vector(7 downto 0);
    type chmem     is array ( 511 downto 0) of	std_logic_vector(7 downto 0);

    function time_to_real (a : time) return real;
    function to_integer (a: std_logic_vector) return natural;
    function to_integer (a: Bit_Vector) return natural;
    function timeAdjust (time_constraint: time) return time;

    component c20m
	generic (
	    Tpd  	: time		:= 25 ns;
	    Tea  	: time		:= 25 ns;
	    Ter  	: time		:= 25 ns;
	    Tpzx 	: time		:= 20 ns;
	    Tpxz 	: time		:= 20 ns;
	    Tco  	: time		:= 15 ns;
	    Ts 	 	: time		:= 20 ns;
	    Th 	 	: time		:=  0 ns;
	    Tw 	 	: time		:= 15 ns);
	port (
	    x		: in	std_logic;
	    oe		: in	std_logic;
	    y		: inout	std_logic;
	    yfb		: out	std_logic);
    end component;

    component c20tri
	generic (
	    Tpd	 	: time		:= 25 ns;
	    Tea	 	: time		:= 25 ns;
	    Ter	 	: time		:= 25 ns;
	    Tpzx 	: time		:= 20 ns;
	    Tpxz 	: time		:= 20 ns;
	    Tco	 	: time		:= 15 ns;
	    Ts	 	: time		:= 20 ns;
	    Th	 	: time		:=  0 ns;
	    Tw	 	: time		:= 15 ns);
	port (
	    x		: in	std_logic;
	    oe		: in	std_logic;
	    y		: out	std_logic);
    end component;

    component c20r
	generic (
	    Tpd  	: time		:= 25 ns;
	    Tea  	: time		:= 25 ns;
	    Ter  	: time		:= 25 ns;
	    Tpzx 	: time		:= 20 ns;
	    Tpxz 	: time		:= 20 ns;
	    Tco  	: time		:= 15 ns;
	    Ts   	: time		:= 20 ns;
	    Th   	: time		:=  0 ns;
	    Tw   	: time		:= 15 ns);
	port (
	    d		: in	std_logic;
	    oe		: in	std_logic;
	    clk		: in	std_logic;
	    y		: out	std_logic;
	    qfb		: out	std_logic);
    end component;

    component c16v8m
	generic (
	    registered	: reg_def	:= reg;
	    inv_setting	: polarity	:= invt;
	    bta_sel	: fb_type	:= xreg;
	    Tpd		: time		:= 10 ns;
	    Ten		: time		:= 10 ns;
	    Tdis	: time		:= 10 ns;
	    Tco		: time		:=  7 ns;
	    Tsu		: time		:=  7 ns;
	    Th		: time		:=  0 ns;
	    Twh		: time		:=  8 ns;
	    Twl		: time		:=  8 ns;
	    Tcf		: time		:=  6 ns);
	port (
	    d		: in	std_logic;
	    clk		: in	std_logic;
	    oe		: in	std_logic;
	    adj		: in	std_logic;
	    y		: inout	std_logic;
	    fb		: out	std_logic;
	    yfb		: out	std_logic);
    end component;

    component c20g10m
	generic (
	    registered	: reg_def	:= reg;
	    inv_setting	: polarity	:= ninv;
	    bta_sel	: fb_type	:= xreg;
	    Tpd		: time		:= 25 ns;
	    Tpzx	: time		:= 20 ns;
	    Tpxz	: time		:= 20 ns;
	    Tco		: time		:= 15 ns;
	    Ts		: time		:= 15 ns;
	    Th		: time		:=  0 ns;
	    Twh		: time		:= 12 ns;
	    Twl		: time		:= 12 ns);

	port (
	    d		: in	std_logic;
	    clk		: in	std_logic;
	    oe		: in	std_logic;
	    y		: inout	std_logic;
	    fb		: out	std_logic);
    end component;

    component c20ra10m
	generic (
	    ibr		: polarity	:= invt;
	    Tpd		: time		:= 15 ns;
	    Tpzx	: time		:= 12 ns;
	    Tpxz	: time		:= 12 ns;
	    Tco		: time		:= 15 ns;
	    Tsu		: time		:= 7 ns;
	    Th		: time		:= 3 ns;
	    Twh		: time		:= 10 ns;
	    Twl		: time		:= 10 ns;
	    Ts		: time		:= 15 ns;
	    Tr		: time		:= 15 ns;
	    Tarw	: time		:= 15 ns;
	    Tasw	: time		:= 15 ns;
	    Tar		: time		:= 10 ns;
	    Twp		: time		:= 15 ns;
	    Tsup	: time		:= 15 ns;
	    Thp		: time		:= 15 ns);
	port (
	    d		: in	std_logic;
	    clk		: in	std_logic;
	    oe		: in	std_logic;
	    pl		: in	std_logic;
	    as		: in	std_logic;
	    ar		: in	std_logic;
	    y		: inout	std_logic;
	    yfb		: out	std_logic);
    end component;

    component c22v10m
	generic (
	    registered	: reg_def	:= reg;
	    inv_setting	: polarity	:= invt;
	    bta_sel	: fb_type	:= xreg;
	    Tpd		: time		:= 20 ns;
	    Tea		: time		:= 20 ns;
	    Ter		: time		:= 20 ns;
	    Tco		: time		:= 12 ns;
	    Ts		: time		:= 12 ns;
	    Th		: time		:=  0 ns;
	    Twh		: time		:= 10 ns;
	    Twl		: time		:= 10 ns;
	    Tcf		: time		:= 10 ns;
	    Taw		: time		:= 20 ns;
	    Tar		: time		:= 20 ns;
	    Tap		: time		:= 25 ns;
	    Tspr	: time		:= 20 ns);
	port (
	    d		: in	std_logic;
	    clk		: in	std_logic;
	    oe		: in	std_logic;
	    ss		: in	std_logic;
	    ar		: in	std_logic;
	    y		: inout	std_logic;
	    fb		: out	std_logic);
    end component;

    component c331ckmx
	generic (
	    Tpd		: time		:= 20 ns;
	    Tico	: time		:= 35 ns;
	    Tioh	: time		:=  5 ns;
	    Tis		: time		:=  2 ns;
	    Tih		: time		:= 11 ns;
	    Tiar	: time		:= 35 ns;
	    Tirw	: time		:= 35 ns;
	    Tirr	: time		:= 35 ns;
	    Tias	: time		:= 35 ns;
	    Tisw	: time		:= 35 ns;
	    Tisr	: time		:= 35 ns;
	    Twh		: time		:= 12 ns;
	    Twl		: time		:= 12 ns;
	    Tco		: time		:= 20 ns;
	    Ts		: time		:= 12 ns;
	    Th		: time		:=  8 ns;
	    Toar	: time		:= 20 ns;
	    Torw	: time		:= 20 ns;
	    Torr	: time		:= 20 ns;
	    Toas	: time		:= 20 ns;
	    Tosw	: time		:= 20 ns;
	    Tosr	: time		:= 20 ns;
	    Tpzx	: time		:= 20 ns;
	    Tpxz	: time		:= 20 ns);
	port (
	    clksrc	: in	std_logic;
	    clk		: out	std_logic);
    end component;

    component c331m
	generic (
	    Tpd		: time		:= 20 ns;
	    Tico	: time		:= 35 ns;
	    Tioh	: time		:=  5 ns;
	    Tis		: time		:=  2 ns;
	    Tih		: time		:= 11 ns;
	    Tiar	: time		:= 35 ns;
	    Tirw	: time		:= 35 ns;
	    Tirr	: time		:= 35 ns;
	    Tias	: time		:= 35 ns;
	    Tisw	: time		:= 35 ns;
	    Tisr	: time		:= 35 ns;
	    Twh		: time		:= 12 ns;
	    Twl		: time		:= 12 ns;
	    Tco		: time		:= 20 ns;
	    Ts		: time		:= 12 ns;
	    Th		: time		:=  8 ns;
	    Toar	: time		:= 20 ns;
	    Torw	: time		:= 20 ns;
	    Torr	: time		:= 20 ns;
	    Toas	: time		:= 20 ns;
	    Tosw	: time		:= 20 ns;
	    Tosr	: time		:= 20 ns;
	    Tpzx	: time		:= 20 ns;
	    Tpxz	: time		:= 20 ns);
	port (
	    x1		: in	std_logic;
	    x2		: in	std_logic;
	    clk		: in	std_logic;
	    iclk	: in	std_logic;
	    oe		: in	std_logic;
	    as		: in	std_logic;
	    ar		: in	std_logic;
	    ias		: in	std_logic;
	    iar		: in	std_logic;
	    qfb		: out	std_logic;
	    y		: inout	std_logic;
	    qifb	: out	std_logic);
    end component;

    component c335m
	generic (
	    registered	: reg_def	:= reg;
	    bta_sel	: fb_type	:= xreg;
	    Tpd		: time		:= 15 ns;
	    Twh		: time		:=  5 ns;
	    Twl		: time		:=  5 ns;
	    Tis		: time		:=  2 ns;
	    Tih		: time		:=  2 ns;
	    Tico	: time		:= 18 ns;
	    Tpzx	: time		:= 12 ns;
	    Tpxz	: time		:= 12 ns;
	    Ts		: time		:=  9 ns;
	    Th		: time		:=  0 ns;
	    Tco		: time		:= 10 ns;
	    Tco2	: time		:= 18 ns);
	port (
	    x1		: in  	std_logic;
	    x2		: in  	std_logic;
	    clk		: in  	std_logic;
	    iclk	: in  	std_logic;
	    ss		: in  	std_logic;
	    sr		: in  	std_logic;
	    oe		: in  	std_logic;
	    qfb		: out 	std_logic;
	    fb		: out 	std_logic;
	    y		: inout	std_logic);
    end component;

    component c335h
	generic (
	    Tpd		: time		:= 15 ns;
	    Twh		: time		:=  5 ns;
	    Twl		: time		:=  5 ns;
	    Tis		: time		:=  2 ns;
	    Tih		: time		:=  2 ns;
	    Tico	: time		:= 18 ns;
	    Tpzx	: time		:= 12 ns;
	    Tpxz	: time		:= 12 ns;
	    Ts		: time		:=  9 ns;
	    Th		: time		:=  0 ns;
	    Tco		: time		:= 10 ns;
	    Tco2	: time		:= 18 ns);
	port (
	    x1		: in	std_logic;
	    x2		: in	std_logic;
	    clk		: in	std_logic;
	    ss		: in	std_logic;
	    sr		: in	std_logic;
	    qfb		: out	std_logic);					
    end component;

    component c335ireg
	generic (
	    iregister	: reg_def	:= reg;	
	    Tpd		: time		:= 15 ns;
	    Twh		: time		:=  5 ns;
	    Twl		: time		:=  5 ns;
	    Tis		: time		:=  2 ns;
	    Tih		: time		:=  2 ns;
	    Tico	: time		:= 18 ns;
	    Tpzx	: time		:= 12 ns;
	    Tpxz	: time		:= 12 ns;
	    Ts		: time		:=  9 ns;
	    Th		: time		:=  0 ns;
	    Tco		: time		:= 10 ns;
	    Tco2	: time		:= 18 ns);
	port (
	    d		: in	std_logic;
	    iclk	: in	std_logic;
	    fb		: out	std_logic);
    end component;

    component c335ckmx
	generic (
	    Tpd		: time		:= 15 ns;
	    Twh		: time		:=  5 ns;
	    Twl		: time		:=  5 ns;
	    Tis		: time		:=  2 ns;
	    Tih		: time		:=  2 ns;
	    Tico	: time		:= 18 ns;
	    Tpzx	: time		:= 12 ns;
	    Tpxz	: time		:= 12 ns;
	    Ts		: time		:=  9 ns;
	    Th		: time		:=  0 ns;
	    Tco		: time		:= 10 ns;
	    Tco2	: time		:= 18 ns);
	port (
	    clksrc	: in	std_logic;
	    clk		: out	std_logic);
    end component;

    component c34xm
	generic (
	    Tin		: time		:=  7 ns;
	    Texp	: time		:= 14 ns;
	    Tpia	: time		:= 16 ns;
	    Tlac	: time		:= 12 ns;
	    Tlad	: time		:= 14 ns;
	    Tic		: time		:= 16 ns;
	    Tics	: time		:=  2 ns;
	    Tclr	: time		:=  6 ns;
	    Tpre	: time		:=  6 ns;
	    Trsu	: time		:=  8 ns;
	    Trh		: time		:=  8 ns;
	    Tcomb	: time		:=  4 ns;
	    Tlatch	: time		:=  4 ns;
	    Trd		: time		:=  2 ns;
	    Tio		: time		:=  6 ns;
	    Tod		: time		:=  5 ns;
	    Txz		: time		:= 11 ns;
	    Tzx		: time		:= 11 ns;
	    Tfd		: time		:=  1 ns;
	    Tpcw	: time 		:=  6 ns;
	    Tpcr	: time		:=  6 ns;
	    Tch		: time		:= 10 ns;
	    Tcl		: time		:= 10 ns);
	port (
	    x1		: in	std_logic;
	    x2		: in	std_logic;
	    as		: in	std_logic;
	    ar		: in	std_logic;
	    clkpt	: in	std_logic;
	    clklab	: in	std_logic;
	    clksel	: in	std_logic;
	    oe		: in	std_logic;
	    y		: inout	std_logic;
	    qfb		: out	std_logic;
	    yfb		: out	std_logic);
    end component;

    component c34xh
	generic (
	    Tin		: time		:=  7 ns;
	    Texp	: time		:= 14 ns;
	    Tpia	: time		:= 16 ns;
	    Tlac	: time		:= 12 ns;
	    Tlad	: time		:= 14 ns;
	    Tic		: time		:= 16 ns;
	    Tics	: time		:=  2 ns;
	    Tclr	: time		:=  6 ns;
	    Tpre	: time		:=  6 ns;
	    Trsu	: time		:=  8 ns;
	    Trh		: time		:=  8 ns;
	    Tcomb	: time		:=  4 ns;
	    Tlatch	: time		:=  4 ns;
	    Trd		: time		:=  2 ns;
	    Tio		: time		:=  6 ns;
	    Tod		: time		:=  5 ns;
	    Txz		: time		:= 11 ns;
	    Tzx		: time		:= 11 ns;
	    Tfd		: time		:=  1 ns;
	    Tpcw	: time 		:=  6 ns;
	    Tpcr	: time		:=  6 ns;
	    Tch		: time		:= 10 ns;
	    Tcl		: time		:= 10 ns);
	port (
	    x1		: in	std_logic;
	    x2		: in	std_logic;
	    as		: in	std_logic;
	    ar		: in	std_logic;
	    clkpt	: in	std_logic;
	    clklab	: in	std_logic;
	    clksel	: in	std_logic;
	    exp		: in	std_logic; 
	    qfb		: out	std_logic);
    end component;

    component c34xexp
	generic (
	    Tin		: time		:=  7 ns;
	    Texp	: time		:= 14 ns;
	    Tpia	: time		:= 16 ns;
	    Tlac	: time		:= 12 ns;
	    Tlad	: time		:= 14 ns;
	    Tic		: time		:= 16 ns;
	    Tics	: time		:=  2 ns;
	    Tclr	: time		:=  6 ns;
	    Tpre	: time		:=  6 ns;
	    Trsu	: time		:=  8 ns;
	    Trh		: time		:=  8 ns;
	    Tcomb	: time		:=  4 ns;
	    Tlatch	: time		:=  4 ns;
	    Trd		: time		:=  2 ns;
	    Tio		: time		:=  6 ns;
	    Tod		: time		:=  5 ns;
	    Txz		: time		:= 11 ns;
	    Tzx		: time		:= 11 ns;
	    Tfd		: time		:=  1 ns;
	    Tpcw	: time 		:=  6 ns;
	    Tpcr	: time		:=  6 ns;
	    Tch		: time		:= 10 ns;
	    Tcl		: time		:= 10 ns);
	port (
	    x		: in	std_logic;
	    expsrc	: in	std_logic;
	    exp		: in	std_logic;
	    fb		: out	std_logic);
    end component;

    component c34xin
	generic (
	    Tin		: time		:=  7 ns;
	    Texp	: time		:= 14 ns;
	    Tpia	: time		:= 16 ns;
	    Tlac	: time		:= 12 ns;
	    Tlad	: time		:= 14 ns;
	    Tic		: time		:= 16 ns;
	    Tics	: time		:=  2 ns;
	    Tclr	: time		:=  6 ns;
	    Tpre	: time		:=  6 ns;
	    Trsu	: time		:=  8 ns;
	    Trh		: time		:=  8 ns;
	    Tcomb	: time		:=  4 ns;
	    Tlatch	: time		:=  4 ns;
	    Trd		: time		:=  2 ns;
	    Tio		: time		:=  6 ns;
	    Tod		: time		:=  5 ns;
	    Txz		: time		:= 11 ns;
	    Tzx		: time		:= 11 ns;
	    Tfd		: time		:=  1 ns;
	    Tpcw	: time 		:=  6 ns;
	    Tpcr	: time		:=  6 ns;
	    Tch		: time		:= 10 ns;
	    Tcl		: time		:= 10 ns);
	port (
	    x		: in	std_logic;
	    fb		: out	std_logic);
    end component;

    component c34xpia 
	generic (
	    Tin		: time		:=  7 ns;
	    Texp	: time		:= 14 ns;
	    Tpia	: time		:= 16 ns;
	    Tlac	: time		:= 12 ns;
	    Tlad	: time		:= 14 ns;
	    Tic		: time		:= 16 ns;
	    Tics	: time		:=  2 ns;
	    Tclr	: time		:=  6 ns;
	    Tpre	: time		:=  6 ns;
	    Trsu	: time		:=  8 ns;
	    Trh		: time		:=  8 ns;
	    Tcomb	: time		:=  4 ns;
	    Tlatch	: time		:=  4 ns;
	    Trd		: time		:=  2 ns;
	    Tio		: time		:=  6 ns;
	    Tod		: time		:=  5 ns;
	    Txz		: time		:= 11 ns;
	    Tzx		: time		:= 11 ns;
	    Tfd		: time		:=  1 ns;
	    Tpcw	: time 		:=  6 ns;
	    Tpcr	: time		:=  6 ns;
	    Tch		: time		:= 10 ns;
	    Tcl		: time		:= 10 ns);
	port (
	    x		: in	std_logic;
	    fb		: out	std_logic);
    end component;

    component c34xexin 
	generic (
	    Tin		: time		:=  7 ns;
	    Texp	: time		:= 14 ns;
	    Tpia	: time		:= 16 ns;
	    Tlac	: time		:= 12 ns;
	    Tlad	: time		:= 14 ns;
	    Tic		: time		:= 16 ns;
	    Tics	: time		:=  2 ns;
	    Tclr	: time		:=  6 ns;
	    Tpre	: time		:=  6 ns;
	    Trsu	: time		:=  8 ns;
	    Trh		: time		:=  8 ns;
	    Tcomb	: time		:=  4 ns;
	    Tlatch	: time		:=  4 ns;
	    Trd		: time		:=  2 ns;
	    Tio		: time		:=  6 ns;
	    Tod		: time		:=  5 ns;
	    Txz		: time		:= 11 ns;
	    Tzx		: time		:= 11 ns;
	    Tfd		: time		:=  1 ns;
	    Tpcw	: time 		:=  6 ns;
	    Tpcr	: time		:=  6 ns;
	    Tch		: time		:= 10 ns;
	    Tcl		: time		:= 10 ns);
	port (
	    x		: in	std_logic;
	    expsrc	: in	std_logic;
	    exp		: in	std_logic;
	    fb		: out	std_logic);
    end component;

    component c34xckmx 
	generic (
	    Tin		: time		:=  7 ns;
	    Texp	: time		:= 14 ns;
	    Tpia	: time		:= 16 ns;
	    Tlac	: time		:= 12 ns;
	    Tlad	: time		:= 14 ns;
	    Tic		: time		:= 16 ns;
	    Tics	: time		:=  2 ns;
	    Tclr	: time		:=  6 ns;
	    Tpre	: time		:=  6 ns;
	    Trsu	: time		:=  8 ns;
	    Trh		: time		:=  8 ns;
	    Tcomb	: time		:=  4 ns;
	    Tlatch	: time		:=  4 ns;
	    Trd		: time		:=  2 ns;
	    Tio		: time		:=  6 ns;
	    Tod		: time		:=  5 ns;
	    Txz		: time		:= 11 ns;
	    Tzx		: time		:= 11 ns;
	    Tfd		: time		:=  1 ns;
	    Tpcw	: time 		:=  6 ns;
	    Tpcr	: time		:=  6 ns;
	    Tch		: time		:= 10 ns;
	    Tcl		: time		:= 10 ns);
	port (
	    x		: in	std_logic;
	    oe		: in	std_logic;
	    fb		: out	std_logic);
    end component;

    component c37xm
	generic (
	    bsel	: polarity	:= ninv;
	    tCLK	: time		:=  4000 ps;
	    tIRD	: time		:=  1000 ps;
	    tICOMB	: time		:=  3000 ps;
	    tILAT	: time		:=  5500 ps;
	    tIRSU	: time		:=  6000 ps;
	    tIRH	: time		:=  2000 ps;
	    tSOP	: time		:=  1500 ps;
	    tORD	: time		:=  1000 ps;
	    tOCOMB	: time		:=  3000 ps;
	    tOLAT	: time		:=  5500 ps;
	    tORSU	: time		:=  4500 ps;
	    tORH	: time		:=  0000 ps;
	    tOD		: time		:=  1000 ps;
	    tXZ		: time		:=  8500 ps;
	    tZX		: time		:=  8500 ps;
	    tFB		: time		:=  0000 ps;
	    tRST	: time		:=  8500 ps;
	    tPST	: time		:=  8500 ps;
	    tWL		: time		:=  2500 ps;
	    tWH		: time		:=  2500 ps;
	    tRW		: time		:=  8000 ps;
	    tRR		: time		:= 10000 ps;
	    tPW		: time		:=  8000 ps;
	    tPR		: time		:= 10000 ps;
	    tVCCO	: time		:=     0 ps);
	port (
	    x		: in	std_logic;
	    oe		: in	std_logic;
	    y		: inout	std_logic;
	    fb		: out	std_logic);
    end component;

    component c37xinp
	generic (
	    iregister	: ireg_type	:= ireg;
	    tCLK	: time		:=  4000 ps;
	    tIRD	: time		:=  1000 ps;
	    tICOMB	: time		:=  3000 ps;
	    tILAT	: time		:=  5500 ps;
	    tIRSU	: time		:=  6000 ps;
	    tIRH	: time		:=  2000 ps;
	    tSOP	: time		:=  1500 ps;
	    tORD	: time		:=  1000 ps;
	    tOCOMB	: time		:=  3000 ps;
	    tOLAT	: time		:=  5500 ps;
	    tORSU	: time		:=  4500 ps;
	    tORH	: time		:=  0000 ps;
	    tOD		: time		:=  1000 ps;
	    tXZ		: time		:=  8500 ps;
	    tZX		: time		:=  8500 ps;
	    tFB		: time		:=  0000 ps;
	    tRST	: time		:=  8500 ps;
	    tPST	: time		:=  8500 ps;
	    tWL		: time		:=  2500 ps;
	    tWH		: time		:=  2500 ps;
	    tRW		: time		:=  8000 ps;
	    tRR		: time		:= 10000 ps;
	    tPW		: time		:=  8000 ps;
	    tPR		: time		:= 10000 ps;
	    tVCCO	: time		:=     0 ps);
	port (
	    d		: in	std_logic;
	    clk		: in	std_logic;
	    fb		: out	std_logic);
    end component;

    component c37xoreg
	generic (
	    oregister	: oreg_type	:= dreg;
	    source	: src_type	:= src_ptm;
	    tCLK	: time		:=  4000 ps;
	    tIRD	: time		:=  1000 ps;
	    tICOMB	: time		:=  3000 ps;
	    tILAT	: time		:=  5500 ps;
	    tIRSU	: time		:=  6000 ps;
	    tIRH	: time		:=  2000 ps;
	    tSOP	: time		:=  1500 ps;
	    tORD	: time		:=  1000 ps;
	    tOCOMB	: time		:=  3000 ps;
	    tOLAT	: time		:=  5500 ps;
	    tORSU	: time		:=  4500 ps;
	    tORH	: time		:=  0000 ps;
	    tOD		: time		:=  1000 ps;
	    tXZ		: time		:=  8500 ps;
	    tZX		: time		:=  8500 ps;
	    tFB		: time		:=  0000 ps;
	    tRST	: time		:=  8500 ps;
	    tPST	: time		:=  8500 ps;
	    tWL		: time		:=  2500 ps;
	    tWH		: time		:=  2500 ps;
	    tRW		: time		:=  8000 ps;
	    tRR		: time		:= 10000 ps;
	    tPW		: time		:=  8000 ps;
	    tPR		: time		:= 10000 ps;
	    tVCCO	: time		:=     0 ps);
	port (
	    as		: in	std_logic;
	    x		: in	std_logic;
	    clk		: in	std_logic;
	    ar		: in	std_logic;
	    fb		: out	std_logic;
	    q		: inout	std_logic);
    end component;

    component c37xprod
	generic (
	    tCLK	: time		:=  4000 ps;
	    tIRD	: time		:=  1000 ps;
	    tICOMB	: time		:=  3000 ps;
	    tILAT	: time		:=  5500 ps;
	    tIRSU	: time		:=  6000 ps;
	    tIRH	: time		:=  2000 ps;
	    tSOP	: time		:=  1500 ps;
	    tORD	: time		:=  1000 ps;
	    tOCOMB	: time		:=  3000 ps;
	    tOLAT	: time		:=  5500 ps;
	    tORSU	: time		:=  4500 ps;
	    tORH	: time		:=  0000 ps;
	    tOD		: time		:=  1000 ps;
	    tXZ		: time		:=  8500 ps;
	    tZX		: time		:=  8500 ps;
	    tFB		: time		:=  0000 ps;
	    tRST	: time		:=  8500 ps;
	    tPST	: time		:=  8500 ps;
	    tWL		: time		:=  2500 ps;
	    tWH		: time		:=  2500 ps;
	    tRW		: time		:=  8000 ps;
	    tRR		: time		:= 10000 ps;
	    tPW		: time		:=  8000 ps;
	    tPR		: time		:= 10000 ps;
	    tVCCO	: time		:=     0 ps);
	port (
	    x		: in	std_logic;
	    fb		: out	std_logic);
    end component;

    component c37xclk
	generic (
	    bsel	: polarity	:= ninv;
	    tCLK	: time		:=  4000 ps;
	    tIRD	: time		:=  1000 ps;
	    tICOMB	: time		:=  3000 ps;
	    tILAT	: time		:=  5500 ps;
	    tIRSU	: time		:=  6000 ps;
	    tIRH	: time		:=  2000 ps;
	    tSOP	: time		:=  1500 ps;
	    tORD	: time		:=  1000 ps;
	    tOCOMB	: time		:=  3000 ps;
	    tOLAT	: time		:=  5500 ps;
	    tORSU	: time		:=  4500 ps;
	    tORH	: time		:=  0000 ps;
	    tOD		: time		:=  1000 ps;
	    tXZ		: time		:=  8500 ps;
	    tZX		: time		:=  8500 ps;
	    tFB		: time		:=  0000 ps;
	    tRST	: time		:=  8500 ps;
	    tPST	: time		:=  8500 ps;
	    tWL		: time		:=  2500 ps;
	    tWH		: time		:=  2500 ps;
	    tRW		: time		:=  8000 ps;
	    tRR		: time		:= 10000 ps;
	    tPW		: time		:=  8000 ps;
	    tPR		: time		:= 10000 ps;
	    tVCCO	: time		:=     0 ps);
	port (
	    x		: in	std_logic;
	    fb		: out	std_logic);
    end component;

    component c37xmux
	generic (
	    tCLK	: time		:=  4000 ps;
	    tIRD	: time		:=  1000 ps;
	    tICOMB	: time		:=  3000 ps;
	    tILAT	: time		:=  5500 ps;
	    tIRSU	: time		:=  6000 ps;
	    tIRH	: time		:=  2000 ps;
	    tSOP	: time		:=  1500 ps;
	    tORD	: time		:=  1000 ps;
	    tOCOMB	: time		:=  3000 ps;
	    tOLAT	: time		:=  5500 ps;
	    tORSU	: time		:=  4500 ps;
	    tORH	: time		:=  0000 ps;
	    tOD		: time		:=  1000 ps;
	    tXZ		: time		:=  8500 ps;
	    tZX		: time		:=  8500 ps;
	    tFB		: time		:=  0000 ps;
	    tRST	: time		:=  8500 ps;
	    tPST	: time		:=  8500 ps;
	    tWL		: time		:=  2500 ps;
	    tWH		: time		:=  2500 ps;
	    tRW		: time		:=  8000 ps;
	    tRR		: time		:= 10000 ps;
	    tPW		: time		:=  8000 ps;
	    tPR		: time		:= 10000 ps;
	    tVCCO	: time		:=     0 ps);
	port (
	    x		: in	std_logic;
	    fb		: out	std_logic);
    end component;

    component c37km
	generic (
	    bsel	: polarity	:= ninv;
	    Ticomb	: time		:= 1000 ps;
	    Tod		: time		:= 2000 ps;
	    Txz		: time		:= 5500 ps;
	    Tzx		: time		:= 5500 ps;
	    Tsl		: time		:= 2000 ps;
	    slsel	: slw_type	:= fast);
	port (
	    x		: in	std_logic;
	    oe		: in	std_logic;
	    y		: inout	std_logic;
	    fb		: out	std_logic);
    end component;

    component c37kinp
	generic (
	    iregister	: ireg_type	:= ireg;
	    Tclk	: time		:= 2000 ps;
	    Tird	: time		:=  500 ps;
	    Ticomb	: time		:= 1000 ps;
	    Tilat	: time		:= 3500 ps;
	    Tirsu	: time		:= 4000 ps;
	    Tirh	: time		:= 0000 ps;
	    Twl		: time		:= 2500 ps;
	    Twh		: time		:= 2500 ps);
	port (
	    d		: in	std_logic;
	    clk		: in	std_logic;
	    fb		: out	std_logic);
    end component;

    component c37koreg
	generic (
	    oregister	: oreg_type	:= dreg;
	    source	: src_type	:= src_ptm;
	    Tclk	: time		:= 2000 ps;
	    Tird	: time		:=  500 ps;
	    Tilat	: time		:= 3500 ps;
	    Tirsu	: time		:= 4000 ps;
	    Tirh	: time		:=    0 ps;
	    Tord	: time		:= 1000 ps;
	    Tocomb	: time		:=    0 ps;
	    Tolat	: time		:= 2500 ps;
	    Torsu	: time		:= 1000 ps;
	    Torh	: time		:= 3500 ps;
	    Tfb		: time		:=    0 ps;
	    Trst	: time		:= 4500 ps;
	    Tpst	: time		:= 4500 ps;
	    Twl		: time		:= 2500 ps;
	    Twh		: time		:= 2500 ps;
	    Trw		: time		:= 8000 ps;
	    Trr		: time		:=10000 ps;
	    Tpw		: time		:= 8000 ps;
	    Tpr		: time		:=10000 ps;
	    Tirsupt	: time		:= 3500 ps;
	    Tirhpt	: time		:= 1000 ps;
	    Torsupt	: time		:= 2500 ps;
	    Torhpt	: time		:= 2500 ps;
	    cksel	: clk_type	:= nopt);
	port (
	    as		: in	std_logic;
	    x		: in	std_logic;
	    clk		: in	std_logic;
	    ar		: in	std_logic;
	    fb		: out	std_logic;
	    q		: inout	std_logic);
    end component;

    component c37kmux
	generic (
	    Tsop	: time		:= 4500 ps);
	port (
	    x		: in	std_logic;
	    fb		: out	std_logic);
    end component;

    -- Global clock block
    component c39kck
	generic (
	    cfgbits		: Bit_Vector(63 downto 0) := (others => '0');
	    xplPulseWthLo		: time	:= 100 ps;
	    xplPulseWthHi		: time	:= 100 ps;
	    xplMinInputDuty		: positive := 30;
	    xplMaxInputDuty		: positive := 70;
	    xplJitterUncertainty	: time	:= 100 ps;
	    xplZeroFBUncertainty	: time	:= 100 ps;
	    xplTreeFBUncertainty	: time	:= 100 ps;
	    xplMinPinClkPeriod		: time	:= 100 ns;
	    xplMaxPinClkPeriod		: time	:= 1000 ns;
	    xplLocktime			: time	:= 100 ns;
	    xplClockTreeOffset		: time	:= 100 ps;
	    xckPin2GClkDirect		: time	:= 100 ps;
	    xplSpreadFreqPercent	: real	:= 0.0;
	    xplSpreadFreqKHz		: real	:= 0.0);
	port (
	    clk		: in	std_logic_vector(3 downto 0);
	    nios	: in	std_logic;
	    lock	: out	std_logic;
	    glclk	: out	std_logic_vector(3 downto 0));
    end component;

    -- Channel memory FIFO
    component c39kcf
	generic (
	    cfgbits		: Bit_Vector(45 downto 0) := (others => '0');
	    memdata			: chmem	:= (others => "00000000");
	    xcmfClockWthCy		: time	:= 100 ps;
	    xcmfClockWthHi		: time	:= 100 ps;
	    xcmfClockWthLo		: time	:= 100 ps;
	    xcmfDinAtClkWrSetup		: time	:= 100 ps;
	    xcmfDinAtClkWrHold		: time	:= 100 ps;
	    xcmfEnxAtClockSetup		: time	:= 100 ps;
	    xcmfEnxAtClockHold		: time	:= 100 ps;
	    xcmfEfbinAtClkRdSetup	: time	:= 100 ps;
	    xcmfEfbinAtClkRdHold	: time	:= 100 ps;
	    xcmfHfbinAtClkRdSetup	: time	:= 100 ps;
	    xcmfHfbinAtClkRdHold	: time	:= 100 ps;
	    xcmfEfbinAtClkWrSetup	: time	:= 100 ps;
	    xcmfEfbinAtClkWrHold	: time	:= 100 ps;
	    xcmfHfbinAtClkWrSetup	: time	:= 100 ps;
	    xcmfHfbinAtClkWrHold	: time	:= 100 ps;
	    xcmfMrbWthLo		: time	:= 100 ps;
	    xcmfMrbRcr			: time	:= 100 ps;
	    xcmfRdWrSkewEfb		: time	:= 100 ps;
	    xcmfRdWrSkewHfb		: time	:= 100 ps;
	    xcmfRdWrSkewPafeb		: time	:= 100 ps;
	    xcmfDoutRegReWthHi		: time	:= 100 ps;
	    xcmfDoutRegReRcr		: time	:= 100 ps;
	    xcmfClkWr2Flagout		: time	:= 100 ps;
	    xcmfClkRd2Flagout		: time	:= 100 ps;
	    xcmfMrb2output		: time	:= 100 ps;
	    xcmfClock2Dout		: time	:= 100 ps;
	    xcmfReset2Dout		: time	:= 100 ps);
	port (
	    din		: in	std_logic_vector(7 downto 0);
	    dout	: inout	std_logic_vector(7 downto 0);
	    enr		: in	std_logic;             
	    enw		: in	std_logic;             
	    ckr		: in	std_logic;
	    ckw		: in	std_logic;
	    mrb		: in	std_logic := '1';             
	    efb		: inout	std_logic;
	    hfb		: inout	std_logic;
	    pafeb	: out	std_logic);
    end component;

    -- Channel memory RAM
    component c39kcm
	generic (
	    cfgbits	 	: Bit_Vector(45 downto 0) := (others => '0');
	    memdata	 		: chmem	:= (others => "00000000");
	    xcmReadAddrWthHi		: time	:= 100 ps;
	    xcmWritAddrWthHi		: time	:= 100 ps;
	    xcmWriEnaWthHi		: time	:= 100 ps;
	    xcmAddrAtWriEnaFallSetup	: time	:= 100 ps;
	    xcmAddrAtWriEnaRiseSetup	: time	:= 100 ps;
	    xcmAddrAtWriEnaFallHold	: time	:= 100 ps;
	    xcmDinAtWriEnaFallSetup	: time	:= 100 ps;
	    xcmDinAtWriEnaFallHold	: time	:= 100 ps;
	    xcmAddr2DoutRegD		: time	:= 100 ps;
	    xcmWriEna2DoutRegD		: time	:= 100 ps;
	    xcmDin2DoutRegD		: time	:= 100 ps;
	    xcmDoutRegD2Dout		: time	:= 100 ps;
	    xcmClkinWthCy		: time	:= 100 ps;
	    xcmClkinWthHi		: time	:= 100 ps;
	    xcmClkinWthLo		: time	:= 100 ps;
	    xcmAddrAtClkinSetup		: time	:= 100 ps;
	    xcmAddrAtClkinHold		: time	:= 100 ps;
	    xcmWriEnaAtClkinSetup	: time	:= 100 ps;
	    xcmWriEnaAtClkinHold	: time	:= 100 ps;
	    xcmDinAtClkinSetup		: time	:= 100 ps;
	    xcmDinAtClkinHold		: time	:= 100 ps;
	    xcmClkin2DoutRegD		: time	:= 100 ps;
	    xcmDoutRegCkWthCy		: time	:= 100 ps;
	    xcmDoutRegCkWthHi		: time	:= 100 ps;
	    xcmDoutRegCkWthLo		: time	:= 100 ps;
	    xcmDoutRegSetup		: time	:= 100 ps;
	    xcmDoutRegHold		: time	:= 100 ps;
	    xcmDoutRegReWthHi		: time	:= 100 ps;
	    xcmDoutRegReRcr		: time	:= 100 ps;
	    xcmReset2Dout		: time	:= 100 ps;
	    xcmClkout2Dout		: time	:= 100 ps;
	    xcmAddrTransDetect		: time	:= 800 ps);
	port (
	    din_a	: in	std_logic_vector( 7 downto 0);
	    din_b	: in	std_logic_vector( 7 downto 0);
	    addr_a	: in	std_logic_vector(11 downto 0);
	    addr_b	: in	std_logic_vector(11 downto 0);
	    we_a	: in	std_logic;
	    we_b	: in	std_logic;
	    iclk_a	: in	std_logic := '0';
	    iclk_b	: in	std_logic := '0';
	    oclk_a	: in	std_logic := '0';
	    oclk_b	: in	std_logic := '0';
	    reset_a	: in	std_logic := '0';
	    reset_b	: in	std_logic := '0';
	    addr_matchb	: out	std_logic;
	    dout_a	: out	std_logic_vector( 7 downto 0);
	    dout_b	: out	std_logic_vector( 7 downto 0));
    end component;

    -- Cluster memory RAM
    component c39kcr
	generic (
	    cfgbits		: Bit_Vector(13 downto 0) := (others => '0');
	    memdata			: clmem	:= (others => "00000000");
	    xcrReadAddrWthHi		: time	:= 100 ps;
	    xcrWritAddrWthHi		: time	:= 100 ps;
	    xcrWriEnaWthHi		: time	:= 100 ps;
	    xcrAddrAtWriEnaFallSetup	: time	:= 100 ps;
	    xcrAddrAtWriEnaRiseSetup	: time	:= 100 ps;
	    xcrAddrAtWriEnaFallHold	: time	:= 100 ps;
	    xcrDinAtWriEnaFallSetup	: time	:= 100 ps;
	    xcrDinAtWriEnaFallHold	: time	:= 100 ps;
	    xcrAddr2DoutRegD		: time	:= 100 ps;
	    xcrWriEna2DoutRegD		: time	:= 100 ps;
	    xcrDin2DoutRegD		: time	:= 100 ps;
	    xcrDoutRegD2Dout		: time	:= 100 ps;
	    xcrClkinWthCy		: time	:= 100 ps;
	    xcrClkinWthHi		: time	:= 100 ps;
	    xcrClkinWthLo		: time	:= 100 ps;
	    xcrAddrAtClkinSetup		: time	:= 100 ps;
	    xcrAddrAtClkinHold		: time	:= 100 ps;
	    xcrWriEnaAtClkinSetup	: time	:= 100 ps;
	    xcrWriEnaAtClkinHold	: time	:= 100 ps;
	    xcrDinAtClkinSetup		: time	:= 100 ps;
	    xcrDinAtClkinHold		: time	:= 100 ps;
	    xcrClkin2DoutRegD		: time	:= 100 ps;
	    xcrDoutRegCkWthHi		: time	:= 100 ps;
	    xcrDoutRegCkWthLo		: time	:= 100 ps;
	    xcrDoutRegCkWthCy		: time	:= 100 ps;
	    xcrDoutRegSetup		: time	:= 100 ps;
	    xcrDoutRegHold		: time	:= 100 ps;
	    xcrDoutRegReRcr		: time	:= 100 ps;
	    xcrDoutRegReWthHi		: time	:= 100 ps;
	    xcrClkout2Dout		: time	:= 100 ps;
	    xcrReset2Dout		: time	:= 100 ps;
	    xcrAddrTransDetect		: time	:= 800 ps);
	port (
	    din		: in	std_logic_vector( 7 downto 0);
	    addr	: in	std_logic_vector(12 downto 0);
	    we		: in	std_logic;
	    iclk	: in	std_logic := '0';
	    oclk	: in	std_logic := '0';
	    reset	: in	std_logic := '0';
	    dout	: out	std_logic_vector( 7 downto 0));
    end component;

    -- Macro-cell Block
    component c39kmc
	generic (
	    cfgbits		: Bit_Vector(11 downto 0) := (others => '0');
	    xlbRegSetup			: time	:= 100 ps;
	    xlbRegHold			: time	:= 100 ps;
	    xlbRegCkWthHi		: time	:= 100 ps;
	    xlbRegCkWthLo		: time	:= 100 ps;
	    xlbRegCkWthCy		: time	:= 100 ps;
	    xlbRegPrRcr			: time	:= 100 ps;
	    xlbRegPrWthHi		: time	:= 100 ps;
	    xlbRegReRcr			: time	:= 100 ps;
	    xlbRegReWthHi		: time	:= 100 ps;
	    xlbSelin2Selout		: time	:= 100 ps;
	    xlbCpt2Selout		: time	:= 100 ps;
	    xlbCpt2RegD			: time	:= 100 ps;
	    xlbEqn2RegD			: time	:= 100 ps;
	    xlbSelin2RegD		: time	:= 100 ps;
	    xlbRegQ2RegD		: time	:= 100 ps;
	    xlbRegD2ToPIM		: time	:= 100 ps;
	    xlbRegCk2ToPIM		: time	:= 100 ps;
	    xlbRegPr2ToPIM		: time	:= 100 ps;
	    xlbRegRe2ToPIM		: time	:= 100 ps);
	port (
	    selin	: in	std_logic;
	    cpt		: in	std_logic_vector(1 downto 0);
	    set		: in	std_logic;
	    clr		: in	std_logic;
	    clk		: in	std_logic;
	    din		: in	std_logic;
	    selout	: out	std_logic;
	    qout	: out	std_logic);
    end component;

    -- I/O Block
    component c39kio
	generic (
	    cfgbits		: Bit_Vector(35 downto 0) := (others => '0');
	    xioClockWthHi		: time	:= 100 ps;
	    xioClockWthLo		: time	:= 100 ps;
	    xioClockWthCy		: time	:= 100 ps;
	    xioResetRcr			: time	:= 100 ps;
	    xioResetWthHi		: time	:= 100 ps;
	    xioIoRegSetup		: time	:= 100 ps;
	    xioIoRegHold		: time	:= 100 ps;
	    xioIoRegEnSup		: time	:= 100 ps;
	    xioIoRegEnHld		: time	:= 100 ps;
	    xioOeRegSetup		: time	:= 100 ps;
	    xioOeRegHold		: time	:= 100 ps;
	    xioFromChip2Pin		: time	:= 100 ps;
	    xioFromChip2IoRegD		: time	:= 100 ps;
	    xioIoRegCk2Pin		: time	:= 100 ps;
	    xioIoRegRe2Pin		: time	:= 100 ps;
	    xioIoRegRe2ToChip		: time	:= 100 ps;
	    xioOeRegCk2PinEA		: time	:= 100 ps;
	    xioOeRegCk2PinER		: time	:= 100 ps;
	    xioOeRegRe2PinER		: time	:= 100 ps;
	    xiooutEna2PinEA		: time	:= 100 ps;
	    xiooutEna2PinER		: time	:= 100 ps;
	    xioPin2IoRegD		: time	:= 100 ps;
	    xioIoRegCk2ToChip		: time	:= 100 ps;
	    xioPin2ToChip		: time	:= 100 ps;
	    xioAddOslow			: time	:= 100 ps;
	    xioAddEAslow		: time	:= 100 ps;
	    xioAddERslow		: time	:= 100 ps;
	    xioAdd			: time	:= 100 ps);
	port (
	    oe		: in	std_logic;
	    din		: in	std_logic;
	    en		: in	std_logic;
	    clk		: in	std_logic;
	    clr		: in	std_logic;
	    fb		: out	std_logic;
	    iop		: inout	std_logic);
    end component;

    component c25g01serdes
	port(
	    txd		: in	std_logic_vector (15 downto 0);
	    fifo_rstb	: in	std_logic;
	    loop_time	: in	std_logic;
	    diagloop	: in	std_logic;
	    loopa	: in	std_logic;
	    lineloop	: in	std_logic;
	    resetb	: in	std_logic;
	    pwrdnb	: in	std_logic;
	    lockrefb	: in	std_logic;
	    refclk_n	: in	std_logic;
	    refclk_p	: in	std_logic;
	    serial_in_n	: in	std_logic := '0';
	    serial_in_p	: in	std_logic := '1';
	    sd		: in	std_logic := '0';
	    serial_out_n: out	std_logic;
	    serial_out_p: out	std_logic;
	    fifo_err	: out	std_logic;
	    txclk	: out	std_logic;
	    rxd		: out	std_logic_vector (15 downto 0);
	    rxclk	: out	std_logic;
	    lfib	: out	std_logic);
    end component;

    component c2gserdes
	port(
	    txd		: in	std_logic_vector (15 downto 0);
	    fifo_rstb	: in	std_logic;
	    loop_time	: in	std_logic;
	    diagloop	: in	std_logic;
	    loopa	: in	std_logic;
	    lineloop	: in	std_logic;
	    resetb	: in	std_logic;
	    pwrdnb	: in	std_logic;
	    lockrefb	: in	std_logic;
	    refclk_n	: in	std_logic;
	    refclk_p	: in	std_logic;
	    serial_in_n	: in	std_logic := '0';
	    serial_in_p	: in	std_logic := '1';
	    sd		: in	std_logic := '0';
	    serial_out_n: out	std_logic;
	    serial_out_p: out	std_logic;
	    fifo_err	: out	std_logic;
	    txclk	: out	std_logic;
	    rxd		: out	std_logic_vector (15 downto 0);
	    rxclk	: out	std_logic;
	    lfib	: out	std_logic);
    end component;

    component c2gcor
	port (
	    txd		: in  	std_logic_vector (15 downto 0);
	    txclki	: in	std_logic;
	    fifo_rstb	: in	std_logic;
	    loop_time	: in	std_logic;
	    diagloop	: in	std_logic;
	    loopa	: in	std_logic;
	    lineloop	: in	std_logic;
	    resetb	: in	std_logic;
	    pwrdnb	: in	std_logic;
	    lockrefb	: in	std_logic;
	    refclk	: in	std_logic;
	    rd_in	: in	std_logic;
	    sd		: in	std_logic;
	    td_out	: out	std_logic;
	    fifo_err	: inout	std_logic;
	    txclko	: inout	std_logic;
	    rxd		: out	std_logic_vector (15 downto 0):=(others => '0');
	    rxclk	: inout	std_logic;
	    lfib	: out	std_logic;
	    locked	: out 	std_logic);
    end component;

    component c2gffo
	port (
	    data_in	: in	std_logic_vector(15 downto 0);
	    rstb	: in	std_logic;
	    wrclk	: in	std_logic;
	    out_2d	: out	std_logic_vector(15 downto 0);
	    rdclk	: in	std_logic;
	    fifoerr	: out	std_logic;
	    fifoempty	: inout	std_logic);
    end component;

component c15g04serdes

    port (  txda		: in	std_logic_vector(7 downto 0) := (others => '0');
	    txdb		: in	std_logic_vector(7 downto 0) := (others => '0');
	    txdc		: in	std_logic_vector(7 downto 0) := (others => '0');
	    txdd		: in	std_logic_vector(7 downto 0) := (others => '0');
	    txpera		: out	std_logic;
	    txperb		: out	std_logic;
	    txperc		: out	std_logic;
	    txperd		: out	std_logic;
	    txcta		: in	std_logic_vector(1 downto 0) := (others => '0');
	    txctb		: in	std_logic_vector(1 downto 0) := (others => '0');
	    txctc		: in	std_logic_vector(1 downto 0) := (others => '0');
	    txctd		: in	std_logic_vector(1 downto 0) := (others => '0');

	    txclka		: in	std_logic;

	    txclko_p		: out	std_logic;

	    txrate		: in	std_logic;
	    txmode		: in	std_logic_vector(1 downto 0);
	    txcksel		: in	std_logic;
	    txrstb		: in	std_logic;

	    rxda		: out	std_logic_vector(7 downto 0);
	    rxdb		: out	std_logic_vector(7 downto 0);
	    rxdc		: out	std_logic_vector(7 downto 0);
	    rxdd		: out	std_logic_vector(7 downto 0);
	    rxsta		: out	std_logic_vector(2 downto 0);
	    rxstb		: out	std_logic_vector(2 downto 0);
	    rxstc		: out	std_logic_vector(2 downto 0);
	    rxstd		: out	std_logic_vector(2 downto 0);

	    rxrate		: in	std_logic;
	    rfen		: in	std_logic;
	    rxmode		: in	std_logic_vector(1 downto 0);
	    rxcksel		: in	std_logic;
	    framchar		: in	std_logic;
	    rfmode		: in	std_logic;
	    decmode		: in	std_logic;

	    spdsel		: in	std_logic;
	    rxclka_p		: out	std_logic;
	    rxclkb_p		: inout	std_logic;
	    rxclkc_p		: out	std_logic;
	    rxclkd_p		: inout	std_logic;

	    refclk_p		: in	std_logic;
	    refclk_n		: in	std_logic;
	    serial_outa1_p	: out	std_logic;
	    serial_outb1_p	: out	std_logic;
	    serial_outc1_p	: out	std_logic;
	    serial_outd1_p	: out	std_logic;
	    serial_outa2_p	: out	std_logic;
	    serial_outb2_p	: out	std_logic;
	    serial_outc2_p	: out	std_logic;
	    serial_outd2_p	: out	std_logic;
	    serial_ina1_p	: in	std_logic;
	    serial_inb1_p	: in	std_logic;
	    serial_inc1_p	: in	std_logic;
	    serial_ind1_p	: in	std_logic;
	    serial_ina2_p	: in	std_logic;
	    serial_inb2_p	: in	std_logic;
	    serial_inc2_p	: in	std_logic;
	    serial_ind2_p	: in	std_logic;
	    serial_outa1_n	: out	std_logic;
	    serial_outb1_n	: out	std_logic;
	    serial_outc1_n	: out	std_logic;
	    serial_outd1_n	: out	std_logic;
	    serial_outa2_n	: out	std_logic;
	    serial_outb2_n	: out	std_logic;
	    serial_outc2_n	: out	std_logic;
	    serial_outd2_n	: out	std_logic;
	    serial_ina1_n	: in	std_logic;
	    serial_inb1_n	: in	std_logic;
	    serial_inc1_n	: in	std_logic;
	    serial_ind1_n	: in	std_logic;
	    serial_ina2_n	: in	std_logic;
	    serial_inb2_n	: in	std_logic;
	    serial_inc2_n	: in	std_logic;
	    serial_ind2_n	: in	std_logic;
	    insela		: in	std_logic;
	    inselb		: in	std_logic;
	    inselc		: in	std_logic;
	    inseld		: in	std_logic;
	    sdasel		: in	std_logic;
	    lpen		: in	std_logic;
	    oele		: in	std_logic;
	    bistle		: in	std_logic;
	    rxle		: in	std_logic;
	    boe			: in	std_logic_vector(7 downto 0);
	    bondst		: inout	std_logic_vector(1 downto 0);
	    masterb		: in	std_logic;
	    bond_all		: inout	std_logic;
	    bond_inhb		: in	std_logic;
	    lfiab		: out	std_logic;
	    lfibb		: out	std_logic;
	    lficb		: out	std_logic;
	    lfidb		: out	std_logic;
	    trstzb		: in	std_logic);

end component;

end primitive;

package body primitive is

    function to_integer (a	: std_logic_vector) return natural is
	variable tmp	: std_logic_vector(a'length-1 downto 0);
	variable result	: natural := 0;
    begin
	if (a'length < 1) then
	    return 0;
	end if;
	tmp := a;
	for i in tmp'reverse_range loop
	    if tmp(i) = '1' then
		result := result + 2**i;
	    end if;
	end loop;
	return result;
    end to_integer;

    function to_integer (a	: Bit_Vector) return natural is
	variable tmp	: Bit_Vector(a'length-1 downto 0);
	variable result	: natural := 0;
    begin
	if (a'length < 1) then
	    return 0;
	end if;
	tmp := a;
	for i in tmp'reverse_range loop
	    if tmp(i) = '1' then
		result := result + 2**i;
	    end if;
	end loop;
	return result;
    end to_integer;

    function timeAdjust	(time_constraint: time) return time is
    begin
    	if (time_constraint < 0 ns) then
	    return -(time_constraint);
	else
	    return 0 ns;
	end if;
    end timeAdjust;

    -- This is necessary to avoid loss of precision when
    -- convering time to a real number.
    function time_to_real (a : time) return real is

       variable result	: real;
       variable x	: time;
       variable os_count: integer;
       variable us_count: integer;
       variable ns_count: integer;
       variable ps_count: integer;
       variable fs_count: integer;

    begin

       x := a;
       os_count := x / 1 sec;
       x := x - os_count * 1 sec;
       us_count := x / 1 us;
       x := x - us_count * 1 us;
       ns_count := x / 1 ns;
       x := x - ns_count * 1 ns;
       x := x * 1e3;
       ps_count := x / 1 ns;
       x := x - ps_count * 1 ns;
       x := x * 1e3;
       fs_count := x / 1 ns;
       x := x - fs_count * 1 ns;

       result := 0.0;
       result := result + real(fs_count) * 1.0e-15;
       result := result + real(ps_count) * 1.0e-12;
       result := result + real(ns_count) * 1.0e-9;
       result := result + real(us_count) * 1.0e-6;
       result := result + real(os_count);
       return result;
    end time_to_real;

end primitive;

    --	Primitive Entity/Architecture pairs.

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c16v8m IS
    GENERIC (
	registered	: reg_def	:= reg;
	inv_setting	: polarity	:= invt;
	bta_sel		: fb_type	:= xreg;
	Tpd		: TIME		:= 10 ns;
	Ten		: TIME		:= 10 ns;
	Tdis		: TIME		:= 10 ns;
	Tco		: TIME		:=  7 ns;
	Tsu		: TIME		:=  7 ns;
	Th		: TIME		:=  0 ns;
	Twh		: TIME		:=  8 ns;
	Twl		: TIME		:=  8 ns;
	Tcf		: TIME		:=  6 ns);
    PORT (
	d	: IN	std_logic;
	clk	: IN	std_logic;
	oe	: IN	std_logic;
	adj	: IN	std_logic;
	y	: INOUT std_logic;
	fb	: OUT	std_logic;
	yfb	: OUT	std_logic);
END c16v8m;

ARCHITECTURE sim OF c16v8m IS
	SIGNAL	q	: std_logic	:= '0';
	SIGNAL	q_not	: std_logic := '1';
	SIGNAL	d_mod	: std_logic	:= '0';
	SIGNAL	d_pol	: std_logic	:= '0';
	SIGNAL	q_tsu	: std_logic := '0';
	SIGNAL	q_th	: std_logic := '0';
	SIGNAL	q_twh	: std_logic := '0';
	SIGNAL	q_twl	: std_logic := '0';
BEGIN

    -- check for clk setup/hold violations
    PROCESS (clk, d)
	VARIABLE dlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	-- Check to see if it is a registered cell.
	IF (registered = reg) THEN

	    -- setup check
	    IF (clk'event AND (clk = '1')) THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - dlastev) >= Tsu))
		    REPORT
		    "Setup ERROR ON D: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - dlastev) >= Tsu)) THEN
		    q_tsu <= '1';
		    q_tsu <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;

	    -- hold check
	    IF (d'event) then
		ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th))
		    REPORT
		    "Hold ERROR ON D: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th)) THEN
		    q_th <= '1';
		    q_th <= transport '0' after 1 ns;
		END IF;
		dlastev := NOW;
	    END IF;
	END IF;
    END PROCESS;

    -- check clk pulse width
    PROCESS (clk)
	VARIABLE clklastev : TIME := 0 ns;
    BEGIN
	-- Check to see if it is a registered cell.
	IF (registered = reg) THEN
	    IF (clk = '0') THEN
	       ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh))
		    REPORT
		    "Pulse Width (H) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh)) THEN
		    q_twh <= '1'; 
		    q_twh <= transport '0' after 1 ns;
		END IF;
	    ELSIF (clk = '1') THEN
	       ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl))
		    REPORT
		    "Pulse Width (L) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl)) THEN
		    q_twl <= '1'; 
		    q_twl <= transport '0' after 1 ns;
		END IF;
	    END IF;
	    clklastev := NOW;
	END IF;
    END PROCESS;

    -- Simulate the polarity gate.
    PROCESS (d)
    BEGIN
	IF (inv_setting = invt) THEN
	    d_pol <= NOT (d);
	ELSE
	    d_pol <= d;
	END IF;
    END PROCESS;

    -- Simulate the Register.
    PROCESS (clk, q_tsu, q_th, q_twh, q_twl)
    BEGIN
	IF ((q_tsu = '1') OR (q_th = '1') OR (q_twh = '1') OR (q_twl = '1'))THEN
	    q <= 'X' after Tco;
	    q_not <= 'X' after Tcf;
	ELSIF ((clk = '1') AND clk'event) THEN
	    q <= d_pol AFTER Tco;
	    IF (d_pol = '1') THEN
		q_not <= '0' after Tcf;
	    ELSE
		q_not <= '1' after Tcf;
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the register definition mux.
    PROCESS (d_pol, q)
    BEGIN
	IF (registered = comb) THEN
	    d_mod <= d_pol AFTER Tpd;
	ELSIF (registered = reg) THEN
	    d_mod <= q;
	END IF;
    END PROCESS;

    -- Simulate the output driver.
    PROCESS (oe, d_mod)
    BEGIN
	IF (oe'event) THEN
	    IF (oe = '1') THEN
		y <= not d_mod AFTER Ten;
	    ELSE
		y <= 'Z' AFTER Tdis;
	    END IF;
	ELSE
	    IF (oe = '1') THEN
		y <= not d_mod; 
	    ELSE
		y <= 'Z';
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the feedback mux.
    PROCESS (y, q_not, adj)
    BEGIN
	IF (bta_sel = xpin) THEN
	    IF (y = '1') THEN
		fb <= '1';
	    ELSE
		fb <= '0';
	    END IF;
	ELSIF (bta_sel = xreg) THEN
	    fb <= q_not;
	ELSIF (bta_sel = xadj) THEN
	    fb <= adj;
	END IF;
    END PROCESS;

    -- Simulate feedback from Y.
    PROCESS (y)
    BEGIN
	IF (y = '1') THEN                       
	    yfb <= '1';
	ELSE
	    yfb <= '0';
	END IF;
    END PROCESS;

END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c20g10m IS
    GENERIC (
	registered	: reg_def	:= reg;
	inv_setting	: polarity	:= ninv;
	bta_sel		: fb_type	:= xreg;
	Tpd		: TIME		:= 25 ns;
	Tpzx		: TIME		:= 20 ns;
	Tpxz		: TIME		:= 20 ns;
	Tco		: TIME		:= 15 ns;
	Ts		: TIME		:= 15 ns;
	Th		: TIME		:=  0 ns;
	Twh		: TIME		:= 12 ns;
	Twl		: TIME		:= 12 ns);

    PORT (
	    d	: IN	std_logic;
	    clk	: IN	std_logic;
	    oe	: IN	std_logic;
	    y	: INOUT std_logic;
	    fb	: OUT	std_logic);
END c20g10m;

ARCHITECTURE sim OF c20g10m IS
    SIGNAL   	q	: std_logic	:= '0';
    SIGNAL	d_mod	: std_logic	:= '0';
    SIGNAL	d_pol	: std_logic	:= '0';
    SIGNAL	q_ts	: std_logic := '0';
    SIGNAL	q_th	: std_logic := '0';
    SIGNAL	q_twh	: std_logic := '0';
    SIGNAL	q_twl	: std_logic := '0';
BEGIN
    -- check for clk setup/hold violations
    PROCESS (clk, d)
	VARIABLE dlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN

	-- setup check
	IF (clk'event AND (clk = '1')) THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - dlastev) >= Ts))
		REPORT
		"Setup ERROR ON D: Setting output to unknown" 
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - dlastev) >= Ts)) THEN
		q_ts <= '1';
		q_ts <= transport '0' after 1 ns;
	    END IF;
	    clklastev := NOW;
	END IF;

	-- hold check
	IF (d'event) then
	    ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th))
		REPORT
		"Hold ERROR ON D: Setting output to unknown" 
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th)) THEN
		q_th <= '1';
		q_th <= transport '0' after 1 ns;
	    END IF;
	    dlastev := NOW;
	END IF;

    END PROCESS;

    -- check clk pulse width
    PROCESS (clk)
	VARIABLE clklastev : TIME := 0 ns;
    BEGIN
	IF (clk = '0') THEN
	   ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh))
		REPORT
		"Pulse Width (H) ERROR on CLK: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh)) THEN
		q_twh <= '1'; 
		q_twh <= transport '0' after 1 ns;
	    END IF;
	ELSIF (clk = '1') THEN
	   ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl))
		REPORT
		"Pulse Width (L) ERROR on CLK: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl)) THEN
		q_twl <= '1'; 
		q_twl <= transport '0' after 1 ns;
	    END IF;
	END IF;
	clklastev := NOW;
    END PROCESS;

    -- Simulate the Register.
    PROCESS (clk, q_ts, q_th, q_twh, q_twl)
    BEGIN
	IF ((q_ts = '1') OR (q_th = '1') OR (q_twh = '1') OR (q_twl = '1')) THEN
	    q <= 'X' after Tco;
	ELSIF ((clk = '1') AND clk'event) THEN
	    q <= d AFTER Tco;
	END IF;
    END PROCESS;

    -- Simulate the Register Mux.
    PROCESS (q, d)
    BEGIN
	IF (registered = comb) THEN
	    d_mod <= d AFTER Tpd;
	ELSIF (registered = reg) THEN
	    d_mod <= q;
	END IF;
    END PROCESS;

    -- Simulate the Polarity Switch.
    PROCESS (d_mod)
    BEGIN
	IF (inv_setting = ninv) THEN
	    IF ((d_mod = '0') OR (d_mod = '1')) THEN
		d_pol <= NOT(d_mod);
	    ELSE
		d_pol <= 'X';
	    END IF;
	ELSE
	    d_pol <= d_mod;
	END IF;
    END PROCESS;

    -- Simulate the Output.
    PROCESS (oe, d_pol)
    BEGIN
	IF (oe'event) THEN
	    IF (oe = '1') THEN
		IF ((d_pol = '0') OR (d_pol = '1')) THEN
		    y <= NOT d_pol AFTER Tpzx;
		ELSE
		    y <= 'X' after Tpzx;
		END IF;
	    ELSE
		y <= 'Z' AFTER Tpxz;
	    END IF;
	ELSE
	    IF (oe = '1') THEN
		IF ((d_pol = '0') OR (d_pol = '1')) THEN
		    y <= NOT d_pol; 
		ELSE
		    y <= 'X';
		END IF;
	    ELSE
		y <= 'Z';
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Feedback Mux.
    PROCESS (q, y)
    BEGIN
	IF (bta_sel = xreg) THEN
	    IF ((q = '0') OR (q = '1')) THEN
		fb <= NOT(q);
	    ELSE
		fb <= 'X';
	    END IF;
	ELSIF (bta_sel = xpin) THEN
	    IF (y = '1') THEN
		fb <= '1';
	    ELSE
		fb <= '0';
	    END IF;
	END IF;
    END PROCESS;
    
END sim;

library ieee;
use ieee.std_logic_1164.all;

ENTITY c20m IS
    GENERIC (
	Tpd	: TIME	:= 25 ns;
	Tea	: TIME	:= 25 ns;
	Ter	: TIME	:= 25 ns;
	Tpzx 	: TIME 	:= 20 ns;
	Tpxz 	: TIME 	:= 20 ns;
	Tco	: TIME 	:= 15 ns;
	Ts	: TIME	:= 20 ns;
	Th	: TIME	:=  0 ns;
	Tw	: TIME	:= 15 ns);
    PORT (
	x	: IN	std_logic;
	oe	: IN	std_logic;
	y	: INOUT	std_logic;
	yfb	: OUT	std_logic);
END c20m;

ARCHITECTURE sim OF c20m IS

BEGIN
    -- resolves tristate
    PROCESS (oe, x)
    BEGIN
	IF (oe'event) THEN
	    IF (oe = '1') THEN
		IF (x = '1') THEN
		    y <= '0' AFTER Tea;
		ELSE
		    y <= '1' AFTER Tea;
		END IF;
	    ELSE
		y <= 'Z' AFTER Ter;
	    END IF;
	ELSE
	    IF (oe = '1') THEN
		IF (x = '1') THEN
		    y <= '0' AFTER Tpd;
		ELSE
		    y <= '1' AFTER Tpd;
		END IF;
	    ELSE
		y <= 'Z';
	    END IF;
	END IF;
    END PROCESS;

    -- resolves node contention
    PROCESS (y)
    BEGIN
	IF (y = '1') THEN
	    yfb <= '1';
	ELSE
	    yfb <= '0';
	END IF;
    END PROCESS;

END sim;

library ieee;
use ieee.std_logic_1164.all;

ENTITY c20r IS
    GENERIC (
	Tpd	: TIME	:= 25 ns;
	Tea	: TIME	:= 25 ns;
	Ter	: TIME	:= 25 ns;
	Tpzx 	: TIME 	:= 20 ns;
	Tpxz 	: TIME 	:= 20 ns;
	Tco	: TIME 	:= 15 ns;
	Ts	: TIME	:= 20 ns;
	Th	: TIME	:=  0 ns;
	Tw	: TIME	:= 15 ns);
    PORT (
	d	: IN	std_logic;
	oe	: IN	std_logic;
	clk	: IN	std_logic;
	y	: OUT	std_logic;
	qfb	: OUT	std_logic := '1');
END c20r;

ARCHITECTURE sim OF c20r IS
    SIGNAL   	q 	: std_logic	:= '0';
    SIGNAL	q_ts	: std_logic := '0';
    SIGNAL	q_th	: std_logic := '0';
    SIGNAL	q_tw	: std_logic := '0';
BEGIN

    -- check for clk setup/hold violations
    PROCESS (clk, d)
	VARIABLE dlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN

	-- setup check
	IF (clk'event AND (clk = '1')) THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - dlastev) >= Ts))
		REPORT
		"Setup ERROR ON D: Setting output to unknown" 
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - dlastev) >= Ts)) THEN
		q_ts <= '1';
		q_ts <= transport '0' after 1 ns;
	    END IF;
	    clklastev := NOW;
	END IF;

	-- hold check
	IF (d'event) then
	    ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th))
		REPORT
		"Hold ERROR ON D: Setting output to unknown" 
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th)) THEN
		q_th <= '1';
		q_th <= transport '0' after 1 ns;
	    END IF;
	    dlastev := NOW;
	END IF;

    END PROCESS;

    -- check clk pulse width
    PROCESS (clk)
	VARIABLE clklastev : TIME := 0 ns;
    BEGIN
	ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Tw))
	    REPORT
	    "Pulse Width ERROR on CLK: Setting output to unknown"
	    SEVERITY WARNING;
	IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Tw)) THEN
	    q_tw <= '1'; 
	    q_tw <= transport '0' after 1 ns;
	END IF;
	clklastev := NOW;
    END PROCESS;

    -- Simulate the Register.
    PROCESS (clk, q_ts, q_th, q_tw)
    BEGIN
	IF ((q_ts = '1') OR (q_th = '1') OR (q_tw = '1')) THEN
	    q <= 'X' after Tco;
	    qfb <= 'X' after Tco;
	ELSIF (clk'event AND (clk = '1')) THEN
	    q <= d AFTER Tco;
	    qfb <= NOT d AFTER Tco;
	END IF;
    END PROCESS;

    -- Simulate the Output.
    PROCESS (oe,q)
    BEGIN
	IF (oe'event) THEN
	    IF (oe = '0') THEN
		IF (q = '1') THEN
		    y <= '0' AFTER Tpzx;
		ELSIF (q = '0') THEN
		    y <= '1' after Tpzx;
		ELSE
		    y <= 'X' after Tpzx;
		END IF;
	    ELSE
		y <= 'Z' AFTER Tpxz;
	    END IF;
	ELSE
	    IF (oe = '0') THEN
		IF (q = '1') THEN
		    y <= '0';
		ELSIF (q = '0') THEN
		    y <= '1';
		ELSE
		    y <= 'X';
		END IF;
	    ELSE
		y <= 'Z';
	    END IF;
	END IF;
    END PROCESS;
END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c20ra10m IS
    GENERIC (
	ibr		: polarity	:= invt;
	Tpd		: TIME		:= 15 ns;
	Tpzx		: TIME		:= 12 ns;
	Tpxz		: TIME		:= 12 ns;
	Tco		: TIME		:= 15 ns;
	Tsu		: TIME		:= 7 ns;
	Th		: TIME		:= 3 ns;
	Twh		: TIME		:= 10 ns;
	Twl		: TIME		:= 10 ns;
	Ts		: TIME		:= 15 ns;
	Tr		: TIME		:= 15 ns;
	Tarw		: TIME		:= 15 ns;
	Tasw		: TIME		:= 15 ns;
	Tar		: TIME		:= 10 ns;
	Twp		: TIME		:= 15 ns;
	Tsup		: TIME		:= 15 ns;
	Thp		: TIME		:= 15 ns
    );
    PORT (
	d	: IN	std_logic;
	clk	: IN	std_logic;
	oe	: IN	std_logic;
	pl	: IN	std_logic := '1';
	as	: IN	std_logic;
	ar	: IN	std_logic;
	y	: INOUT	std_logic;
	yfb	: OUT	std_logic);
END c20ra10m;

ARCHITECTURE sim OF c20ra10m IS
    SIGNAL	d_mod	: std_logic	:= '0';
    SIGNAL	q	: std_logic	:= '0';
    SIGNAL	q_tsu	: std_logic := '0';
    SIGNAL	q_th	: std_logic := '0';
    SIGNAL	q_twh	: std_logic := '0';
    SIGNAL	q_twl	: std_logic := '0';
    SIGNAL	q_tarw	: std_logic := '0';
    SIGNAL	q_tasw	: std_logic := '0';
    SIGNAL	q_tar	: std_logic := '0';
    SIGNAL	q_twp	: std_logic	:= '0';
    SIGNAL	q_tsup	: std_logic	:= '0';
    SIGNAL	q_thp	: std_logic	:= '0';
BEGIN
    -- check for clk setup/hold violations
    PROCESS (clk, d_mod)
	VARIABLE d_modlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	IF ((as = '0') AND (ar = '0') AND (pl = '1')) THEN

	    -- setup check
	    IF (clk'event AND (clk = '1')) THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - d_modlastev) >= Tsu))
		    REPORT
		    "Setup ERROR ON D: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - d_modlastev) >= Tsu)) THEN
		    q_tsu <= '1';
		    q_tsu <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;

	    -- hold check
	    IF (d_mod'event) then
		ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th))
		    REPORT
		    "Hold ERROR ON D: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th)) THEN
		    q_th <= '1';
		    q_th <= transport '0' after 1 ns;
		END IF;
		d_modlastev := NOW;
	    END IF;

	END IF;
    END PROCESS;

    -- check for pl setup/hold violations
    PROCESS (pl, y)
	VARIABLE ylastev	: TIME := 0 ns;
	VARIABLE pllastev	: TIME := 0 ns;
    BEGIN
	IF ((as = '0') AND (ar = '0') AND (pl = '0')) THEN

	    -- setup check
	    IF (pl'event AND (pl = '0')) THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - ylastev) >= Tsup))
		    REPORT
		    "Setup ERROR ON Y: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - ylastev) >= Tsup)) THEN
		    q_tsup <= '1';
		    q_tsup <= transport '0' after 1 ns;
		END IF;
		pllastev := NOW;
	    END IF;

	    -- hold check
	    IF (y'event) then
		ASSERT ((NOW = 0 ns) OR ((NOW - pllastev) >= Thp))
		    REPORT
		    "Hold ERROR ON Y: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - pllastev) >= Thp)) THEN
		    q_thp <= '1';
		    q_thp <= transport '0' after 1 ns;
		END IF;
		ylastev := NOW;
	    END IF;

	END IF;
    END PROCESS;

    -- check for Asynchronous Set/Reset Recovery violation
    PROCESS (as, ar)
	VARIABLE arlastev	: TIME := 0 ns;
	VARIABLE aslastev	: TIME := 0 ns;
    BEGIN
	IF (as'event) then
	    aslastev := NOW;
	END IF;
	IF (as = '0') THEN
	    IF (ar'event AND (ar = '0')) THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - aslastev) >= Tar))
		    REPORT
		    "Recovery ERROR on AS against AR: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - aslastev) >= Tar)) THEN
		    q_tar <= '1'; 
		    q_tar <= transport '0' after 1 ns;
		END IF;
		arlastev := NOW;
	    END IF;
	END IF;
    END PROCESS;

    -- check clk pulse width
    PROCESS (clk)
	VARIABLE clklastev : TIME := 0 ns;
    BEGIN
	IF (clk = '0') THEN
	   ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh))
		REPORT
		"Pulse Width (H) ERROR on CLK: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh)) THEN
		q_twh <= '1'; 
		q_twh <= transport '0' after 1 ns;
	    END IF;
	ELSIF (clk = '1') THEN
	   ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl))
		REPORT
		"Pulse Width (L) ERROR on CLK: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl)) THEN
		q_twl <= '1'; 
		q_twl <= transport '0' after 1 ns;
	    END IF;
	END IF;
	clklastev := NOW;
    END PROCESS;

    -- check Asynghronous Reset pulse width
    PROCESS (ar)
	VARIABLE arlastev : TIME := 0 ns;
    BEGIN
	IF (ar = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - arlastev) >= Tarw))
		REPORT
		"Pulse Width ERROR on AR: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - arlastev) >= Tarw)) THEN
		q_tarw <= '1'; 
		q_tarw <= transport '0' after 1 ns;
	    END IF;
	END IF;
	arlastev := NOW;
    END PROCESS;

    -- check Asynghronous Set pulse width
    PROCESS (as)
	VARIABLE aslastev : TIME := 0 ns;
    BEGIN
	IF (as = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - aslastev) >= Tasw))
		REPORT
		"Pulse Width ERROR on AS: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - aslastev) >= Tasw)) THEN
		q_tasw <= '1'; 
		q_tasw <= transport '0' after 1 ns;
	    END IF;
	END IF;
	aslastev := NOW;
    END PROCESS;

    -- check Preload pulse width
    PROCESS (pl)
	VARIABLE pllastev : TIME := 0 ns;
    BEGIN
	IF (pl = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - pllastev) >= Twp))
		REPORT
		"Pulse Width ERROR on PL: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - pllastev) >= Twp)) THEN
		q_twp <= '1'; 
		q_twp <= transport '0' after 1 ns;
	    END IF;
	END IF;
	pllastev := NOW;
    END PROCESS;

    -- Simulate the Polarity Switch.
    PROCESS (d)
    BEGIN
	IF (ibr = invt) THEN
	    d_mod <= NOT d;
	ELSE
	    d_mod <= d;
	END IF;
    END PROCESS;

    -- Simulate the Register.
    PROCESS(d_mod,clk,ar,as,q_tsu,q_th,q_twh,q_twl,
		q_tarw,q_tasw,q_tar,q_twp,q_tsup,q_thp)
    BEGIN
	IF ( (q_tsu	= '1')
	    OR (q_th	= '1')
	    OR (q_twh	= '1')
	    OR (q_twl	= '1')
	    OR (q_tarw	= '1')
	    OR (q_tasw	= '1')
	    OR (q_tar	= '1')
	    OR (q_twp	= '1')
	    OR (q_tsup	= '1')
	    OR (q_thp	= '1')) THEN
	    q <= 'X' after Tco;
	ELSIF ((ar = '1') AND (as = '1')) THEN
	    q <= d_mod AFTER Tpd;
	ELSIF (ar = '1') THEN
	    q <= '0' AFTER Tr;
	ELSIF (as = '1') THEN
	    q <= '1' AFTER Ts;
	ELSIF (clk = '1' AND clk'event) THEN
	    IF (pl = '0') THEN
		IF (y = '1') THEN
		    q <= '0' AFTER Tco;
		ELSE
		    q <= '1' AFTER Tco;
		END IF;
	    ELSE
		    q <= d_mod AFTER Tco;
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Output.
    PROCESS (q, oe)
    BEGIN
	IF (oe = '1') THEN
	    IF (oe'event) THEN
		y <= NOT q AFTER Tpzx;					
	    ELSE
		y <= NOT q;
	    END IF;
	ELSE 
	    y <= 'Z' AFTER Tpxz;
	END IF;
    END PROCESS;

    -- Simulate the Feedback.
    PROCESS (y)
    BEGIN
	IF (y = '1') THEN
	    yfb <= '1';
	ELSE
	    yfb <= '0';
	END IF;
    END PROCESS;
END sim;

library ieee;
use ieee.std_logic_1164.all;

ENTITY c20tri IS
    GENERIC (
	Tpd	: TIME	:= 25 ns;
	Tea	: TIME	:= 25 ns;
	Ter	: TIME	:= 25 ns;
	Tpzx 	: TIME 	:= 20 ns;
	Tpxz 	: TIME 	:= 20 ns;
	Tco	: TIME 	:= 15 ns;
	Ts	: TIME	:= 20 ns;
	Th	: TIME	:=  0 ns;
	Tw	: TIME	:= 15 ns);
    PORT (
	x	: IN	std_logic;
	oe	: IN	std_logic;
	y	: OUT	std_logic);
END c20tri;

ARCHITECTURE sim OF c20tri IS
BEGIN
    -- Simulate the Output.
    PROCESS (oe,x)
    BEGIN
	IF (oe'event) THEN
	    IF (oe = '1') THEN
		IF (x = '1') THEN
		    y <= '0' AFTER Tea;
		ELSE
		    y <= '1' AFTER Tea;
		END IF;
	    ELSE
		y <= 'Z' AFTER Ter;
	    END IF;
	ELSE
	    IF (oe = '1') THEN
		IF (x = '1') THEN
		    y <= '0' AFTER Tpd;
		ELSE
		    y <= '1' AFTER Tpd;
		END IF;
	    ELSE
		y <= 'Z';
	    END IF;
	END IF;
    END PROCESS;
END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c22v10m IS
    GENERIC (
	registered	: reg_def	:= reg;
	inv_setting	: polarity	:= invt;
	bta_sel		: fb_type	:= xreg;
	Tpd		: TIME		:= 20 ns;
	Tea		: TIME		:= 20 ns;
	Ter		: TIME		:= 20 ns;
	Tco		: TIME		:= 12 ns;
	Ts		: TIME		:= 12 ns;
	Th		: TIME		:=  0 ns;
	Twh		: TIME		:= 10 ns;
	Twl		: TIME		:= 10 ns;
	Tcf		: TIME		:= 10 ns;
	Taw		: TIME		:= 20 ns;
	Tar		: TIME		:= 20 ns;
	Tap		: TIME		:= 25 ns;
	Tspr		: TIME		:= 20 ns);
    PORT (
	d	: IN	std_logic;
	clk	: IN	std_logic;
	oe	: IN	std_logic;
	ss	: IN	std_logic;
	ar	: IN	std_logic;
	y	: INOUT std_logic;
	fb	: OUT	std_logic);
END c22v10m;

ARCHITECTURE sim OF c22v10m IS
	SIGNAL	q	: std_logic	:= '0';
	SIGNAL	q_not	: std_logic := '1';
	SIGNAL	qbar	: std_logic	:= '0';
	SIGNAL	d_mod	: std_logic	:= '0';
	SIGNAL	d_pol	: std_logic	:= '0';
	SIGNAL	q_ts	: std_logic := '0';
	SIGNAL	q_th	: std_logic := '0';
	SIGNAL	q_twh	: std_logic := '0';
	SIGNAL	q_twl	: std_logic := '0';
	SIGNAL	q_tar	: std_logic := '0';
	SIGNAL	q_ss	: std_logic := '0';
	SIGNAL	q_tspr	: std_logic := '0';
	SIGNAL	q_taw	: std_logic	:= '0';
BEGIN

    -- check for clk setup/hold violations
    PROCESS (clk, d)
	VARIABLE dlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	-- Check only if the cell is registered.
	IF (registered = reg) THEN

	    -- setup check
	    IF (clk'event AND (clk = '1')) THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - dlastev) >= Ts))
		    REPORT
		    "Setup ERROR ON D: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - dlastev) >= Ts)) THEN
		    q_ts <= '1';
		    q_ts <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;

	    -- hold check
	    IF (d'event) then
		ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th))
		    REPORT
		    "Hold ERROR ON D: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th)) THEN
		    q_th <= '1';
		    q_th <= transport '0' after 1 ns;
		END IF;
		dlastev := NOW;
	    END IF;
	END IF;
    END PROCESS;

    -- check for Asynchronous Reset Recovery violation
    PROCESS (clk, ar)
	VARIABLE arlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	-- Check only if the cell is registered.
	IF (registered = reg) THEN
	    IF (ar'event) then
		arlastev := NOW;
	    END IF;
	    IF (ar = '0') THEN
		IF (clk'event AND (clk = '1')) THEN
		    ASSERT ((NOW = 0 ns) OR ((NOW - arlastev) >= Tar))
			REPORT
			"Recovery ERROR on AR: Setting output to unknown" 
			SEVERITY WARNING;
		    IF NOT ((NOW = 0 ns) OR ((NOW - arlastev) >= Tar)) THEN
			q_tar <= '1'; 
			q_tar <= transport '0' after 1 ns;
		    END IF;
		    clklastev := NOW;
		END IF;
	    END IF;
	END IF;
    END PROCESS;

    -- check for Synchronous Preset Recovery violation
    PROCESS (clk, ss)
	VARIABLE sslastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	-- Check only if the cell is registered.
	IF (registered = reg) THEN
	    IF (ss'event) then
		sslastev := NOW;
	    END IF;
	    IF (ss = '0') THEN
		IF (clk'event AND (clk = '1')) THEN
		    ASSERT ((NOW = 0 ns) OR ((NOW - sslastev) >= Tspr))
			REPORT
			"Recovery ERROR on SS: Setting output to unknown" 
			SEVERITY WARNING;
		    IF NOT ((NOW = 0 ns) OR ((NOW - sslastev) >= Tspr)) THEN
			q_tspr <= '1'; 
			q_tspr <= transport '0' after 1 ns;
		    END IF;
		    clklastev := NOW;
		END IF;
	    END IF;
	END IF;
    END PROCESS;

    -- check clk pulse width
    PROCESS (clk)
	VARIABLE clklastev : TIME := 0 ns;
    BEGIN
	-- Check only if the cell is registered.
	IF (registered = reg) THEN
	    IF (clk = '0') THEN
	       ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh))
		    REPORT
		    "Pulse Width (H) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh)) THEN
		    q_twh <= '1'; 
		    q_twh <= transport '0' after 1 ns;
		END IF;
	    ELSIF (clk = '1') THEN
	       ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl))
		    REPORT
		    "Pulse Width (L) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl)) THEN
		    q_twl <= '1'; 
		    q_twl <= transport '0' after 1 ns;
		END IF;
	    END IF;
	    clklastev := NOW;
	END IF;
    END PROCESS;

    -- check Asynchronous Reset pulse width
    PROCESS (ar)
	VARIABLE arlastev : TIME := 0 ns;
    BEGIN
	-- Check only if the cell is registered.
	IF (registered = reg) THEN
	    IF (clk = '0') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - arlastev) >= Taw))
		    REPORT
		    "Pulse Width ERROR on AR: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - arlastev) >= Taw)) THEN
		    q_taw <= '1'; 
		    q_taw <= transport '0' after 1 ns;
		END IF;
	    END IF;
	END IF;
	arlastev := NOW;
    END PROCESS;

    -- Simulate the Register.
    PROCESS (clk, ar, ss, q_ts, q_th, q_twh, q_twl, q_taw, q_tar, q_tspr, q_ss)
    BEGIN
	IF ((q_ts = '1') OR (q_th = '1') OR (q_twh = '1') OR (q_twl = '1') OR
	(q_taw = '1') OR (q_tar = '1') OR (q_tspr = '1') OR (q_ss = '1')) THEN
	    q <= 'X' after Tco;
	    q_not <= 'X' after Tcf;
	ELSIF (ar = '1') THEN
	    q <= '0' AFTER Tap;
	    q_not <= '1' AFTER Tcf;
	ELSIF ((clk = '1') AND clk'event) THEN
	    IF (ss = '1') THEN
		q <= '1' AFTER Tco;
		q_not <= '0' AFTER Tcf;
	    ELSE
		q <= d AFTER Tco;
		IF (d = '1') THEN
		    q_not <= '0' after Tcf;
		ELSE
		    q_not <= '1' after Tcf;
		END IF;
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Register Mux.
    PROCESS (d, q)
    BEGIN
	IF (registered = comb) THEN
	    d_mod <= d AFTER Tpd;
	ELSIF (registered = reg) THEN
	    d_mod <= q;
	END IF;
    END PROCESS;

    -- Simulate the Polarity Switch.
    PROCESS (d_mod)
    BEGIN
	IF (inv_setting = invt) THEN
	    d_pol <= d_mod;
	ELSE
	    d_pol <= NOT d_mod;
	END IF;
    END PROCESS;

    -- Simulate the Output.
    PROCESS (oe, d_pol)
    BEGIN
	IF (oe'event) THEN
	    IF (oe = '1') THEN
		y <= NOT d_pol AFTER Tea;
	    ELSE
		y <= 'Z' AFTER Ter;
	    END IF;
	ELSE
	    IF (oe = '1') THEN
		y <= NOT d_pol; 
	    ELSE
		y <= 'Z';
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Feedback.
    PROCESS (y, q)
    BEGIN
	IF (bta_sel = xpin) THEN
	    IF (y = '1') THEN
		fb <= '1';
	    ELSE
		fb <= '0';
	    END IF;
	ELSIF (bta_sel = xreg) THEN
	    fb <= q_not;
	END IF;
    END PROCESS;

END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c331ckmx IS
    GENERIC (
	Tpd		: TIME		:= 20 ns;
	Tico		: TIME		:= 35 ns;
	Tioh		: TIME		:=  5 ns;
	Tis		: TIME		:=  2 ns;
	Tih		: TIME		:= 11 ns;
	Tiar		: TIME		:= 35 ns;
	Tirw		: TIME		:= 35 ns;
	Tirr		: TIME		:= 35 ns;
	Tias		: TIME		:= 35 ns;
	Tisw		: TIME		:= 35 ns;
	Tisr		: TIME		:= 35 ns;
	Twh		: TIME		:= 12 ns;
	Twl		: TIME		:= 12 ns;
	Tco		: TIME		:= 20 ns;
	Ts		: TIME		:= 12 ns;
	Th		: TIME		:=  8 ns;
	Toar		: TIME		:= 20 ns;
	Torw		: TIME		:= 20 ns;
	Torr		: TIME		:= 20 ns;
	Toas		: TIME		:= 20 ns;
	Tosw		: TIME		:= 20 ns;
	Tosr		: TIME		:= 20 ns;
	Tpzx		: TIME		:= 20 ns;
	Tpxz		: TIME		:= 20 ns);
    PORT (
	clksrc	 : IN std_logic;
	clk	 : OUT std_logic);
END c331ckmx;

ARCHITECTURE sim OF c331ckmx IS
    SIGNAL	clksrc_twh	: std_logic := '0';
    SIGNAL	clksrc_twl	: std_logic := '0';
BEGIN
    -- check clksrc pulse width
    PROCESS (clksrc)
	VARIABLE clksrclastev : TIME := 0 ns;
    BEGIN
	IF (clksrc = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - clksrclastev) >= Twh))
		REPORT
		"Pulse Width (H) ERROR on CLKSRC: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clksrclastev) >= Twh)) THEN
		clksrc_twh <= '1'; 
		clksrc_twh <= transport '0' after 1 ns;
	    END IF;
	ELSIF (clksrc = '1') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - clksrclastev) >= Twl))
		REPORT
		"Pulse Width (L) ERROR on CLKSRC: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clksrclastev) >= Twl)) THEN
		clksrc_twl <= '1'; 
		clksrc_twl <= transport '0' after 1 ns;
	    END IF;
	END IF;
	clksrclastev := NOW;
    END PROCESS;

    -- Simulate the Clock Mux.
    PROCESS (clksrc, clksrc_twh, clksrc_twl)
    BEGIN
	IF ((clksrc_twh = '1') OR (clksrc_twl = '1')) THEN
	    clk <= 'X';
	ELSE
	    clk <= clksrc;
	END IF;
    END PROCESS;
END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c331m IS
    GENERIC (
	Tpd		: TIME		:= 20 ns;
	Tico		: TIME		:= 35 ns;
	Tioh		: TIME		:=  5 ns;
	Tis		: TIME		:=  2 ns;
	Tih		: TIME		:= 11 ns;
	Tiar		: TIME		:= 35 ns;
	Tirw		: TIME		:= 35 ns;
	Tirr		: TIME		:= 35 ns;
	Tias		: TIME		:= 35 ns;
	Tisw		: TIME		:= 35 ns;
	Tisr		: TIME		:= 35 ns;
	Twh		: TIME		:= 12 ns;
	Twl		: TIME		:= 12 ns;
	Tco		: TIME		:= 20 ns;
	Ts		: TIME		:= 12 ns;
	Th		: TIME		:=  8 ns;
	Toar		: TIME		:= 20 ns;
	Torw		: TIME		:= 20 ns;
	Torr		: TIME		:= 20 ns;
	Toas		: TIME		:= 20 ns;
	Tosw		: TIME		:= 20 ns;
	Tosr		: TIME		:= 20 ns;
	Tpzx		: TIME		:= 20 ns;
	Tpxz		: TIME		:= 20 ns);
    PORT (
	x1	: IN    std_logic;
	x2	: IN    std_logic;
	clk	: IN    std_logic;
	iclk	: IN    std_logic;
	oe	: IN    std_logic;
	as	: IN    std_logic;
	ar	: IN    std_logic;
	ias	: IN    std_logic;
	iar 	: IN    std_logic;
	qfb	: OUT   std_logic := '1';
	y	: INOUT std_logic;
	qifb	: OUT   std_logic := '0');
END c331m;

ARCHITECTURE sim OF c331m IS
    SIGNAL	q		: std_logic	:= '0';
    SIGNAL	iregq_tis	: std_logic	:= '0';
    SIGNAL	iregq_tih	: std_logic	:= '0';
    SIGNAL	iregq_tirw	: std_logic	:= '0';
    SIGNAL	iregq_tirr	: std_logic	:= '0';
    SIGNAL	iregq_tisw	: std_logic	:= '0';
    SIGNAL	iregq_tisr	: std_logic	:= '0';
    SIGNAL	iregq_twh	: std_logic	:= '0';
    SIGNAL	iregq_twl	: std_logic	:= '0';
    SIGNAL	q_twh		: std_logic	:= '0';
    SIGNAL	q_twl		: std_logic	:= '0';
    SIGNAL	q_ts		: std_logic	:= '0';
    SIGNAL	q_th		: std_logic	:= '0';
    SIGNAL	q_torw		: std_logic	:= '0';
    SIGNAL	q_torr		: std_logic	:= '0';
    SIGNAL	q_tosw		: std_logic	:= '0';
    SIGNAL	q_tosr		: std_logic	:= '0';
    SIGNAL	q_tpzx		: std_logic	:= '0';
    SIGNAL	q_tpxz		: std_logic	:= '0';
BEGIN

    -- check for clk setup/hold violations
    PROCESS (clk, x1, x2)
	VARIABLE xlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
    -- only check constraints if as and ar are not enabled.
    IF ((as = '0') AND (ar = '0')) THEN
	
	-- setup check
	IF (clk'event AND (clk = '1')) THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - xlastev) >= Ts))
		REPORT
		"Setup ERROR on X: Setting output to Unknown" 
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - xlastev) >= Ts)) THEN
		q_ts <= '1'; 
		q_ts <= transport '0' after 1 ns;
	    END IF;
	    clklastev := NOW;
	END IF;

	-- hold check
	IF (x1'event OR
	    (x2'event)) then
	    ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th))
		REPORT
		"Hold ERROR ON X: Setting output to unknown" 
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th)) THEN
		q_th <= '1';
		q_th <= transport '0' after 1 ns;
	    END IF;
	    xlastev := NOW;
	END IF;

    END IF;
    END PROCESS;

    -- check for iclk setup/hold violations
    PROCESS (iclk, y)
	VARIABLE ylastev	: TIME := 0 ns;
	VARIABLE iclklastev	: TIME := 0 ns;
    BEGIN
    -- only check constraints if ias and iar are not enabled.
    IF ((ias = '0') AND (iar = '0')) THEN

	-- setup check
	IF (iclk'event AND (iclk = '1')) THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - ylastev) >= Tis))
		REPORT
		"Setup ERROR ON Y: Setting output to Unknown" 
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - ylastev) >= Tis)) THEN
		iregq_tis <= '1'; 
		iregq_tis <= transport '0' after 1 ns;
	    END IF;
	    iclklastev := NOW;
	END IF;

	-- hold check
	IF (y'event) then
	    ASSERT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Tih))
		REPORT
		"Hold ERROR ON Y: Setting output to Unknown" 
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Tih)) THEN
		iregq_tih <= '1'; 
		iregq_tih <= transport '0' after 1 ns;
	    END IF;
	    ylastev := NOW;
	END IF;

    END IF;
    END PROCESS;

    -- check clk pulse width
    PROCESS (clk)
	VARIABLE clklastev : TIME := 0 ns;
    BEGIN
    -- Only check constraints when as & ar are disabled
    IF ((as = '0') AND (ar = '0')) THEN
	IF (clk = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh))
		REPORT
		"Pulse Width (H) ERROR on CLK: Setting output to Unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh)) THEN
		q_twh <= '1'; 
		q_twh <= transport '0' after 1 ns;
	    END IF;
	ELSIF (clk = '1') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl))
		REPORT
		"Pulse Width (L) ERROR on CLK: Setting output to Unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl)) THEN
		q_twl <= '1'; 
		q_twl <= transport '0' after 1 ns;
	    END IF;
	END IF;
	clklastev := NOW;
    END IF;
    END PROCESS;

    -- check iclk pulse width
    PROCESS (iclk)
	VARIABLE iclklastev : TIME := 0 ns;
    BEGIN
    -- Only check constraints when as & ar are disabled
    IF ((ias = '0') AND (iar = '0')) THEN
	IF (iclk = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twh))
		REPORT
		"Pulse Width (H) ERROR on CLK: Setting output to Unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twh)) THEN
		iregq_twh <= '1'; 
		iregq_twh <= transport '0' after 1 ns;
	    END IF;
	ELSIF (iclk = '1') THEN
	   ASSERT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twl))
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twl)) THEN
		iregq_twl <= '1'; 
		iregq_twl <= transport '0' after 1 ns;
	    END IF;
	END IF;
	iclklastev := NOW;
    END IF;
    END PROCESS;

    -- check for Asynchronous Reset Recovery violation
    PROCESS (clk, ar)
	VARIABLE arlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	IF (ar'event) then
	    arlastev := NOW;
	END IF;
	IF (ar = '0') THEN
	    IF (clk'event AND (clk = '1')) THEN
		ASSERT ((NOW = 0 ns) OR (NOW - arlastev) >= Torr)
		    REPORT
		    "Recovery ERROR on AR: Setting output to Unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - arlastev) >= Torr)) THEN
		    q_torr <= '1'; 
		    q_torr <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;
	END IF;
    END PROCESS;

    -- check for Asynchronous Preset Recovery violation
    PROCESS (clk, as)
	VARIABLE aslastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	IF (as'event) then
	    aslastev := NOW;
	END IF;
	IF (as = '0') THEN
	    IF (clk'event AND (clk = '1')) THEN
		ASSERT ((NOW = 0 ns) OR (NOW - aslastev) >= Tosr)
		    REPORT
		    "Recovery ERROR on AS: Setting output to Unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - aslastev) >= Tosr)) THEN
		    q_tosr <= '1'; 
		    q_tosr <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;
	END IF;
    END PROCESS;

    -- check for Asynchronous Reset Recovery violation
    PROCESS (iclk, iar)
	VARIABLE iarlastev	: TIME := 0 ns;
	VARIABLE iclklastev	: TIME := 0 ns;
    BEGIN
	IF (iar'event) then
	    iarlastev := NOW;
	END IF;
	IF (iar = '0') THEN
	    IF (iclk'event AND (iclk = '1')) THEN
		ASSERT ((NOW = 0 ns) OR (NOW - iarlastev) >= Tirr)
		    REPORT
		    "Recovery ERROR on IAR: Setting output to Unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - iarlastev) >= Tirr)) THEN
		    iregq_tirr <= '1'; 
		    iregq_tirr <= transport '0' after 1 ns;
		END IF;
		iclklastev := NOW;
	    END IF;
	END IF;
    END PROCESS;

    -- check for Asynchronous Preset Recovery violation
    PROCESS (iclk, ias)
	VARIABLE iaslastev	: TIME := 0 ns;
	VARIABLE iclklastev	: TIME := 0 ns;
    BEGIN
	IF (ias'event) then
	    iaslastev := NOW;
	END IF;
	IF (ias = '0') THEN
	    IF (iclk'event AND (iclk = '1')) THEN
		ASSERT ((NOW = 0 ns) OR (NOW - iaslastev) >= Tisr)
		    REPORT
		    "Recovery ERROR on IAS: Setting output to Unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - iaslastev) >= Tisr)) THEN
		    iregq_tisr <= '1'; 
		    iregq_tisr <= transport '0' after 1 ns;
		END IF;
		iclklastev := NOW;
	    END IF;
	END IF;
    END PROCESS;

    -- check Asynchronous Reset pulse width
    PROCESS (ar)
	VARIABLE arlastev : TIME := 0 ns;
    BEGIN
	IF (clk = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - arlastev) >= Torw))
		REPORT
		"Pulse Width ERROR on AR: Setting output to Unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - arlastev) >= Torw)) THEN
		q_torw <= '1'; 
		q_torw <= transport '0' after 1 ns;
	    END IF;
	END IF;
	arlastev := NOW;
    END PROCESS;

    -- check Asynchronous Set pulse width
    PROCESS (as)
	VARIABLE aslastev : TIME := 0 ns;
    BEGIN
	IF (clk = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - aslastev) >= Tosw))
		REPORT
		"Pulse Width ERROR on AS: Setting output to Unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - aslastev) >= Tosw)) THEN
		q_tosw <= '1'; 
		q_tosw <= transport '0' after 1 ns;
	    END IF;
	END IF;
	aslastev := NOW;
    END PROCESS;

    -- check Asynchronous Reset pulse width
    PROCESS (iar)
	VARIABLE iarlastev : TIME := 0 ns;
    BEGIN
	IF (iclk = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - iarlastev) >= Tirw))
		REPORT
		"Pulse Width ERROR on IAR: Setting output to Unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - iarlastev) >= Tirw)) THEN
		iregq_tirw <= '1'; 
		iregq_tirw <= transport '0' after 1 ns;
	    END IF;
	END IF;
	iarlastev := NOW;
    END PROCESS;

    -- check Asynchronous Set pulse width
    PROCESS (ias)
	VARIABLE iaslastev : TIME := 0 ns;
    BEGIN
	IF (iclk = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - iaslastev) >= Tisw))
		REPORT
		"Pulse Width ERROR on IAS: Setting output to Unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - iaslastev) >= Tisw)) THEN
		iregq_tisw <= '1'; 
		iregq_tisw <= transport '0' after 1 ns;
	    END IF;
	END IF;
	iaslastev := NOW;
    END PROCESS;

    -- Simulate the Output Register.
    PROCESS (clk,ar,as,q_ts,q_th,q_twh,q_twl,q_tosw,q_torw,q_tosr,q_torr,x1,x2)
    BEGIN
	IF ((q_ts = '1') OR (q_th = '1') OR (q_twh = '1') OR (q_twl = '1')
	OR (q_tosw = '1') OR (q_torw = '1') OR (q_tosr = '1')
	OR (q_torr = '1')) THEN
	    q <= 'X' after Tco;
	ELSIF ((ar = '1') AND (as = '1')) THEN
	    q <= x1 XOR x2 AFTER Tpd;
	ELSIF (ar = '1') THEN
	    q <= '0' AFTER Toar;
	ELSIF (as = '1') THEN
	    q <= '1' AFTER Toas;
	ELSIF (clk = '1' AND clk'event) THEN
	    q <= x1 XOR x2 AFTER Tco;		
	END IF;
    END PROCESS;

    -- Simulate the Register Feedback.
    PROCESS (q)
    BEGIN
	qfb <= NOT q;
    END PROCESS;

    -- Simulate the Output.
    PROCESS (q, oe)
    BEGIN
	IF (oe = '1') THEN
	    IF (oe'event) THEN
		y <= NOT q AFTER Tpzx;
	    ELSE
		y <= NOT q;
	    END IF;
	ELSE
	    IF (oe'event) THEN
		y <= 'Z' AFTER Tpxz;
	    ELSE
		y <= 'Z';
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Input Register.
    PROCESS (iclk,iar,ias,y,iregq_tis,iregq_tih,iregq_twh,iregq_twl,iregq_tisw,
		 iregq_tirw,iregq_tisr,iregq_tirr)
    BEGIN
	IF ((iregq_tis = '1') OR (iregq_tih = '1') OR (iregq_twh = '1')
	OR (iregq_twl = '1') OR (iregq_tisw = '1') OR (iregq_tirw = '1')
	OR (iregq_tisr = '1') OR (iregq_tirr = '1')) THEN
	    qifb <= 'X' after (Tico - Tpd);
	ELSIF ((iar = '1') AND (ias = '1')) THEN
	    IF (y = '1') THEN
		qifb <= '1';
	    ELSE
		qifb <= '0';
	    END IF;
	ELSIF (iar = '1') THEN
	    qifb <= '0' AFTER Tiar;
	ELSIF (ias = '1') THEN
	    qifb <= '1' AFTER Tias;
	ELSIF (iclk = '1' AND iclk'event) THEN
	    IF (y = '1') THEN
		qifb <= '1' AFTER (Tico -Tpd);
	    ELSE
		qifb <= '0' AFTER (Tico -Tpd);
	    END IF;
	END IF;
    END PROCESS;
END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c335ckmx IS
    GENERIC (
	Tpd		: TIME		:= 15 ns;
	Twh		: TIME		:=  5 ns;
	Twl		: TIME		:=  5 ns;
	Tis		: TIME		:=  2 ns;
	Tih		: TIME		:=  2 ns;
	Tico		: TIME		:= 18 ns;
	Tpzx		: TIME		:= 12 ns;
	Tpxz		: TIME		:= 12 ns;
	Ts		: TIME		:=  9 ns;
	Th		: TIME		:=  0 ns;
	Tco		: TIME		:= 10 ns;
	Tco2		: TIME		:= 18 ns
    );
    PORT (
	clksrc	 : IN std_logic;
	clk	 : OUT std_logic);
END c335ckmx;

ARCHITECTURE sim OF c335ckmx IS
    SIGNAL	clksrc_twh	: std_logic := '0';
    SIGNAL	clksrc_twl	: std_logic := '0';
BEGIN
    -- check clksrc pulse width
    PROCESS (clksrc)
	VARIABLE clksrclastev : TIME := 0 ns;
    BEGIN
	IF (clksrc = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - clksrclastev) >= Twh))
		REPORT
		"Pulse Width (H) ERROR on CLKSRC: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clksrclastev) >= Twh)) THEN
		clksrc_twh <= '1'; 
		clksrc_twh <= transport '0' after 1 ns;
	    END IF;
	ELSIF (clksrc = '1') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - clksrclastev) >= Twl))
		REPORT
		"Pulse Width (L) ERROR on CLKSRC: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clksrclastev) >= Twl)) THEN
		clksrc_twl <= '1'; 
		clksrc_twl <= transport '0' after 1 ns;
	    END IF;
	END IF;
	clksrclastev := NOW;
    END PROCESS;

    -- Simulate the Clock Mux.
    PROCESS (clksrc, clksrc_twh, clksrc_twl)
    BEGIN
	IF ((clksrc_twh = '1') OR (clksrc_twl = '1')) THEN
	    clk <= 'X';
	ELSE
	    clk <= clksrc;
	END IF;
    END PROCESS;
END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c335h IS				
    GENERIC (
	Tpd		: TIME		:= 15 ns;
	Twh		: TIME		:=  5 ns;
	Twl		: TIME		:=  5 ns;
	Tis		: TIME		:=  2 ns;
	Tih		: TIME		:=  2 ns;
	Tico		: TIME		:= 18 ns;
	Tpzx		: TIME		:= 12 ns;
	Tpxz		: TIME		:= 12 ns;
	Ts		: TIME		:=  9 ns;
	Th		: TIME		:=  0 ns;
	Tco		: TIME		:= 10 ns;
	Tco2		: TIME		:= 18 ns
    );
    PORT (
	x1	: IN  std_logic;
	x2	: IN  std_logic;
	clk	: IN  std_logic;
	ss	: IN  std_logic;
	sr	: IN  std_logic;
	qfb	: OUT std_logic := '0');
END c335h;

ARCHITECTURE sim OF c335h IS
    SIGNAL	q_ts	   : std_logic := '0';
    SIGNAL	q_th	   : std_logic := '0';
    SIGNAL	q_twh	   : std_logic := '0';
    SIGNAL	q_twl	   : std_logic := '0';
    SIGNAL	q_setreset : std_logic := '0';
BEGIN

    -- check for clk setup/hold violations
    PROCESS (clk, x1, x2)
	VARIABLE xlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	-- setup check
	IF (clk'event AND (clk = '1')) THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - xlastev) >= Ts))
		REPORT
		"Setup ERROR on X: Setting output to unknown" 
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - xlastev) >= Ts)) THEN
		q_ts <= '1';
		q_ts <= transport '0' after 1 ns;
	    END IF;
	    clklastev := NOW;
	END IF;
	-- hold check
	IF (x1'event OR
	    x2'event) then
	    ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th))
		REPORT
		"Hold ERROR ON X: Setting output to unknown" 
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th)) THEN
		q_th <= '1';
		q_th <= transport '0' after 1 ns;
	    END IF;
	    xlastev := NOW;
	END IF;
    END PROCESS;

    -- check clk pulse width
    PROCESS (clk)
	VARIABLE clklastev : TIME := 0 ns;
    BEGIN
	IF (clk = '0') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh))
		REPORT
		"Pulse Width (H) ERROR on CLK: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh)) THEN
		q_twh <= '1'; 
		q_twh <= transport '0' after 1 ns;
	    END IF;
	ELSIF (clk = '1') THEN
	    ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl))
		REPORT
		"Pulse Width (L) ERROR on CLK: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl)) THEN
		q_twl <= '1'; 
		q_twl <= transport '0' after 1 ns;
	    END IF;
	END IF;
	clklastev := NOW;
    END PROCESS;

    -- IS THIS CHECK REALLY NECESSARY AND VALID????  See notes below.
    -- check for invalid control
    PROCESS (clk)
    BEGIN
	IF (clk = '1') THEN
	    ASSERT NOT ((ss = '1') AND (sr = '1'))
		REPORT
		"ERROR: Preset & Clear both Active: Setting outputs to unknown"
		SEVERITY warning;
	    IF ((ss = '1') AND (sr = '1')) THEN
		q_setreset <= '1';
		q_setreset <= transport '0' after 1 ns;
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Register.
    PROCESS (clk, sr, ss, q_ts, q_th, q_twh, q_twl, q_setreset)
    BEGIN
	IF ((q_ts = '1') OR (q_th = '1') OR (q_twh = '1') OR (q_twl = '1')
	OR (q_setreset = '1')) THEN
	    qfb <= 'X' after Tco;
	ELSIF ((clk = '1') AND clk'event) THEN
	    IF (sr = '1') THEN
		qfb <= '0';
	    ELSIF (ss = '1') THEN
		qfb <= '1';
	    ELSE
		qfb <= NOT (x1 XOR x2) AFTER Tco;
	    END IF;
	END IF;	
    END PROCESS;
END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c335ireg IS

    GENERIC (
	iregister	: reg_def	:= reg;
	Tpd		: TIME		:= 15 ns;
	Twh		: TIME		:=  5 ns;
	Twl		: TIME		:=  5 ns;
	Tis		: TIME		:=  2 ns;
	Tih		: TIME		:=  2 ns;
	Tico		: TIME		:= 18 ns;
	Tpzx		: TIME		:= 12 ns;
	Tpxz		: TIME		:= 12 ns;
	Ts		: TIME		:=  9 ns;
	Th		: TIME		:=  0 ns;
	Tco		: TIME		:= 10 ns;
	Tco2		: TIME		:= 18 ns
    );
    PORT (
	d	: IN  std_logic;
	iclk	: IN  std_logic;
	fb	: OUT std_logic);
END c335ireg;

ARCHITECTURE sim OF c335ireg IS
    SIGNAL	iregq	  : std_logic := '0';
    SIGNAL	iregq_ts  : std_logic := '0';
    SIGNAL	iregq_th  : std_logic := '0';
    SIGNAL	iregq_twh : std_logic := '0';
    SIGNAL	iregq_twl : std_logic := '0';
BEGIN
    -- check for iclk setup/hold violations
    PROCESS (iclk, d)
	VARIABLE dlastev	: TIME := 0 ns;
	VARIABLE iclklastev	: TIME := 0 ns;
    BEGIN
	-- only if it is a registered cell.
	if (iregister = reg) then
	    -- setup check
	    IF (iclk'event AND (iclk = '1')) THEN
		ASSERT ((NOW = 0 ns) OR (NOW - dlastev) >= Tis)
		    REPORT
		    "Setup ERROR ON D: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - dlastev) >= Tis)) THEN
		    iregq_ts <= '1'; 
		    iregq_ts <= transport '0' after 1 ns;
		END IF;
		iclklastev := NOW;
	    END IF;
	    -- hold check
	    IF (d'event) then
		ASSERT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Tih))
		    REPORT
		    "Hold ERROR ON D: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Tih)) THEN
		    iregq_th <= '1'; 
		    iregq_th <= transport '0' after 1 ns;
		END IF;
		dlastev := NOW;
	    END IF;
	end if;
    END PROCESS;

    -- check iclk pulse width
    PROCESS (iclk)
	VARIABLE iclklastev : TIME := 0 ns;
    BEGIN
	-- only if it is a registered cell.
	if (iregister = reg) then
	    IF (iclk = '0') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twh))
		    REPORT
		    "Pulse Width (H) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twh)) THEN
		    iregq_twh <= '1'; 
		    iregq_twh <= transport '0' after 1 ns;
		END IF;
	    ELSIF (iclk = '1') THEN
	       ASSERT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twl))
		    REPORT
		    "Pulse Width (L) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twl)) THEN
		    iregq_twl <= '1'; 
		    iregq_twl <= transport '0' after 1 ns;
		END IF;
	    END IF;
	    iclklastev := NOW;
	end if;
    END PROCESS;

    -- Simulate the Register
    PROCESS (iclk, iregq_ts, iregq_th, iregq_twh, iregq_twl)
    BEGIN
	IF ((iregq_ts = '1') OR (iregq_th = '1') OR (iregq_twh = '1')
	OR (iregq_twl = '1')) THEN
	    iregq <= 'X' after (Tico - Tpd);
	ELSIF ((iclk = '1') AND iclk'event) THEN
	    IF (d = '1') THEN
		iregq <= '1' AFTER (Tico - Tpd);
	    ELSE
		iregq <= '0' AFTER (Tico - Tpd);
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Feedback Mux.
    PROCESS (d, iregq)
    BEGIN
	IF (iregister = reg) THEN
	    fb <= iregq;
	ELSIF (iregister = comb) THEN
	    IF (d = '1') THEN
		fb <= '1';
	    ELSE
		fb <= '0';
	    END IF;
	END IF;
    END PROCESS;

END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c335m IS
    GENERIC (
	registered	: reg_def	:= reg;
	bta_sel		: fb_type	:= xreg;
	Tpd		: TIME		:= 15 ns;
	Twh		: TIME		:=  5 ns;
	Twl		: TIME		:=  5 ns;
	Tis		: TIME		:=  2 ns;
	Tih		: TIME		:=  2 ns;
	Tico		: TIME		:= 18 ns;
	Tpzx		: TIME		:= 12 ns;
	Tpxz		: TIME		:= 12 ns;
	Ts		: TIME		:=  9 ns;
	Th		: TIME		:=  0 ns;
	Tco		: TIME		:= 10 ns;
	Tco2		: TIME		:= 18 ns
    );
    PORT (
	x1	: IN    std_logic;
	x2	: IN    std_logic;
	clk	: IN    std_logic;
	iclk	: IN    std_logic;
	ss	: IN    std_logic;
	sr	: IN    std_logic;
	oe	: IN    std_logic;
	qfb	: OUT   std_logic := '1';
	fb	: OUT   std_logic;
	y	: INOUT std_logic);
END c335m;

ARCHITECTURE sim OF c335m IS
    SIGNAL	q	   : std_logic := '0';
    SIGNAL	iregq	   : std_logic := '0';
    SIGNAL	q_ts	   : std_logic := '0';
    SIGNAL	q_th	   : std_logic := '0';
    SIGNAL	q_twh	   : std_logic := '0';
    SIGNAL	q_twl	   : std_logic := '0';
    SIGNAL	iregq_ts   : std_logic := '0';
    SIGNAL	iregq_th   : std_logic := '0';
    SIGNAL	iregq_twh  : std_logic := '0';
    SIGNAL	iregq_twl  : std_logic := '0';
    SIGNAL	q_setreset : std_logic := '0';
BEGIN
    -- check for clk setup/hold violations
    PROCESS (clk, x1, x2)
	VARIABLE xlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	-- only if the cell is registered.
	if (registered = reg) then

	    -- setup check
	    IF (clk'event AND (clk = '1')) THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - xlastev) >= Ts))
		    REPORT
		    "Setup ERROR on X: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - xlastev) >= Ts)) THEN
		    q_ts <= '1'; 
		    q_ts <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;

	    -- hold check
	    IF (x1'event OR
		x2'event) then
		ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th))
		    REPORT
		    "Hold ERROR ON X: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Th)) THEN
		    q_th <= '1';
		    q_th <= transport '0' after 1 ns;
		END IF;
		xlastev := NOW;
	    END IF;

	end if;
    END PROCESS;

    -- check for iclk setup/hold violations
    PROCESS (iclk, y)
	VARIABLE ylastev	: TIME := 0 ns;
	VARIABLE iclklastev	: TIME := 0 ns;
    BEGIN
	-- only if the cell is registered.
	if (bta_sel = xreg) then

	    -- setup check
	    IF (iclk'event AND (iclk = '1')) THEN
		ASSERT ((NOW = 0 ns) OR (NOW - ylastev) >= Tis)
		    REPORT
		    "Setup ERROR ON Y: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR (NOW - ylastev) >= Tis) THEN
		    iregq_ts <= '1'; 
		    iregq_ts <= transport '0' after 1 ns;
		END IF;
		iclklastev := NOW;
	    END IF;

	    -- hold check
	    IF (y'event) then
		ASSERT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Tih))
		    REPORT
		    "Hold ERROR ON Y: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Tih)) THEN
		    iregq_th <= '1'; 
		    iregq_th <= transport '0' after 1 ns;
		END IF;
		ylastev := NOW;
	    END IF;

	end if;
    END PROCESS;

    -- check clk pulse width
    PROCESS (clk)
	VARIABLE clklastev : TIME := 0 ns;
    BEGIN
	-- only if the cell is registered.
	if (registered = reg) then

	    IF (clk = '0') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh))
		    REPORT
		    "Pulse Width (H) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twh)) THEN
		    q_twh <= '1'; 
		    q_twh <= transport '0' after 1 ns;
		END IF;
	    ELSIF (clk = '1') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl))
		    REPORT
		    "Pulse Width (L) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklastev) >= Twl)) THEN
		    q_twl <= '1'; 
		    q_twl <= transport '0' after 1 ns;
		END IF;
	    END IF;
	    clklastev := NOW;
	end if;
    END PROCESS;

    -- check iclk pulse width
    PROCESS (iclk)
	VARIABLE iclklastev : TIME := 0 ns;
    BEGIN
	-- only if the cell is registered.
	if (bta_sel = xreg) then

	    IF (iclk = '0') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twh))
		    REPORT
		    "Pulse Width (H) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twh)) THEN
		    iregq_twh <= '1'; 
		    iregq_twh <= transport '0' after 1 ns;
		END IF;
	    ELSIF (iclk = '1') THEN
	       ASSERT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twl))
		    REPORT
		    "Pulse Width (L) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - iclklastev) >= Twl)) THEN
		    iregq_twl <= '1'; 
		    iregq_twl <= transport '0' after 1 ns;
		END IF;
	    END IF;
	    iclklastev := NOW;
	end if;
    END PROCESS;

    -- IS THIS CHECK REallY NECESSARY AND VALID????  See notes below.
    -- check for invalid control
    PROCESS (clk)
    BEGIN
	IF (clk = '1') THEN
	    ASSERT NOT ((ss = '1') AND (sr = '1'))
		REPORT
		"ERROR: Preset & Clear both Active: Setting outputs to unknown"
		SEVERITY warning;
	    IF ((ss = '1') AND (sr = '1')) THEN
		q_setreset <= '1';
		q_setreset <= transport '0' after 1 ns;
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Output Register.
    PROCESS (clk, sr, ss, q_ts, q_th, q_twh, q_twl, q_setreset)
    BEGIN
	IF ((q_ts = '1') OR (q_th = '1') OR (q_twh = '1') OR (q_twl = '1')
	OR (q_setreset = '1')) THEN
	    q <= 'X' after Tco;
	ELSIF ((clk = '1') AND clk'event) THEN
	    IF (sr = '1') THEN
		q <= '0';
	    ELSIF (ss = '1') THEN
		q <= '1';
	    ELSE
		q <= x1 XOR x2 AFTER Tco;
	    END IF;
	END IF;
    END PROCESS;

 -- Since the sr and ss terms come from product terms, most of their
 -- delay is modeled in c335m.  They are really NOT synchronous for this
 -- model.  Their affect on QFB is not 0, but there is no information given
 -- in the data sheet for these parameters.

    -- Simulate the Feedback.
    PROCESS (q)
    BEGIN
	IF (q = '1') THEN
	    qfb <= '0';
	ELSE
	    qfb <= '1';
	END IF;
    END PROCESS;

    -- Simulate the Output.
    PROCESS (q, oe, x1, x2)
    BEGIN
	IF (oe = '1') THEN
	    IF (oe'event) THEN
		IF (registered = reg) THEN
		    y <= NOT q AFTER Tpzx;
		ELSIF (registered = comb) THEN
		    y <= NOT (x1 XOR x2) AFTER Tpzx;
		END IF;
	    ELSE
		IF (registered = reg) THEN
		    y <= NOT q;
		ELSIF (registered = comb) THEN
		    y <= NOT (x1 XOR x2) AFTER Tpd;
		END IF;
	    END IF;
	ELSE
	    IF (oe'event) THEN
		y <= 'Z' AFTER Tpxz;
	    ELSE
		y <= 'Z';
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Input Register.
    PROCESS (iclk, iregq_ts, iregq_th, iregq_twh, iregq_twl)
    BEGIN
	IF ((iregq_ts = '1') OR (iregq_th = '1') OR (iregq_twh = '1')
	OR (iregq_twl = '1')) THEN
	    iregq <= 'X' after (Tico - Tpd);
	ELSIF ((iclk = '1') AND iclk'event) THEN
	    IF (y = '1') THEN
		iregq <= '1' AFTER (Tico - Tpd);
	    ELSE
		iregq <= '0' AFTER (Tico - Tpd);
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Feedback Mux.
    PROCESS (iregq, y)
    BEGIN
	IF (bta_sel = xreg) THEN
	    fb <= iregq;
	ELSIF (bta_sel = xpin) THEN
	    IF (y = '1') THEN
		fb <= '1';
	    ELSE
		fb <= '0';
	    END IF;
	END IF;
    END PROCESS;
END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c34xckmx IS
    GENERIC (
	Tin	: TIME	:=  7 ns;
	Texp	: TIME	:= 14 ns;
	Tpia	: TIME	:= 16 ns;
	Tlac	: TIME	:= 12 ns;
	Tlad	: TIME	:= 14 ns;
	Tic	: TIME	:= 16 ns;
	Tics	: TIME	:=  2 ns;
	Tclr	: TIME	:=  6 ns;
	Tpre	: TIME	:=  6 ns;
	Trsu	: TIME	:=  8 ns;
	Trh	: TIME	:=  8 ns;
	Tcomb	: TIME	:=  4 ns;
	Tlatch	: TIME	:=  4 ns;
	Trd	: TIME	:=  2 ns;
	Tio	: TIME	:=  6 ns;
	Tod	: TIME	:=  5 ns;
	Txz	: TIME	:= 11 ns;
	Tzx	: TIME	:= 11 ns;
	Tfd	: TIME	:=  1 ns;
	Tpcw	: TIME 	:=  6 ns;
	Tpcr	: TIME	:=  6 ns;
	Tch	: time	:= 10 ns;
	Tcl	: TIME	:= 10 ns);
    PORT (
	x	: IN	std_logic;
	oe	: IN	std_logic;
	fb	: OUT	std_logic);
END c34xckmx;

ARCHITECTURE sim OF c34xckmx IS
BEGIN

    -- Simulate the Clock Select Mux.
    PROCESS (x, oe)						
    BEGIN

	    fb <= NOT(x) AND OE;

    END PROCESS;

END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c34xexin IS
    GENERIC (
	Tin	: TIME	:=  7 ns;
	Texp	: TIME	:= 14 ns;
	Tpia	: TIME	:= 16 ns;
	Tlac	: TIME	:= 12 ns;
	Tlad	: TIME	:= 14 ns;
	Tic	: TIME	:= 16 ns;
	Tics	: TIME	:=  2 ns;
	Tclr	: TIME	:=  6 ns;
	Tpre	: TIME	:=  6 ns;
	Trsu	: TIME	:=  8 ns;
	Trh	: TIME	:=  8 ns;
	Tcomb	: TIME	:=  4 ns;
	Tlatch	: TIME	:=  4 ns;
	Trd	: TIME	:=  2 ns;
	Tio	: TIME	:=  6 ns;
	Tod	: TIME	:=  5 ns;
	Txz	: TIME	:= 11 ns;
	Tzx	: TIME	:= 11 ns;
	Tfd	: TIME	:=  1 ns;
	Tpcw	: TIME 	:=  6 ns;
	Tpcr	: TIME	:=  6 ns;
	Tch	: time	:= 10 ns;
	Tcl	: TIME	:= 10 ns);
    PORT (
	x	: IN	std_logic;
	expsrc	: IN	std_logic;
	exp	: IN	std_logic;
	fb	: OUT	std_logic);
END c34xexin;

ARCHITECTURE sim OF c34xexin IS
BEGIN

    -- Simulate the Expander Array.
    PROCESS (x, expsrc, exp)						
    BEGIN
	IF (exp = '1') THEN						
	    fb <= x AFTER Texp;
	ELSE									
	    fb <= NOT(expsrc) AFTER Texp;
	END IF;
    END PROCESS;

END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c34xexp IS
    GENERIC (
	Tin	: TIME	:=  7 ns;
	Texp	: TIME	:= 14 ns;
	Tpia	: TIME	:= 16 ns;
	Tlac	: TIME	:= 12 ns;
	Tlad	: TIME	:= 14 ns;
	Tic	: TIME	:= 16 ns;
	Tics	: TIME	:=  2 ns;
	Tclr	: TIME	:=  6 ns;
	Tpre	: TIME	:=  6 ns;
	Trsu	: TIME	:=  8 ns;
	Trh	: TIME	:=  8 ns;
	Tcomb	: TIME	:=  4 ns;
	Tlatch	: TIME	:=  4 ns;
	Trd	: TIME	:=  2 ns;
	Tio	: TIME	:=  6 ns;
	Tod	: TIME	:=  5 ns;
	Txz	: TIME	:= 11 ns;
	Tzx	: TIME	:= 11 ns;
	Tfd	: TIME	:=  1 ns;
	Tpcw	: TIME 	:=  6 ns;
	Tpcr	: TIME	:=  6 ns;
	Tch	: time	:= 10 ns;
	Tcl	: TIME	:= 10 ns);
    PORT (
	x	: IN	std_logic;
	expsrc	: IN	std_logic;
	exp	: IN	std_logic;
	fb	: OUT	std_logic);
END c34xexp;

ARCHITECTURE sim OF c34xexp IS
BEGIN

    -- Simulate the Expander Array.
    PROCESS (x, expsrc, exp)						
    BEGIN
	IF (exp = '1') THEN						
	    fb <= x AFTER Texp;
	ELSE									
	    fb <= expsrc AFTER Texp;
	END IF;
    END PROCESS;

END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c34xh IS
    GENERIC (
	Tin	: TIME	:=  7 ns;
	Texp	: TIME	:= 14 ns;
	Tpia	: TIME	:= 16 ns;
	Tlac	: TIME	:= 12 ns;
	Tlad	: TIME	:= 14 ns;
	Tic	: TIME	:= 16 ns;
	Tics	: TIME	:=  2 ns;
	Tclr	: TIME	:=  6 ns;
	Tpre	: TIME	:=  6 ns;
	Trsu	: TIME	:=  8 ns;
	Trh	: TIME	:=  8 ns;
	Tcomb	: TIME	:=  4 ns;
	Tlatch	: TIME	:=  4 ns;
	Trd	: TIME	:=  2 ns;
	Tio	: TIME	:=  6 ns;
	Tod	: TIME	:=  5 ns;
	Txz	: TIME	:= 11 ns;
	Tzx	: TIME	:= 11 ns;
	Tfd	: TIME	:=  1 ns;
	Tpcw	: TIME 	:=  6 ns;
	Tpcr	: TIME	:=  6 ns;
	Tch	: time	:= 10 ns;
	Tcl	: TIME	:= 10 ns
    );
    PORT (
	x1	: IN	std_logic;
	x2	: IN	std_logic;
	as	: IN	std_logic;
	ar	: IN	std_logic;
	clkpt	: IN	std_logic;
	clklab	: IN	std_logic;
	clksel	: IN	std_logic;
	exp	: IN	std_logic;		-- This is unused.
	qfb	: OUT	std_logic := '0');

END c34xh;

ARCHITECTURE sim OF c34xh IS
    SIGNAL	x1_in	: std_logic	:= '0';
    SIGNAL	x2_in	: std_logic	:= '0';
    SIGNAL	as_in	: std_logic	:= '0';
    SIGNAL	ar_in	: std_logic	:= '0';
    SIGNAL	clkpt_in : std_logic := '0';
    SIGNAL	clklab_in : std_logic := '0';
    SIGNAL	clkcell	: std_logic := '0';
    SIGNAL	q_trsu	: std_logic := '0';
    SIGNAL	q_trh	: std_logic := '0';
    SIGNAL	q_tchpt	: std_logic := '0';
    SIGNAL	q_tclpt	: std_logic := '0';
    SIGNAL	q_tchsys : std_logic := '0';
    SIGNAL	q_tclsys : std_logic := '0';
    SIGNAL	q_tpcwr	: std_logic	:= '0';
    SIGNAL	q_tpcws	: std_logic	:= '0';
    SIGNAL	q_tpcrr	: std_logic	:= '0';
    SIGNAL	q_tpcrs	: std_logic	:= '0';
    SIGNAL	q_clkchk : std_logic := '0';
BEGIN

    -- Simulate the Logic Array.
    PROCESS (x1, x2 , as, ar, clkpt, clklab)
    BEGIN
	x1_in <= x1 AFTER Tlad;
	x2_in <= x2 AFTER Tlad;
	as_in <= as AFTER Tlac;
	ar_in <= ar AFTER Tlac;
	clkpt_in <= clkpt AFTER Tic;
	clklab_in <= clklab AFTER Tics;
    END PROCESS;

    -- Simulate the Clock Mux.
    PROCESS (clkpt_in, clklab_in)
    BEGIN
	clkcell <= (clkpt_in OR (clksel AND clklab_in));
    END PROCESS;

    -- check for clk setup/hold violations
    PROCESS (clkcell, x1_in, x2_in)
	VARIABLE xlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	-- Check to see that Set & Reset aren't enabled
	IF ((as_in = '1') AND (ar_in = '1')) THEN

	    -- setup check
	    IF (clkcell'event AND (clkcell = '1')) THEN
		ASSERT ((NOW <= Tlac) OR ((NOW - xlastev) >= Trsu))
		    REPORT
		    "Setup ERROR on X: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW <= Tlac) OR ((NOW - xlastev) >= Trsu)) THEN
		    q_trsu <= '1'; 
		    q_trsu <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;

	    -- hold check
	    IF (x1_in'event OR
		x2_in'event) then
		ASSERT ((NOW <= Tlad) OR ((NOW - clklastev) >= Trh))
		    REPORT
		    "Hold ERROR ON X: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW <= Tlad) OR ((NOW - clklastev) >= Trh)) THEN
		    q_trh <= '1';
		    q_trh <= transport '0' after 1 ns;
		END IF;
		xlastev := NOW;
	    END IF;

	END IF;
    END PROCESS;

    -- check clkpt_in pulse width
    PROCESS (clkpt_in)
	VARIABLE clkptlastev : TIME := 0 ns;
    BEGIN
	-- Check to see that Set & Reset aren't enabled
	IF ((as_in = '1') AND (ar_in = '1')) THEN
	    IF (clkpt_in = '0') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - clkptlastev) >= Tch))
		    REPORT
		    "Pulse Width (H) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clkptlastev) >= Tch)) THEN
		    q_tchpt <= '1'; 
		    q_tchpt <= transport '0' after 1 ns;
		END IF;
	    ELSIF (clkpt_in = '1') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - clkptlastev) >= Tcl))
		    REPORT
		    "Pulse Width (L) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clkptlastev) >= Tcl)) THEN
		    q_tclpt <= '1'; 
		    q_tclpt <= transport '0' after 1 ns;
		END IF;
	    END IF;
	clkptlastev := NOW;
	END IF;
    END PROCESS;

    -- check clklab pulse width
    PROCESS (clklab_in)
	VARIABLE clklablastev : TIME := 0 ns;
    BEGIN
	-- Check to see that Set & Reset aren't enabled
	IF ((as_in = '1') AND (ar_in = '1')) THEN
	    IF (clklab_in = '0') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - clklablastev) >= Tch))
		    REPORT
		    "Pulse Width (H) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklablastev) >= Tch)) THEN
		    q_tchsys <= '1'; 
		    q_tchsys <= transport '0' after 1 ns;
		END IF;
	    ELSIF (clklab_in = '1') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - clklablastev) >= Tcl))
		    REPORT
		    "Pulse Width (L) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklablastev) >= Tcl)) THEN
		    q_tclsys <= '1'; 
		    q_tclsys <= transport '0' after 1 ns;
		END IF;
	    END IF;
	clklablastev := NOW;
	END IF;
    END PROCESS;

    -- check SET pulse width
    PROCESS (as_in)
	VARIABLE as_inlastev : TIME := 0 ns;
    BEGIN
	IF (as_in = '1') THEN
	    ASSERT ((NOW <= Tlac) OR ((NOW - as_inlastev) >= Tpcw))
		REPORT
		"Pulse Width (L) ERROR on AS: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW <= Tlac) OR ((NOW - as_inlastev) >= Tpcw)) THEN
		q_tpcws <= '1'; 
		q_tpcws <= transport '0' after 1 ns;
	    END IF;
	END IF;
	as_inlastev := NOW;
    END PROCESS;

    -- check RESET pulse width
    PROCESS (ar_in)
	VARIABLE ar_inlastev : TIME := 0 ns;
    BEGIN
	IF (ar_in = '1') THEN
	    ASSERT ((NOW <= Tlac) OR ((NOW - ar_inlastev) >= Tpcw))
		REPORT
		"Pulse Width (L) ERROR on AR: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW <= Tlac) OR ((NOW - ar_inlastev) >= Tpcw)) THEN
		q_tpcwr <= '1'; 
		q_tpcwr <= transport '0' after 1 ns;
	    END IF;
	END IF;
	ar_inlastev := NOW;
    END PROCESS;

    -- check for Asynchronous Reset Recovery violation
    PROCESS (clkcell, ar_in)
	VARIABLE ar_inlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	IF (ar_in'event) then
	    ar_inlastev := NOW;
	END IF;
	IF (ar_in = '0') THEN
	    IF (clkcell'event AND (clkcell = '1')) THEN
		ASSERT ((NOW <= Tlac) OR (NOW - ar_inlastev) >= Tpcr)
		    REPORT
		    "Recovery ERROR on AR: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW <= Tlac) OR ((NOW - ar_inlastev) >= Tpcr)) THEN
		    q_tpcrr <= '1'; 
		    q_tpcrr <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;
	END IF;
    END PROCESS;

    -- check for Asynchronous Set Recovery violation
    PROCESS (clkcell, as_in)
	VARIABLE as_inlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	IF (as_in'event) then
	    as_inlastev := NOW;
	END IF;
	IF (as_in = '0') THEN
	    IF (clkcell'event AND (clkcell = '1')) THEN
		ASSERT ((NOW <= Tlac) OR (NOW - as_inlastev) >= Tpcr)
		    REPORT
		    "Recovery ERROR on AS: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW <= Tlac) OR ((NOW - as_inlastev) >= Tpcr)) THEN
		    q_tpcrs <= '1'; 
		    q_tpcrs <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Register.
    PROCESS (x1_in, x2_in, clkcell, ar_in, as_in, q_trsu, q_trh, q_tchpt,
		q_tchsys, q_tclpt, q_tclsys, q_tpcwr, q_tpcws, q_tpcrr,
		q_tpcrs, q_clkchk)
    BEGIN
	IF ((q_trsu = '1') OR (q_trh    = '1') OR (q_tchpt  = '1')
	OR (q_tclpt = '1') OR (q_tchsys = '1') OR (q_tclsys = '1')
	OR (q_tpcwr = '1') OR (q_tpcws  = '1') OR (q_tpcrr  = '1')
	OR (q_tpcrs = '1') OR (q_clkchk = '1')) THEN

	    qfb <= 'X' AFTER Trd + Tfd;            
	ELSIF ((ar_in = '0') AND (as_in = '0')) THEN
	    IF (clkcell = '1' AND NOT clkcell'event) then

		qfb <= (x1_in XOR x2_in) AFTER Tcomb + Tfd;
	    ELSIF ((clkcell = '1') AND clkcell'event) then

		qfb <= (x1_in XOR x2_in) AFTER Tlatch + Tfd;
	    END IF;
	ELSIF (ar_in = '0') THEN

	    qfb <= '0' AFTER Tclr + Tfd;
	ELSIF (as_in = '0') THEN

	    qfb <= '1' AFTER Tpre + Tfd;
	ELSIF ((clkcell = '1') AND clkcell'event) THEN

		qfb <= (x1_in XOR x2_in) AFTER Trd + Tfd;
	END IF;
    END PROCESS;
END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c34xin IS
    GENERIC (
	Tin	: TIME	:=  7 ns;
	Texp	: TIME	:= 14 ns;
	Tpia	: TIME	:= 16 ns;
	Tlac	: TIME	:= 12 ns;
	Tlad	: TIME	:= 14 ns;
	Tic	: TIME	:= 16 ns;
	Tics	: TIME	:=  2 ns;
	Tclr	: TIME	:=  6 ns;
	Tpre	: TIME	:=  6 ns;
	Trsu	: TIME	:=  8 ns;
	Trh	: TIME	:=  8 ns;
	Tcomb	: TIME	:=  4 ns;
	Tlatch	: TIME	:=  4 ns;
	Trd	: TIME	:=  2 ns;
	Tio	: TIME	:=  6 ns;
	Tod	: TIME	:=  5 ns;
	Txz	: TIME	:= 11 ns;
	Tzx	: TIME	:= 11 ns;
	Tfd	: TIME	:=  1 ns;
	Tpcw	: TIME 	:=  6 ns;
	Tpcr	: TIME	:=  6 ns;
	Tch	: time	:= 10 ns;
	Tcl	: TIME	:= 10 ns);
    PORT (
	x	: IN std_logic;
	fb	: OUT std_logic);
END c34xin;

ARCHITECTURE sim OF c34xin IS
BEGIN

    -- Simulate the Input Pad.
    PROCESS (x)
    BEGIN
	fb <= x AFTER Tin;
    END PROCESS;

END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c34xm IS
    GENERIC (
	Tin	: TIME	:=  7 ns;
	Texp	: TIME	:= 14 ns;
	Tpia	: TIME	:= 16 ns;
	Tlac	: TIME	:= 12 ns;
	Tlad	: TIME	:= 14 ns;
	Tic	: TIME	:= 16 ns;
	Tics	: TIME	:=  2 ns;
	Tclr	: TIME	:=  6 ns;
	Tpre	: TIME	:=  6 ns;
	Trsu	: TIME	:=  8 ns;
	Trh	: TIME	:=  8 ns;
	Tcomb	: TIME	:=  4 ns;
	Tlatch	: TIME	:=  4 ns;
	Trd	: TIME	:=  2 ns;
	Tio	: TIME	:=  6 ns;
	Tod	: TIME	:=  5 ns;
	Txz	: TIME	:= 11 ns;
	Tzx	: TIME	:= 11 ns;
	Tfd	: TIME	:=  1 ns;
	Tpcw	: TIME 	:=  6 ns;
	Tpcr	: TIME	:=  6 ns;
	Tch	: time	:= 10 ns;
	Tcl	: TIME	:= 10 ns
    );
    PORT (
	x1	: IN	std_logic;
	x2	: IN	std_logic;
	as	: IN	std_logic;
	ar	: IN	std_logic;
	clkpt	: IN	std_logic;
	clklab	: IN	std_logic;
	clksel	: IN	std_logic;
	oe	: IN	std_logic;
	y	: INOUT	std_logic;
	qfb	: OUT	std_logic := '0';
	yfb	: OUT	std_logic);
END c34xm;

ARCHITECTURE sim OF c34xm IS
    SIGNAL	q	: std_logic	:= '0';
    SIGNAL	x1_in	: std_logic	:= '0';
    SIGNAL	x2_in	: std_logic	:= '0';
    SIGNAL	as_in	: std_logic	:= '0';
    SIGNAL	ar_in	: std_logic	:= '0';
    SIGNAL	clkpt_in : std_logic := '0';
    SIGNAL	clklab_in : std_logic := '0';
    SIGNAL	clkcell	: std_logic := '0';
    SIGNAL	oe_in	: std_logic	:= '1';
    SIGNAL	q_trsu	: std_logic := '0';
    SIGNAL	q_trh	: std_logic := '0';
    SIGNAL	q_tchpt	: std_logic := '0';
    SIGNAL	q_tclpt	: std_logic := '0';
    SIGNAL	q_tchsys : std_logic := '0';
    SIGNAL	q_tclsys : std_logic := '0';
    SIGNAL	q_tpcwr	: std_logic	:= '0';
    SIGNAL	q_tpcws	: std_logic	:= '0';
    SIGNAL	q_tpcrr	: std_logic	:= '0';
    SIGNAL	q_tpcrs	: std_logic	:= '0';
    SIGNAL	q_clkchk : std_logic := '0';
BEGIN

    -- Simulate the Logic Array.
    PROCESS (x1, x2 , as, ar, oe, clkpt, clklab)
    BEGIN
	x1_in <= x1 AFTER Tlad;
	x2_in <= x2 AFTER Tlad;
	as_in <= as AFTER Tlac;
	ar_in <= ar AFTER Tlac;
	oe_in <= oe AFTER Tlac;
	clkpt_in <= clkpt AFTER Tic;
	clklab_in <= clklab AFTER Tics;
    END PROCESS;

    -- Simulate the Clock Mux.
    PROCESS (clkpt_in, clklab_in)
    BEGIN
	clkcell <= (clkpt_in OR (clksel AND clklab_in));
    END PROCESS;

    -- check for clk setup/hold violations
    PROCESS (clkcell, x1_in, x2_in)
	VARIABLE xlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	-- Check to see that Set & Reset aren't enabled
	IF ((as_in = '1') AND (ar_in = '1')) THEN

	    -- setup check
	    IF (clkcell'event AND (clkcell = '1')) THEN
		ASSERT ((NOW <= Tlac) OR ((NOW - xlastev) >= Trsu))
		    REPORT
		    "Setup ERROR on X: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW <= Tlac) OR ((NOW - xlastev) >= Trsu)) THEN
		    q_trsu <= '1'; 
		    q_trsu <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;

	    -- hold check
	    IF (x1_in'event OR
		x2_in'event) then
		ASSERT ((NOW <= Tlad) OR ((NOW - clklastev) >= Trh))
		    REPORT
		    "Hold ERROR ON X: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW <= Tlad) OR ((NOW - clklastev) >= Trh)) THEN
		    q_trh <= '1';
		    q_trh <= transport '0' after 1 ns;
		END IF;
		xlastev := NOW;
	    END IF;

	END IF;
    END PROCESS;

    -- check clkpt_in pulse width
    PROCESS (clkpt_in)
	VARIABLE clkptlastev : TIME := 0 ns;
    BEGIN
	-- Check to see that Set & Reset aren't enabled
	IF ((as_in = '1') AND (ar_in = '1')) THEN
	    IF (clkpt_in = '0') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - clkptlastev) >= Tch))
		    REPORT
		    "Pulse Width (H) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clkptlastev) >= Tch)) THEN
		    q_tchpt <= '1'; 
		    q_tchpt <= transport '0' after 1 ns;
		END IF;
	    ELSIF (clkpt_in = '1') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - clkptlastev) >= Tcl))
		    REPORT
		    "Pulse Width (L) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clkptlastev) >= Tcl)) THEN
		    q_tclpt <= '1'; 
		    q_tclpt <= transport '0' after 1 ns;
		END IF;
	    END IF;
	clkptlastev := NOW;
	END IF;
    END PROCESS;

    -- check clklab pulse width
    PROCESS (clklab_in)
	VARIABLE clklablastev : TIME := 0 ns;
    BEGIN
	-- Check to see that Set & Reset aren't enabled
	IF ((as_in = '1') AND (ar_in = '1')) THEN
	    IF (clklab_in = '0') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - clklablastev) >= Tch))
		    REPORT
		    "Pulse Width (H) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklablastev) >= Tch)) THEN
		    q_tchsys <= '1'; 
		    q_tchsys <= transport '0' after 1 ns;
		END IF;
	    ELSIF (clklab_in = '1') THEN
		ASSERT ((NOW = 0 ns) OR ((NOW - clklablastev) >= Tcl))
		    REPORT
		    "Pulse Width (L) ERROR on CLK: Setting output to unknown"
		    SEVERITY WARNING;
		IF NOT ((NOW = 0 ns) OR ((NOW - clklablastev) >= Tcl)) THEN
		    q_tclsys <= '1'; 
		    q_tclsys <= transport '0' after 1 ns;
		END IF;
	    END IF;
	clklablastev := NOW;
	END IF;
    END PROCESS;

    -- check SET pulse width
    PROCESS (as_in)
	VARIABLE as_inlastev : TIME := 0 ns;
    BEGIN
	IF (as_in = '1') THEN
	    ASSERT ((NOW <= Tlac) OR ((NOW - as_inlastev) >= Tpcw))
		REPORT
		"Pulse Width (L) ERROR on AS: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW <= Tlac) OR ((NOW - as_inlastev) >= Tpcw)) THEN
		q_tpcws <= '1'; 
		q_tpcws <= transport '0' after 1 ns;
	    END IF;
	END IF;
	as_inlastev := NOW;
    END PROCESS;

    -- check RESET pulse width
    PROCESS (ar_in)
	VARIABLE ar_inlastev : TIME := 0 ns;
    BEGIN
	IF (ar_in = '1') THEN
	    ASSERT ((NOW <= Tlac) OR ((NOW - ar_inlastev) >= Tpcw))
		REPORT
		"Pulse Width (L) ERROR on AR: Setting output to unknown"
		SEVERITY WARNING;
	    IF NOT ((NOW <= Tlac) OR ((NOW - ar_inlastev) >= Tpcw)) THEN
		q_tpcwr <= '1'; 
		q_tpcwr <= transport '0' after 1 ns;
	    END IF;
	END IF;
	ar_inlastev := NOW;
    END PROCESS;

    -- check for Asynchronous Reset Recovery violation
    PROCESS (clkcell, ar_in)
	VARIABLE ar_inlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	IF (ar_in'event) then
	    ar_inlastev := NOW;
	END IF;
	IF (ar_in = '0') THEN
	    IF (clkcell'event AND (clkcell = '1')) THEN
		ASSERT ((NOW <= Tlac) OR (NOW - ar_inlastev) >= Tpcr)
		    REPORT
		    "Recovery ERROR on AR: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW <= Tlac) OR ((NOW - ar_inlastev) >= Tpcr)) THEN
		    q_tpcrr <= '1'; 
		    q_tpcrr <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;
	END IF;
    END PROCESS;

    -- check for Asynchronous Set Recovery violation
    PROCESS (clkcell, as_in)
	VARIABLE as_inlastev	: TIME := 0 ns;
	VARIABLE clklastev	: TIME := 0 ns;
    BEGIN
	IF (as_in'event) then
	    as_inlastev := NOW;
	END IF;
	IF (as_in = '0') THEN
	    IF (clkcell'event AND (clkcell = '1')) THEN
		ASSERT ((NOW <= Tlac) OR (NOW - as_inlastev) >= Tpcr)
		    REPORT
		    "Recovery ERROR on AS: Setting output to unknown" 
		    SEVERITY WARNING;
		IF NOT ((NOW <= Tlac) OR ((NOW - as_inlastev) >= Tpcr)) THEN
		    q_tpcrs <= '1'; 
		    q_tpcrs <= transport '0' after 1 ns;
		END IF;
		clklastev := NOW;
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Register.
    PROCESS (x1_in, x2_in, clkcell, ar_in, as_in, q_trsu, q_trh, q_tchpt,
		q_tchsys, q_tclpt, q_tclsys, q_tpcwr, q_tpcws, q_tpcrr,
		q_tpcrs, q_clkchk)
    BEGIN
	IF ((q_trsu = '1') OR (q_trh    = '1') OR (q_tchpt  = '1')
	OR (q_tclpt = '1') OR (q_tchsys = '1') OR (q_tclsys = '1')
	OR (q_tpcwr = '1') OR (q_tpcws  = '1') OR (q_tpcrr  = '1')
	OR (q_tpcrs = '1') OR (q_clkchk = '1')) THEN
	    q   <= 'X' AFTER Trd;
	    qfb <= 'X' AFTER Trd + Tfd;            
	ELSIF ((ar_in = '0') AND (as_in = '0')) THEN
	    IF (clkcell = '1' AND NOT clkcell'event) then
		q   <= (x1_in XOR x2_in) AFTER Tcomb;
		qfb <= (x1_in XOR x2_in) AFTER Tcomb + Tfd;
	    ELSIF ((clkcell = '1') AND clkcell'event) then
		q   <= (x1_in XOR x2_in) AFTER Tlatch;
		qfb <= (x1_in XOR x2_in) AFTER Tlatch + Tfd;
	    END IF;
	ELSIF (ar_in = '0') THEN
	    q   <= '0' AFTER Tclr;
	    qfb <= '0' AFTER Tclr + Tfd;
	ELSIF (as_in = '0') THEN
	    q   <= '1' AFTER Tpre;
	    qfb <= '1' AFTER Tpre + Tfd;
	ELSIF ((clkcell = '1') AND clkcell'event) THEN
		q   <= (x1_in XOR x2_in) AFTER Trd;
		qfb <= (x1_in XOR x2_in) AFTER Trd + Tfd;
	END IF;
    END PROCESS;

    -- Simulate the Output.
    PROCESS (q, oe_in)
    BEGIN
	IF (oe_in = '1') THEN
	    IF (oe_in'event) THEN
		y <= q AFTER Tzx;
	    ELSE
		y <= q AFTER Tod;
	    END IF;
	ELSE
	    IF (oe_in'event) THEN
		y <= 'Z' AFTER Txz;
	    ELSE
		y <= 'Z';
	    END IF;
	END IF;
    END PROCESS;

    -- Simulate the Y-Feedback.
    PROCESS (y)
    BEGIN
	IF (y = '1') THEN			
	    yfb <= '1' AFTER Tio;
	ELSE
	    yfb <= '0' AFTER Tio;
	END IF;
    END PROCESS;
END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

ENTITY c34xpia IS 
    GENERIC (
	Tin	: TIME	:=  7 ns;
	Texp	: TIME	:= 14 ns;
	Tpia	: TIME	:= 16 ns;
	Tlac	: TIME	:= 12 ns;
	Tlad	: TIME	:= 14 ns;
	Tic	: TIME	:= 16 ns;
	Tics	: TIME	:=  2 ns;
	Tclr	: TIME	:=  6 ns;
	Tpre	: TIME	:=  6 ns;
	Trsu	: TIME	:=  8 ns;
	Trh	: TIME	:=  8 ns;
	Tcomb	: TIME	:=  4 ns;
	Tlatch	: TIME	:=  4 ns;
	Trd	: TIME	:=  2 ns;
	Tio	: TIME	:=  6 ns;
	Tod	: TIME	:=  5 ns;
	Txz	: TIME	:= 11 ns;
	Tzx	: TIME	:= 11 ns;
	Tfd	: TIME	:=  1 ns;
	Tpcw	: TIME 	:=  6 ns;
	Tpcr	: TIME	:=  6 ns;
	Tch	: time	:= 10 ns;
	Tcl	: TIME	:= 10 ns);
    PORT (
	x	: IN	std_logic;
	fb	: OUT	std_logic);
END c34xpia;

ARCHITECTURE sim OF c34xpia IS

BEGIN
    fb <= x AFTER Tpia;
END sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c37xclk is
    generic (
	bsel	: 	polarity := ninv;

	tCLK	:	time :=  4000 ps;
	tIRD	:	time :=  1000 ps;
	tICOMB	:	time :=  3000 ps;
	tILAT	:	time :=  5500 ps;
	tIRSU	:	time :=  6000 ps;
	tIRH	:	time :=  2000 ps;
	tSOP	:	time :=  1500 ps;
	tORD	:	time :=  1000 ps;
	tOCOMB	:	time :=  3000 ps;
	tOLAT	:	time :=  5500 ps;
	tORSU	:	time :=  4500 ps;
	tORH	:	time :=  0000 ps;
	tOD	:	time :=  1000 ps;
	tXZ	:	time :=  8500 ps;
	tZX	:	time :=  8500 ps;
	tFB	:	time :=  0000 ps;
	tRST	:	time :=  8500 ps;
	tPST	:	time :=  8500 ps;
	tWL	:	time :=  2500 ps;
	tWH	:	time :=  2500 ps;
	tRW	:	time :=  8000 ps;
	tRR	:	time := 10000 ps;
	tPW	:	time :=  8000 ps;
	tPR	:	time := 10000 ps;
	tVCCO	:	time :=     0 ps );
    PORT (x	: in	std_logic;
	fb	: out	std_logic);

end c37xclk;

architecture sim of c37xclk is

begin

    process (x)
    begin
	if (bsel = ninv) then
	    fb <= transport x after Tclk;
	elsif (bsel = invt) then
	    fb <= transport NOT x after Tclk;
	end if;
    end process;

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c37xinp IS
    generic (
	iregister	: ireg_type	:= ireg;

	tCLK	:	time :=  4000 ps;
	tIRD	:	time :=  1000 ps;
	tICOMB	:	time :=  3000 ps;
	tILAT	:	time :=  5500 ps;
	tIRSU	:	time :=  6000 ps;
	tIRH	:	time :=  2000 ps;
	tSOP	:	time :=  1500 ps;
	tORD	:	time :=  1000 ps;
	tOCOMB	:	time :=  3000 ps;
	tOLAT	:	time :=  5500 ps;
	tORSU	:	time :=  4500 ps;
	tORH	:	time :=  0000 ps;
	tOD	:	time :=  1000 ps;
	tXZ	:	time :=  8500 ps;
	tZX	:	time :=  8500 ps;
	tFB	:	time :=  0000 ps;
	tRST	:	time :=  8500 ps;
	tPST	:	time :=  8500 ps;
	tWL	:	time :=  2500 ps;
	tWH	:	time :=  2500 ps;
	tRW	:	time :=  8000 ps;
	tRR	:	time := 10000 ps;
	tPW	:	time :=  8000 ps;
	tPR	:	time := 10000 ps;
	tVCCO	:	time :=     0 ps );

    port (d	: in	std_logic;
	clk	: in	std_logic;
	fb	: out	std_logic);
end c37xinp;

architecture sim of c37xinp is
    signal   	dclk		:	std_logic	:= '0';
    signal   	q1		:	std_logic	:= '0';
    signal	q2		:	std_logic	:= '0';
    signal	q3		:	std_logic	:= '0';
    signal	iregq_tis	: 	std_logic	:= '0';
    signal	iregq_tih	: 	std_logic	:= '0';
    signal	iregq_twh	: 	std_logic	:= '0';
    signal	iregq_twl	: 	std_logic	:= '0';
begin

    dclk <= clk;

    -- check for clk setup/hold violations
    process (dclk, d)

	variable dlastev	: time := 0 ns;
	variable clklastev	: time := 0 ns;

    begin
	-- only if not combinatorial.
	if (iregister /= comb) then
	    -- setup check
	    if (dclk'event AND (dclk = '1')) then
		assert ((dlastev = 0 ns) OR ((NOW - dlastev) >= Tirsu))
		    report
		    "Setup ERROR ON D: Setting output to unknown" 
		    severity warning;
		if NOT ((dlastev = 0 ns) OR ((NOW - dlastev) >= Tirsu)) then
		    iregq_tis <= '1'; 
		    iregq_tis <= transport '0' after 1 ns;
		end if;
		clklastev := NOW;
	    end if;

	    -- hold check
	    if (d'event) then
		asserT ((clklastev = 0 ns) OR ((NOW - clklastev) >= Tirh))
		    report
		    "Hold ERROR ON D: Setting output to unknown" 
		    severity warning;
		if NOT ((clklastev = 0 ns) OR ((NOW - clklastev) >= Tirh)) then
		    iregq_tih <= '1'; 
		    iregq_tih <= transport '0' after 1 ns;
		end if;
		dlastev := NOW;
	    end if;
	end if;
    end process;

    -- check clk pulse width
    process (dclk)

	variable clklastevhi,clklastevlo : time := 0 ns;

    begin
	-- only if not combinatorial.
	if (iregister /= comb) then
	    if (dclk = '0') then
		assert ((clklastevhi = 0 ns) OR ((NOW - clklastevhi) >= Twh))
		    report

		    "Pulse Width (H) ERROR on CLK: Setting output to unknown"
		    severity warning;
		if NOT ((clklastevhi = 0 ns) OR ((NOW-clklastevhi) >= Twh)) then
		    iregq_twh <= '1'; 
		    iregq_twh <= transport '0' after 1 ns;
		end if;
		clklastevlo := NOW;
	    elsif (dclk = '1') then
	       assert ((clklastevlo = 0 ns) OR ((NOW - clklastevlo) >= Twl))
		    report
		    "Pulse Width (L) ERROR on CLK: Setting output to unknown"
		    severity warning;
		if NOT ((clklastevlo = 0 ns) OR ((NOW-clklastevlo) >= Twl)) then
		    iregq_twl <= '1'; 
		    iregq_twl <= transport '0' after 1 ns;
		end if;
		clklastevhi := NOW;
	    end if;
	end if;
    end process;

    -- Simulate the Register.
    process (d, dclk, iregq_tis, iregq_tih, iregq_twh, iregq_twl)
    begin
	if ((iregq_tis = '1') OR (iregq_tih = '1') OR (iregq_twh = '1')
	OR (iregq_twl = '1')) then
	    q1 <= 'X' after Tird;
	    q2 <= 'X' after Tird;
	    q3 <= 'X' after Tird;
	elsif (dclk'event AND (dclk = '1')) then
	    q1 <= d after Tird;
	    q2 <= q1 after Tird;
	    q3 <= d after Tird;
	elsif (dclk = '1') then
	    q3 <= d after Tilat;
	end if;
    end process;

    -- Simulate the Mux.
    process (q1, q2, q3, d)
    begin
	if (iregister = comb) then
	    fb <= d after Ticomb;
	elsif (iregister = ireg) then
	    fb <= q1;
	elsif (iregister = dblireg) then	
	    fb <= q2;
	elsif (iregister = iltch) then
	    fb <= q3;
	end if;
    end process;
end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c37xm is
    generic (
	bsel	: 	polarity := ninv;

	tCLK	:	time :=  4000 ps;
	tIRD	:	time :=  1000 ps;
	tICOMB	:	time :=  3000 ps;
	tILAT	:	time :=  5500 ps;
	tIRSU	:	time :=  6000 ps;
	tIRH	:	time :=  2000 ps;
	tSOP	:	time :=  1500 ps;
	tORD	:	time :=  1000 ps;
	tOCOMB	:	time :=  3000 ps;
	tOLAT	:	time :=  5500 ps;
	tORSU	:	time :=  4500 ps;
	tORH	:	time :=  0000 ps;
	tOD	:	time :=  1000 ps;
	tXZ	:	time :=  8500 ps;
	tZX	:	time :=  8500 ps;
	tFB	:	time :=  0000 ps;
	tRST	:	time :=  8500 ps;
	tPST	:	time :=  8500 ps;
	tWL	:	time :=  2500 ps;
	tWH	:	time :=  2500 ps;
	tRW	:	time :=  8000 ps;
	tRR	:	time := 10000 ps;
	tPW	:	time :=  8000 ps;
	tPR	:	time := 10000 ps;
	tVCCO	:	time :=     0 ps );

    port (x	: in	std_logic;
	oe	: in	std_logic;
	y	: inout	std_logic;
	fb	: out	std_logic);
end c37xm;

architecture sim of c37xm is
begin

    -- Simulate the I/O Macro-cell.
    process (oe, x)
    begin
	if (bsel = invt) then
	    if (oe'event) then
		if (oe = '1') then

		    y <= NOT x AFTER (Tzx + Tvcco);

		else

		    y <= 'Z' AFTER (Txz + Tvcco);

		end if;
	    else
		if (oe = '1') then

		    y <= NOT x  AFTER (Tod + Tvcco) ;

		else
		    y <= 'Z';
		end if;
	    end if;
	elsif (bsel = ninv) then
	    if (oe'event) then
		if (oe = '1') then

		    y <= x AFTER (Tzx + Tvcco);

		else

		    y <= 'Z' AFTER (Txz + Tvcco);

		end if;
	    else
		if (oe = '1') then

		    y <= x AFTER (Tod + Tvcco);

		else
		    y <= 'Z';
		end if;
	    end if;
	end if;
    end process;

    -- Simulate the feedback.
    process (y)
    begin

	fb <= y;

    end process;
end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c37xmux is
    generic (

	tCLK	:	time :=  4000 ps;
	tIRD	:	time :=  1000 ps;
	tICOMB	:	time :=  3000 ps;
	tILAT	:	time :=  5500 ps;
	tIRSU	:	time :=  6000 ps;
	tIRH	:	time :=  2000 ps;
	tSOP	:	time :=  1500 ps;
	tORD	:	time :=  1000 ps;
	tOCOMB	:	time :=  3000 ps;
	tOLAT	:	time :=  5500 ps;
	tORSU	:	time :=  4500 ps;
	tORH	:	time :=  0000 ps;
	tOD	:	time :=  1000 ps;
	tXZ	:	time :=  8500 ps;
	tZX	:	time :=  8500 ps;
	tFB	:	time :=  0000 ps;
	tRST	:	time :=  8500 ps;
	tPST	:	time :=  8500 ps;
	tWL	:	time :=  2500 ps;
	tWH	:	time :=  2500 ps;
	tRW	:	time :=  8000 ps;
	tRR	:	time := 10000 ps;
	tPW	:	time :=  8000 ps;
	tPR	:	time := 10000 ps;
	tVCCO	:	time :=     0 ps );

    port (x	: in	std_logic;

	fb	: out	std_logic);

end c37xmux;

architecture sim of c37xmux is
begin

    -- Simulate the PIM.
    process (x)
    begin

	fb <= x AFTER Tsop;

    end process;

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c37xoreg is
    generic (
	oregister	: oreg_type	:= dreg;
	source		: src_type	:= src_ptm;

	tCLK	:	time :=  4000 ps;
	tIRD	:	time :=  1000 ps;
	tICOMB	:	time :=  3000 ps;
	tILAT	:	time :=  5500 ps;
	tIRSU	:	time :=  6000 ps;
	tIRH	:	time :=  2000 ps;
	tSOP	:	time :=  1500 ps;
	tORD	:	time :=  1000 ps;
	tOCOMB	:	time :=  3000 ps;
	tOLAT	:	time :=  5500 ps;
	tORSU	:	time :=  4500 ps;
	tORH	:	time :=  0000 ps;
	tOD	:	time :=  1000 ps;
	tXZ	:	time :=  8500 ps;
	tZX	:	time :=  8500 ps;
	tFB	:	time :=  0000 ps;
	tRST	:	time :=  8500 ps;
	tPST	:	time :=  8500 ps;
	tWL	:	time :=  2500 ps;
	tWH	:	time :=  2500 ps;
	tRW	:	time :=  8000 ps;
	tRR	:	time := 10000 ps;
	tPW	:	time :=  8000 ps;
	tPR	:	time := 10000 ps;
	tVCCO	:	time :=     0 ps );

    port (as	: in	std_logic;
	x	: in	std_logic;
	clk	: in	std_logic;
	ar	: in	std_logic;
	fb	: out	std_logic;
	q	: inout	std_logic := '0');

end c37xoreg;

architecture sim of c37xoreg is

    signal	regq_ts		: std_logic	:= '0';
    signal	regq_th		: std_logic	:= '0';
    signal	regq_twh	: std_logic	:= '0';
    signal	regq_twl	: std_logic	:= '0';
    signal	regq_tpw	: std_logic	:= '0';
    signal	regq_tpr	: std_logic	:= '0';
    signal	regq_trr	: std_logic	:= '0';
    signal	regq_trw	: std_logic	:= '0';
    signal	ireg_err	: std_logic	:= '0';
    signal	dclk		: std_logic;

begin

    dclk <= clk;

    -- check for clk setup/hold violations
    process (dclk, x)
	variable xlastev, clklastev	: time := 0 ns;
    begin
	-- only if not combinatorial
	if (oregister /= cmb) then
	    -- setup check
	    if (dclk'event AND (dclk = '1')) then
		if (source = src_ptm) then

			assert ((xlastev = 0 ns) OR ((NOW - xlastev) >= Torsu))
			    report
			    "Setup ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT ((xlastev=0 ns) OR ((NOW-xlastev) >= Torsu)) then
			    regq_ts <= '1'; 
			    regq_ts <= transport '0' AFTER 1 ns;
			end if;

		else		-- Buried macrocell used as input register

			assert ((xlastev = 0 ns) OR ((NOW - xlastev) >= Tirsu))
			    report
			    "Setup ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT ((xlastev=0 ns) OR ((NOW-xlastev) >= Tirsu)) then
			    regq_ts <= '1'; 
			    regq_ts <= transport '0' AFTER 1 ns;
			end if;

		end if;
		clklastev := NOW;
	    end if;

	    -- hold check
	    if (x'event) then
		if (source = src_ptm) then

			assert ((clklastev=0 ns) OR ((NOW - clklastev) >= Torh))
			    report
			    "Hold ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT((clklastev=0 ns) OR ((NOW-clklastev)>=Torh)) then
			    regq_th <= '1'; 
			    regq_th <= transport '0' AFTER 1 ns;
			end if;

		else		-- Buried macrocell used as input register

			assert ((clklastev = 0 ns) OR ((NOW-clklastev) >= Tirh))
			    report
			    "Hold ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT((clklastev=0 ns) OR ((NOW-clklastev)>=Tirh)) then
			    regq_ts <= '1'; 
			    regq_ts <= transport '0' AFTER 1 ns;
			end if;

		end if;
		xlastev := NOW;
	    end if;
	end if;
    end process;

    -- check clk pulse width
    process (clk)

	variable clklastevhi, clklastevlo : time := 0 ns;

    begin
	-- only if not combinatorial.
	if (oregister /= cmb) then
	    if (clk = '0') then
		assert ((clklastevhi = 0 ns) OR ((NOW - clklastevhi) >= Twh))
		    report
		    "Pulse Width (H) ERROR on CLK: Setting output unknown"
		    severity warning;
		if NOT ((clklastevhi = 0 ns) OR ((NOW-clklastevhi) >= Twh)) then
		    regq_twh <= '1'; 
		    regq_twh <= transport '0' AFTER 1 ns;
		end if;
		clklastevlo := NOW;
	    elsif (clk = '1') then
	       assert ((clklastevlo = 0 ns) OR ((NOW - clklastevlo) >= Twl))
		    report
		    "Pulse Width (L) ERROR on CLK: Setting output unknown"
		    severity warning;
		if NOT ((clklastevlo = 0 ns) OR ((NOW-clklastevlo) >= Twl)) then
		    regq_twl <= '1'; 
		    regq_twl <= transport '0' AFTER 1 ns;
		end if;
		clklastevhi := NOW;
	    end if;
	end if;
    end process;

    -- check RESET minimum pulse width
    process (ar)

	variable arlastev : time := 0 ns;

    begin
	-- only if not combinatorial
	if (oregister /= cmb) then
	    if (ar = '0') then
		assert ((arlastev = 0 ns) OR ((NOW - arlastev) >= Trw))
		    report
		    "Pulse Width ERROR on AR: Setting output to unknown"
		    severity warning;
		if NOT ((arlastev = 0 ns) OR ((NOW - arlastev) >= Trw)) then
		    regq_trw <= '1'; 
		    regq_trw <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	    arlastev := NOW;
	end if;
    end process;

    -- check PRESET minimum pulse width
    process (as)

	variable aslastev : time := 0 ns;

    begin
	-- only if not combinatorial
	if (oregister /= cmb) then
	    if (as = '0') then
		assert ((aslastev = 0 ns) OR ((NOW - aslastev) >= Tpw))
		    report
		    "Pulse Width ERROR on AS: Setting output to unknown"
		    severity warning;
		if NOT ((aslastev = 0 ns) OR ((NOW - aslastev) >= Tpw)) then
		    regq_tpw <= '1'; 
		    regq_tpw <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	    aslastev := NOW;
	end if;
    end process;

    -- check for Asynchronous Reset Recovery violation
    process (dclk, ar)

	variable arlastev, clklastev	: time := 0 ns;

    begin
	-- only if not combinatorial
	if (oregister /= cmb) then
	    if (ar'event) then
		arlastev := NOW;
	    end if;
	    if (ar = '0') then
		if (dclk'event AND (dclk = '1')) then
		    assert ((arlastev = 0 ns) OR ((NOW - arlastev) >= Trr))
			report
			"Recovery ERROR on AR: Setting output to unknown" 
			severity warning;
		    if NOT ((arlastev = 0 ns) OR ((NOW - arlastev) >= Trr)) then
			regq_trr <= '1'; 
			regq_trr <= transport '0' AFTER 1 ns;
		    end if;
		    clklastev := NOW;
		end if;
	    end if;
	end if;
    end process;

    -- check for Asynchronous Preset Recovery violation
    process (dclk, as)

	variable aslastev, clklastev	: time := 0 ns;

    begin
	-- only if not combinatorial
	if (oregister /= cmb) then
	    if (as'event) then
		aslastev := NOW;
	    end if;
	    if (as = '0') then
		if (dclk'event AND (dclk = '1')) then
		    assert ((aslastev = 0 ns) OR ((NOW - aslastev) >= Tpr))
			report
			"Recovery ERROR on AS: Setting output to unknown" 
			severity warning;
		    if NOT ((aslastev = 0 ns) OR ((NOW - aslastev) >= Tpr)) then
			regq_tpr <= '1'; 
			regq_tpr <= transport '0' AFTER 1 ns;
		    end if;
		    clklastev := NOW;
		end if;
	    end if;
	end if;
    end process;

    -- Simulate the register.
    process (dclk, x, as, ar, regq_ts, regq_th, regq_twl, regq_twh, regq_tpw,
   		 regq_tpr, regq_trr, regq_trw)
    begin
	if (source = src_ptm) then
	    if (oregister = cmb) then
		q <= x AFTER Tocomb;
	    elsif ((regq_ts = '1') OR (regq_th  = '1') OR (regq_twh = '1')
		OR (regq_twl = '1') OR (regq_tpw = '1') OR (regq_tpr = '1')
		OR (regq_trr = '1') OR (regq_trw = '1')) then
		q <= 'X' AFTER Tord;
	    elsif (ar = '1') then
		q <= '0' AFTER Trst;
	    elsif (as = '1') then
		q <= '1' AFTER Tpst;
	    elsif (oregister = oltch) then
		if (dclk'event AND (dclk = '1')) then
		    q <= x AFTER Tord;
		elsif (dclk = '1') then	
		    q <= x AFTER Tolat;
		end if;
	    elsif (oregister = dreg) then
		if (dclk'event AND (dclk = '1')) then
		    q <= x AFTER Tord;
		end if;
	    elsif (oregister = treg) then
		if (dclk'event AND (dclk = '1')) then
		    if (x = '1') then
			q <= not q AFTER Tord;
		    end if;
		end if;
	    end if;
	else			-- Buried macrocell used as input register.
	    assert (oregister /= cmb)
		report
		"Illegal configuration: Configured as input combinatorial"
		severity error;
	    if (oregister = cmb) then
		ireg_err <= '1'; 
		ireg_err <= transport '0' AFTER 1 ns;
	    end if;
	    assert (oregister /= treg)
		report
		"Illegal configuration: Configured as input T-register"
		severity error;
	    if (oregister = treg) then
		ireg_err <= '1'; 
		ireg_err <= transport '0' AFTER 1 ns;
	    end if;
	    if ((regq_ts = '1') OR (regq_th  = '1') OR (regq_twh = '1')
		OR (regq_twl = '1') OR (regq_tpw = '1') OR (regq_tpr = '1')
		OR (regq_trr = '1') OR (regq_trw = '1') OR (ireg_err = '1'))then
		q <= 'X' AFTER Tird;
	    elsif (ar = '1') then
		q <= '0' AFTER Trst;
	    elsif (as = '1') then
		q <= '1' AFTER Tpst;
	    elsif (oregister = oltch) then
		if (dclk'event AND (dclk = '1')) then
		    q <= x AFTER Tird;
		elsif (dclk = '1') then	
		    q <= x AFTER Tilat;
		end if;
	    elsif (oregister = dreg) then
		if (dclk'event AND (dclk = '1')) then
		    q <= x AFTER Tird;
		end if;
	    end if;
	end if;
    end process;

    -- Simulate the feedback.
    process (q)
    begin
	if (source = src_ptm) then
	    fb <= q AFTER Tfb;
	else
	    fb <= q;
	end if;
    end process;
end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c37xprod is
    generic (

	tCLK	:	time :=  4000 ps;
	tIRD	:	time :=  1000 ps;
	tICOMB	:	time :=  3000 ps;
	tILAT	:	time :=  5500 ps;
	tIRSU	:	time :=  6000 ps;
	tIRH	:	time :=  2000 ps;
	tSOP	:	time :=  1500 ps;
	tORD	:	time :=  1000 ps;
	tOCOMB	:	time :=  3000 ps;
	tOLAT	:	time :=  5500 ps;
	tORSU	:	time :=  4500 ps;
	tORH	:	time :=  0000 ps;
	tOD	:	time :=  1000 ps;
	tXZ	:	time :=  8500 ps;
	tZX	:	time :=  8500 ps;
	tFB	:	time :=  0000 ps;
	tRST	:	time :=  8500 ps;
	tPST	:	time :=  8500 ps;
	tWL	:	time :=  2500 ps;
	tWH	:	time :=  2500 ps;
	tRW	:	time :=  8000 ps;
	tRR	:	time := 10000 ps;
	tPW	:	time :=  8000 ps;
	tPR	:	time := 10000 ps;
	tVCCO	:	time :=     0 ps );
    port (x	: in	std_logic;
	fb	: out	std_logic);

end c37xprod;

architecture sim of c37xprod is
begin

    process (x)	
    begin
	fb <= x;
    end process;

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c37kinp IS
    generic (
	iregister	: ireg_type	:= ireg;

	Tclk	:	time := 2000 ps;
	Tird	:	time :=  500 ps;
	Ticomb	:	time := 1000 ps;
	Tilat	:	time := 3500 ps;
	Tirsu	:	time := 4000 ps;
	Tirh	:	time := 0000 ps;
	Twl	:	time := 2500 ps;

	Twh	:	time := 2500 ps);

    port (d	: in	std_logic;
	clk	: in	std_logic;
	fb	: out	std_logic);
end c37kinp;

architecture sim of c37kinp is
    signal   	dclk		:	std_logic	:= '0';
    signal   	q1		:	std_logic	:= '0';
    signal	q2		:	std_logic	:= '0';
    signal	q3		:	std_logic	:= '0';
    signal	iregq_tis	: 	std_logic	:= '0';
    signal	iregq_tih	: 	std_logic	:= '0';
    signal	iregq_twh	: 	std_logic	:= '0';
    signal	iregq_twl	: 	std_logic	:= '0';
begin

    dclk <= transport clk AFTER (Tclk);

    -- check for clk setup/hold violations
    process (dclk, d)

	variable dlastev	: time := 0 ns;
	variable clklastev	: time := 0 ns;

    begin
	-- only if not combinatorial.
	if (iregister /= comb) then
	    -- setup check
	    if (dclk'event AND (dclk = '1')) then
		assert ((dlastev = 0 ns) OR ((NOW - dlastev) >= Tirsu))
		    report
		    "Setup ERROR ON D: Setting output to unknown" 
		    severity warning;
		if NOT ((dlastev = 0 ns) OR ((NOW - dlastev) >= Tirsu)) then
		    iregq_tis <= '1'; 
		    iregq_tis <= transport '0' after 1 ns;
		end if;
		clklastev := NOW;
	    end if;

	    -- hold check
	    if (d'event) then
		asserT ((clklastev = 0 ns) OR ((NOW - clklastev) >= Tirh))
		    report
		    "Hold ERROR ON D: Setting output to unknown" 
		    severity warning;
		if NOT ((clklastev = 0 ns) OR ((NOW - clklastev) >= Tirh)) then
		    iregq_tih <= '1'; 
		    iregq_tih <= transport '0' after 1 ns;
		end if;
		dlastev := NOW;
	    end if;
	end if;
    end process;

    -- check clk pulse width
    process (dclk)

	variable clklastevhi,clklastevlo : time := 0 ns;

    begin
	-- only if not combinatorial.
	if (iregister /= comb) then
	    if (dclk = '0') then
		assert ((clklastevhi = 0 ns) OR ((NOW - clklastevhi) >= Twh))
		    report

		    "Pulse Width (H) ERROR on CLK: Setting output to unknown"
		    severity warning;
		if NOT ((clklastevhi = 0 ns) OR ((NOW-clklastevhi) >= Twh)) then
		    iregq_twh <= '1'; 
		    iregq_twh <= transport '0' after 1 ns;
		end if;
		clklastevlo := NOW;
	    elsif (dclk = '1') then
	       assert ((clklastevlo = 0 ns) OR ((NOW - clklastevlo) >= Twl))
		    report
		    "Pulse Width (L) ERROR on CLK: Setting output to unknown"
		    severity warning;
		if NOT ((clklastevlo = 0 ns) OR ((NOW-clklastevlo) >= Twl)) then
		    iregq_twl <= '1'; 
		    iregq_twl <= transport '0' after 1 ns;
		end if;
		clklastevhi := NOW;
	    end if;
	end if;
    end process;

    -- Simulate the Register.
    process (d, dclk, iregq_tis, iregq_tih, iregq_twh, iregq_twl)
    begin
	if ((iregq_tis = '1') OR (iregq_tih = '1') OR (iregq_twh = '1')
	OR (iregq_twl = '1')) then
	    q1 <= 'X' after Tird;
	    q2 <= 'X' after Tird;
	    q3 <= 'X' after Tird;
	elsif (dclk'event AND (dclk = '1')) then
	    q1 <= d after Tird;
	    q2 <= q1 after Tird;
	    q3 <= d after Tird;
	elsif (dclk = '1') then
	    q3 <= d after Tilat;
	end if;
    end process;

    -- Simulate the Mux.
    process (q1, q2, q3, d)
    begin
	if (iregister = comb) then
	    fb <= d after Ticomb;
	elsif (iregister = ireg) then
	    fb <= q1;
	elsif (iregister = dblireg) then	
	    fb <= q2;
	elsif (iregister = iltch) then
	    fb <= q3;
	end if;
    end process;
end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c37km is
    generic (
	bsel	: 	polarity := ninv;

	Ticomb  :       time := 1000 ps; -- Unused in this model.
	Tod     :       time := 2000 ps;
	Txz     :       time := 5500 ps;
	Tzx     :       time := 5500 ps;
	Tsl     :       time := 2000 ps;
	slsel   :       slw_type := fast);

    port (x	: in	std_logic;
	oe	: in	std_logic;
	y	: inout	std_logic;
	fb	: out	std_logic);
end c37km;

architecture sim of c37km is
begin

    -- Simulate the I/O Macro-cell.
    process (oe, x)
    begin
	if (bsel = invt) then
	    if (oe'event) then
		if (oe = '1') then

		    if (slsel = fast) then
			y <= NOT x AFTER Tzx;
		    else
			y <= NOT x AFTER (Tzx + Tsl);
		    end if;

		else

		    if (slsel = fast) then
			y <= 'Z' AFTER Txz;
		    else
			y <= 'Z' AFTER (Txz + Tsl);
		    end if;

		end if;
	    else
		if (oe = '1') then

		    if (slsel = fast) then
			y <= NOT x  AFTER Tod;
		    else
			y <= NOT x  AFTER (Tod + Tsl);
		    end if;

		else
		    y <= 'Z';
		end if;
	    end if;
	elsif (bsel = ninv) then
	    if (oe'event) then
		if (oe = '1') then

		    if (slsel = fast) then
			y <= x AFTER Tzx;
		    else
			y <= x AFTER (Tzx + Tsl);
		    end if;

		else

		    if (slsel = fast) then
			y <= 'Z' AFTER Txz;
		    else
			y <= 'Z' AFTER (Txz + Tsl);
		    end if;

		end if;
	    else
		if (oe = '1') then

		    if (slsel = fast) then
			y <= x AFTER Tod;
		    else
			y <= x AFTER (Tod + Tsl);
		    end if;

		else
		    y <= 'Z';
		end if;
	    end if;
	end if;
    end process;

    -- Simulate the feedback.
    process (y)
    begin

	fb <= y;

    end process;
end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c37kmux is
    generic (

	Tsop	:	time := 4500 ps);

    port (x	: in	std_logic;

	fb	: out	std_logic := '0');

end c37kmux;

architecture sim of c37kmux is
begin

    -- Simulate the PIM.
    process (x)
    begin

	if (x = '1') OR (x = '0') then
	    fb <= x AFTER Tsop;
	else
	    fb <= 'X' AFTER Tsop;
	end if;

    end process;

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c37koreg is
    generic (
	oregister	: oreg_type	:= dreg;
	source		: src_type	:= src_ptm;

	Tclk	:	time := 2000 ps;
	Tird	:	time :=  500 ps;
	Tilat	:	time := 3500 ps;
	Tirsu	:	time := 4000 ps;
	Tirh	:	time :=    0 ps;
	Tord	:	time := 1000 ps;
	Tocomb	:	time :=    0 ps;
	Tolat	:	time := 2500 ps;
	Torsu	:	time := 1000 ps;
	Torh	:	time := 3500 ps;
	Tfb	:	time :=    0 ps;
	Trst	:	time := 4500 ps;
	Tpst	:	time := 4500 ps;
	Twl	:	time := 2500 ps;
	Twh	:	time := 2500 ps;
	Trw	:	time := 8000 ps;
	Trr	:	time :=10000 ps;
	Tpw	:	time := 8000 ps;
	Tpr	:	time :=10000 ps;
	Tirsupt	:	time := 3500 ps;
	Tirhpt	:	time := 1000 ps;
	Torsupt	:	time := 2500 ps;
	Torhpt	:	time := 2500 ps;

	cksel	: 	clk_type := nopt);

    port (as	: in	std_logic;
	x	: in	std_logic;
	clk	: in	std_logic;
	ar	: in	std_logic;
	fb	: out	std_logic;
	q	: inout	std_logic := '0');

end c37koreg;

architecture sim of c37koreg is

    signal	regq_ts		: std_logic	:= '0';
    signal	regq_th		: std_logic	:= '0';
    signal	regq_twh	: std_logic	:= '0';
    signal	regq_twl	: std_logic	:= '0';
    signal	regq_tpw	: std_logic	:= '0';
    signal	regq_tpr	: std_logic	:= '0';
    signal	regq_trr	: std_logic	:= '0';
    signal	regq_trw	: std_logic	:= '0';
    signal	ireg_err	: std_logic	:= '0';
    signal	dclk		: std_logic;

begin

    -- add the delay for product term clock if necessary
    process (clk)
    begin
	if (cksel = ckpt) then
	    dclk <= clk;
	else
	    dclk <= transport clk AFTER (Tclk);
	end if;
    end process;

    -- check for clk setup/hold violations
    process (dclk, x)
	variable xlastev, clklastev	: time := 0 ns;
    begin
	-- only if not combinatorial
	if (oregister /= cmb) then
	    -- setup check
	    if (dclk'event AND (dclk = '1')) then
		if (source = src_ptm) then

		    if (cksel = ckpt) then
			assert ((xlastev = 0 ns) OR ((NOW-xlastev) >= Torsupt))
			    report
			    "Setup ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT ((xlastev=0 ns) OR ((NOW-xlastev)>=Torsupt)) then
			    regq_ts <= '1'; 
			    regq_ts <= transport '0' AFTER 1 ns;
			end if;
		    else

			assert ((xlastev = 0 ns) OR ((NOW - xlastev) >= Torsu))
			    report
			    "Setup ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT ((xlastev=0 ns) OR ((NOW-xlastev) >= Torsu)) then
			    regq_ts <= '1'; 
			    regq_ts <= transport '0' AFTER 1 ns;
			end if;

		    end if;

		else		-- Buried macrocell used as input register

		    if (cksel = ckpt) then
			assert ((xlastev = 0 ns) OR ((NOW-xlastev) >= Tirsupt))
			    report
			    "Setup ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT ((xlastev=0 ns) OR ((NOW-xlastev)>=Tirsupt)) then
			    regq_ts <= '1'; 
			    regq_ts <= transport '0' AFTER 1 ns;
			end if;
		    else

			assert ((xlastev = 0 ns) OR ((NOW - xlastev) >= Tirsu))
			    report
			    "Setup ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT ((xlastev=0 ns) OR ((NOW-xlastev) >= Tirsu)) then
			    regq_ts <= '1'; 
			    regq_ts <= transport '0' AFTER 1 ns;
			end if;

		    end if;

		end if;
		clklastev := NOW;
	    end if;

	    -- hold check
	    if (x'event) then
		if (source = src_ptm) then

		    if (cksel = ckpt) then
			assert ((clklastev=0 ns) OR ((NOW-clklastev) >= Torhpt))
			    report
			    "Hold ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT((clklastev=0 ns)OR((NOW-clklastev)>=Torhpt)) then
			    regq_ts <= '1'; 
			    regq_ts <= transport '0' AFTER 1 ns;
			end if;
		    else

			assert ((clklastev=0 ns) OR ((NOW - clklastev) >= Torh))
			    report
			    "Hold ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT((clklastev=0 ns) OR ((NOW-clklastev)>=Torh)) then
			    regq_th <= '1'; 
			    regq_th <= transport '0' AFTER 1 ns;
			end if;

		    end if;

		else		-- Buried macrocell used as input register

		    if (cksel = ckpt) then
			assert ((clklastev=0 ns) OR ((NOW-clklastev) >= Tirhpt))
			    report
			    "Hold ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT((clklastev=0 ns)OR((NOW-clklastev)>=Tirhpt)) then
			    regq_ts <= '1'; 
			    regq_ts <= transport '0' AFTER 1 ns;
			end if;
		    else

			assert ((clklastev = 0 ns) OR ((NOW-clklastev) >= Tirh))
			    report
			    "Hold ERROR ON X: Setting output to unknown" 
			    severity warning;
			if NOT((clklastev=0 ns) OR ((NOW-clklastev)>=Tirh)) then
			    regq_ts <= '1'; 
			    regq_ts <= transport '0' AFTER 1 ns;
			end if;

		    end if;

		end if;
		xlastev := NOW;
	    end if;
	end if;
    end process;

    -- check clk pulse width
    process (clk)

	variable clklastevhi, clklastevlo : time := 0 ns;

    begin
	-- only if not combinatorial.
	if (oregister /= cmb) then
	    if (clk = '0') then
		assert ((clklastevhi = 0 ns) OR ((NOW - clklastevhi) >= Twh))
		    report
		    "Pulse Width (H) ERROR on CLK: Setting output unknown"
		    severity warning;
		if NOT ((clklastevhi = 0 ns) OR ((NOW-clklastevhi) >= Twh)) then
		    regq_twh <= '1'; 
		    regq_twh <= transport '0' AFTER 1 ns;
		end if;
		clklastevlo := NOW;
	    elsif (clk = '1') then
	       assert ((clklastevlo = 0 ns) OR ((NOW - clklastevlo) >= Twl))
		    report
		    "Pulse Width (L) ERROR on CLK: Setting output unknown"
		    severity warning;
		if NOT ((clklastevlo = 0 ns) OR ((NOW-clklastevlo) >= Twl)) then
		    regq_twl <= '1'; 
		    regq_twl <= transport '0' AFTER 1 ns;
		end if;
		clklastevhi := NOW;
	    end if;
	end if;
    end process;

    -- check RESET minimum pulse width
    process (ar)

	variable arlastev : time := 0 ns;

    begin
	-- only if not combinatorial
	if (oregister /= cmb) then
	    if (ar = '0') then
		assert ((arlastev = 0 ns) OR ((NOW - arlastev) >= Trw))
		    report
		    "Pulse Width ERROR on AR: Setting output to unknown"
		    severity warning;
		if NOT ((arlastev = 0 ns) OR ((NOW - arlastev) >= Trw)) then
		    regq_trw <= '1'; 
		    regq_trw <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	    arlastev := NOW;
	end if;
    end process;

    -- check PRESET minimum pulse width
    process (as)

	variable aslastev : time := 0 ns;

    begin
	-- only if not combinatorial
	if (oregister /= cmb) then
	    if (as = '0') then
		assert ((aslastev = 0 ns) OR ((NOW - aslastev) >= Tpw))
		    report
		    "Pulse Width ERROR on AS: Setting output to unknown"
		    severity warning;
		if NOT ((aslastev = 0 ns) OR ((NOW - aslastev) >= Tpw)) then
		    regq_tpw <= '1'; 
		    regq_tpw <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	    aslastev := NOW;
	end if;
    end process;

    -- check for Asynchronous Reset Recovery violation
    process (dclk, ar)

	variable arlastev, clklastev	: time := 0 ns;

    begin
	-- only if not combinatorial
	if (oregister /= cmb) then
	    if (ar'event) then
		arlastev := NOW;
	    end if;
	    if (ar = '0') then
		if (dclk'event AND (dclk = '1')) then
		    assert ((arlastev = 0 ns) OR ((NOW - arlastev) >= Trr))
			report
			"Recovery ERROR on AR: Setting output to unknown" 
			severity warning;
		    if NOT ((arlastev = 0 ns) OR ((NOW - arlastev) >= Trr)) then
			regq_trr <= '1'; 
			regq_trr <= transport '0' AFTER 1 ns;
		    end if;
		    clklastev := NOW;
		end if;
	    end if;
	end if;
    end process;

    -- check for Asynchronous Preset Recovery violation
    process (dclk, as)

	variable aslastev, clklastev	: time := 0 ns;

    begin
	-- only if not combinatorial
	if (oregister /= cmb) then
	    if (as'event) then
		aslastev := NOW;
	    end if;
	    if (as = '0') then
		if (dclk'event AND (dclk = '1')) then
		    assert ((aslastev = 0 ns) OR ((NOW - aslastev) >= Tpr))
			report
			"Recovery ERROR on AS: Setting output to unknown" 
			severity warning;
		    if NOT ((aslastev = 0 ns) OR ((NOW - aslastev) >= Tpr)) then
			regq_tpr <= '1'; 
			regq_tpr <= transport '0' AFTER 1 ns;
		    end if;
		    clklastev := NOW;
		end if;
	    end if;
	end if;
    end process;

    -- Simulate the register.
    process (dclk, x, as, ar, regq_ts, regq_th, regq_twl, regq_twh, regq_tpw,
   		 regq_tpr, regq_trr, regq_trw)
    begin
	if (source = src_ptm) then
	    if (oregister = cmb) then
		q <= x AFTER Tocomb;
	    elsif ((regq_ts = '1') OR (regq_th  = '1') OR (regq_twh = '1')
		OR (regq_twl = '1') OR (regq_tpw = '1') OR (regq_tpr = '1')
		OR (regq_trr = '1') OR (regq_trw = '1')) then
		q <= 'X' AFTER Tord;
	    elsif (ar = '1') then
		q <= '0' AFTER Trst;
	    elsif (as = '1') then
		q <= '1' AFTER Tpst;
	    elsif (oregister = oltch) then
		if (dclk'event AND (dclk = '1')) then
		    q <= x AFTER Tord;
		elsif (dclk = '1') then	
		    q <= x AFTER Tolat;
		end if;
	    elsif (oregister = dreg) then
		if (dclk'event AND (dclk = '1')) then
		    q <= x AFTER Tord;
		end if;
	    elsif (oregister = treg) then
		if (dclk'event AND (dclk = '1')) then
		    if (x = '1') then
			q <= not q AFTER Tord;
		    end if;
		end if;
	    end if;
	else			-- Buried macrocell used as input register.
	    assert (oregister /= cmb)
		report
		"Illegal configuration: Configured as input combinatorial"
		severity error;
	    if (oregister = cmb) then
		ireg_err <= '1'; 
		ireg_err <= transport '0' AFTER 1 ns;
	    end if;
	    assert (oregister /= treg)
		report
		"Illegal configuration: Configured as input T-register"
		severity error;
	    if (oregister = treg) then
		ireg_err <= '1'; 
		ireg_err <= transport '0' AFTER 1 ns;
	    end if;
	    if ((regq_ts = '1') OR (regq_th  = '1') OR (regq_twh = '1')
		OR (regq_twl = '1') OR (regq_tpw = '1') OR (regq_tpr = '1')
		OR (regq_trr = '1') OR (regq_trw = '1') OR (ireg_err = '1'))then
		q <= 'X' AFTER Tird;
	    elsif (ar = '1') then
		q <= '0' AFTER Trst;
	    elsif (as = '1') then
		q <= '1' AFTER Tpst;
	    elsif (oregister = oltch) then
		if (dclk'event AND (dclk = '1')) then
		    q <= x AFTER Tird;
		elsif (dclk = '1') then	
		    q <= x AFTER Tilat;
		end if;
	    elsif (oregister = dreg) then
		if (dclk'event AND (dclk = '1')) then
		    q <= x AFTER Tird;
		end if;
	    end if;
	end if;
    end process;

    -- Simulate the feedback.
    process (q)
    begin
	if (source = src_ptm) then
	    fb <= q AFTER Tfb;
	else
	    fb <= q;
	end if;
    end process;
end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c39kcf is
    generic (
	cfgbits : Bit_Vector(45 downto 0);
	memdata	: chmem;
	xcmfClockWthCy		: time;		-- checked parameters
	xcmfClockWthHi		: time;
	xcmfClockWthLo		: time;
	xcmfDinAtClkWrSetup	: time;
	xcmfDinAtClkWrHold	: time;
	xcmfEnxAtClockSetup	: time;
	xcmfEnxAtClockHold	: time;
	xcmfEfbInAtClkRdSetup	: time;
	xcmfEfbInAtClkRdHold	: time;
	xcmfHfbInAtClkRdSetup	: time;
	xcmfHfbInAtClkRdHold	: time;
	xcmfEfbInAtClkWrSetup	: time;
	xcmfEfbInAtClkWrHold	: time;
	xcmfHfbInAtClkWrSetup	: time;
	xcmfHfbInAtClkWrHold	: time;
	xcmfMrbWthLo		: time;
	xcmfMrbRcr		: time;
	xcmfRdWrSkewEfb		: time;
	xcmfRdWrSkewHfb		: time;
	xcmfRdWrSkewPafeb	: time;
	xcmfDoutRegReWthHi	: time;
	xcmfDoutRegReRcr	: time;

	xcmfClkWr2FlagOut	: time;		-- applied parameters
	xcmfClkRd2FlagOut	: time;
	xcmfMrb2Output		: time;
	xcmfClock2Dout		: time;
	xcmfReset2Dout		: time);
    port (
	din		: in	std_logic_vector(7 downto 0);
	dout		: inout	std_logic_vector(7 downto 0);
	enr		: in	std_logic;            
	enw		: in	std_logic;            
	ckr		: in	std_logic;
	ckw		: in	std_logic;
	mrb		: in	std_logic := '1';            
	efb		: inout	std_logic;
	hfb		: inout	std_logic;
	pafeb		: out	std_logic);
end c39kcf;

architecture sim of c39kcf is

    signal full		: std_logic := '1';
    signal empt		: std_logic := '0';
    signal half		: std_logic := '0';
    signal pafl		: std_logic := '1';
    signal paem		: std_logic := '0';

    -- Signals for use with negative setup and hold checks
    signal d_din	: std_logic_vector(7 downto 0);
    signal d_dckw	: std_logic;
    signal d_enr	: std_logic;
    signal e_dckr	: std_logic;
    signal d_enw	: std_logic;
    signal e_dckw	: std_logic;
    signal r_efb	: std_logic;
    signal f_dckr	: std_logic;
    signal r_hfb	: std_logic;
    signal h_dckr	: std_logic;
    signal w_efb	: std_logic;
    signal f_dckw	: std_logic;
    signal w_hfb	: std_logic;
    signal h_dckw	: std_logic;

    -- Constants for use with negative setup and hold checks
    constant DataSetup	: time := timeAdjust(xcmfDinAtClkWrSetup);
    constant DataHold	: time := timeAdjust(xcmfDinAtClkWrHold);
    constant EnSetup	: time := timeAdjust(xcmfEnxAtClockSetup);
    constant EnHold	: time := timeAdjust(xcmfEnxAtClockHold);
    constant fflgSetupR	: time := timeAdjust(xcmfEfbInAtClkRdSetup);
    constant hflgSetupR	: time := timeAdjust(xcmfHfbInAtClkRdSetup);
    constant fflgHoldR	: time := timeAdjust(xcmfEfbInAtClkRdHold);
    constant hflgHoldR	: time := timeAdjust(xcmfHfbInAtClkRdHold);
    constant fflgSetupW	: time := timeAdjust(xcmfEfbInAtClkWrSetup);
    constant hflgSetupW	: time := timeAdjust(xcmfHfbInAtClkWrSetup);
    constant fflgHoldW	: time := timeAdjust(xcmfEfbInAtClkWrHold);
    constant hflgHoldW	: time := timeAdjust(xcmfHfbInAtClkWrHold);

    constant unk	: string := " Setting output unknown.";

    signal ckrerr	: std_logic;
    constant read_high		: string :=
    "Read clock high width violation:"	& unk;
    constant read_low		: string :=
    "Read clock low width violation:"	& unk;
    constant read_cycle		: string :=
    "Read clock cycle width violation:"	& unk;

    signal ckwerr	: std_logic;
    constant write_high		: string :=
    "Write clock high width violation:"	& unk;
    constant write_low		: string :=
    "Write clock low width violation:"	& unk;
    constant write_cycle	: string :=
    "Write clock cycle width violation:"& unk;

    signal wdserr	: std_logic;
    constant writedata_setup	: string :=
    "Write data setup violation:"	& unk;

    signal wdherr	: std_logic;
    constant writedata_hold	: string :=
    "Write data hold violation:"	& unk;

    signal enrserr	: std_logic;
    constant readen_setup	: string :=
    "Read enable setup violation:"	& unk;

    signal enrherr	: std_logic;
    constant readen_hold	: string :=
    "Read enable hold violation:"	& unk;

    signal enwserr	: std_logic;
    constant writeen_setup	: string :=
    "Write enable setup violation:"	& unk;

    signal enwherr	: std_logic;
    constant writeen_hold	: string :=
    "Write enable hold violation:"	& unk;

    signal rrcverr	: std_logic;
    constant readreset_rcvry	: string :=
    "Read reset recovery violation:"	& unk;

    signal wrcverr	: std_logic;
    constant writereset_rcvry	: string :=
    "Write reset recovery violation:"	& unk;

    signal mrberr	: std_logic;
    constant reset_width	: string :=
    "Reset width violation:"		& unk;

    constant write2read_skew1	: string :=
    "Write to read skew insufficient for current cycle empty/full update.";
    constant write2read_skew2	: string :=
    "Write to read skew insufficient for current cycle almost empty update.";
    constant read2write_skew2	: string :=
    "Read to write skew insufficient for current cycle half full update.";
    constant read2write_skew3	: string :=
    "Read to write skew insufficient for current cycle almost full update.";

    signal refserr	: std_logic;
    constant refflag_setup	: string :=
    "Read clock to E/F flag setup violation.";

    signal refherr	: std_logic;
    constant refflag_hold	: string :=
    "E/F flag to read clock hold violation.";

    signal rhfserr	: std_logic;
    constant rhfflag_setup	: string :=
    "Read clock to H/F flag setup violation.";

    signal rhfherr	: std_logic;
    constant rhfflag_hold	: string :=
    "H/F flag to read clock hold violation.";

    signal wefserr	: std_logic;
    constant wefflag_setup	: string :=
    "Write clock to E/F flag setup violation.";

    signal wefherr	: std_logic;
    constant wefflag_hold	: string :=
    "E/F flag to write clock hold violation.";

    signal whfserr	: std_logic;
    constant whfflag_setup	: string :=
    "Write clock to H/F flag setup violation.";

    signal whfherr	: std_logic;
    constant whfflag_hold	: string :=
    "H/F flag to write clock hold violation.";

begin

    -- check read clock cycle, high and low times.
    process (ckr)
        variable clkhi, clklo : time := 0 ns;
    begin
	if (ckr = '0') then
	    if ((clkhi /= 0 ns) AND ((NOW-clkhi) < xcmfClockWthHi)) then
		assert (false)
		    report read_high
		    severity warning;
		ckrerr <= '1';
		ckrerr <= transport '0' AFTER 1 ns;
	    end if;
	    clklo := NOW;
	elsif (ckr = '1') then
	    if ((clklo /= 0 ns) AND ((NOW-clklo) < xcmfClockWthLo)) then
	       assert (false)
		    report read_low
		    severity warning;
		ckrerr <= '1';
		ckrerr <= transport '0' AFTER 1 ns;
	    end if;
	    if ((clkhi /= 0 ns) AND ((NOW-clkhi) < xcmfClockWthCy)) then
		assert (false)
		    report read_cycle
		    severity warning;
		ckrerr <= '1';
		ckrerr <= transport '0' AFTER 1 ns;
	    end if;
	    clkhi := NOW;
	end if;
    end process;

    -- check write clock cycle, high and low times.
    process (ckw)
        variable clkhi, clklo : time := 0 ns;
    begin
	if (ckw = '0') then
	    if ((clkhi /= 0 ns) AND ((NOW-clkhi) < xcmfClockWthHi)) then
		assert (false)
		    report write_high
		    severity warning;
		ckwerr <= '1';
		ckwerr <= transport '0' AFTER 1 ns;
	    end if;
	    clklo := NOW;
	elsif (ckw = '1') then
	    if ((clklo /= 0 ns) AND ((NOW-clklo) < xcmfClockWthLo)) then
	       assert (false)
		    report write_low
		    severity warning;
		ckwerr <= '1';
		ckwerr <= transport '0' AFTER 1 ns;
	    end if;
	    if ((clkhi /= 0 ns) AND ((NOW-clkhi) < xcmfClockWthCy)) then
		assert (false)
		    report write_cycle
		    severity warning;
		ckwerr <= '1';
		ckwerr <= transport '0' AFTER 1 ns;
	    end if;
	    clkhi := NOW;
	end if;
    end process;

    -- check write data setup
    d_dckw <= ckw after DataSetup;
    process (din, d_dckw)
    	variable din_ev : time := 0 ns;
    begin
	if (rising_edge(d_dckw)) then
	    if ((din_ev /= 0 ns) AND
		    ((NOW-din_ev) < xcmfDinAtClkWrSetup + DataSetup)) then
		assert (false)
		    report writedata_setup
		    severity warning;
		wdserr <= '1';
		wdserr <= transport '0' AFTER 1 ns;
	    end if;
	elsif (din'event) then
	    din_ev := NOW;
	end if;
    end process;

    -- check write data hold
    d_din <= din after DataHold;
    process (d_din, ckw)
    	variable clk_ev : time := 0 ns;
    begin
	if (rising_edge(ckw)) then
	    clk_ev := NOW;
	elsif (d_din'event) then
	    if ((clk_ev /= 0 ns) AND
		    ((NOW-clk_ev) < xcmfDinAtClkWrHold + DataHold)) then
		assert (false)
		    report writedata_hold
		    severity warning;
		wdherr <= '1';
		wdherr <= transport '0' AFTER 1 ns;
	    end if;
	end if;
    end process;

    -- check read enable setup
    e_dckr <= ckr after EnSetup;
    process (enr, e_dckr)
    	variable enr_ev : time := 0 ns;
    begin
	if (rising_edge(e_dckr)) then
	    if ((enr_ev /= 0 ns) AND
		    ((NOW-enr_ev) < xcmfEnxAtClockSetup + EnSetup)) then
		assert (false)
		    report readen_setup
		    severity warning;
		enrserr <= '1';
		enrserr <= transport '0' AFTER 1 ns;
	    end if;
	elsif (enr'event) then
	    enr_ev := NOW;
	end if;
    end process;

    -- check read enable hold
    d_enr <= enr after EnHold;
    process (d_enr, ckr)
    	variable clk_ev : time := 0 ns;
    begin
	if (rising_edge(ckr)) then
	    clk_ev := NOW;
	elsif (d_enr'event) then
	    if ((clk_ev /= 0 ns) AND
		    ((NOW-clk_ev) < xcmfEnxAtClockHold + EnHold)) then
		assert (false)
		    report readen_hold
		    severity warning;
		enrherr <= '1';
		enrherr <= transport '0' AFTER 1 ns;
	    end if;
	end if;
    end process;

    -- check write enable setup
    e_dckw <= ckw after EnSetup;
    process (enw, e_dckw)
    	variable enw_ev : time := 0 ns;
    begin
	if (rising_edge(e_dckw)) then
	    if ((enw_ev /= 0 ns) AND
		    ((NOW-enw_ev) < xcmfEnxAtClockSetup + EnSetup)) then
		assert (false)
		    report writeen_setup
		    severity warning;
		enwserr <= '1';
		enwserr <= transport '0' AFTER 1 ns;
	    end if;
	elsif (enw'event) then
	    enw_ev := NOW;
	end if;
    end process;

    -- check write enable hold
    d_enw <= enw after EnHold;
    process (d_enw, ckw)
    	variable clk_ev : time := 0 ns;
    begin
	if (rising_edge(ckw)) then
	    clk_ev := NOW;
	elsif (d_enw'event) then
	    if ((clk_ev /= 0 ns) AND
		    ((NOW-clk_ev) < xcmfEnxAtClockHold + EnHold)) then
		assert (false)
		    report writeen_hold
		    severity warning;
		enwherr <= '1';
		enwherr <= transport '0' AFTER 1 ns;
	    end if;
	end if;
    end process;

    -- check reset width
    process (mrb)
        variable mrblo : time := 0 ns;
    begin
	if (mrb = '0') then
	    mrblo := NOW;
	else
	    if ((mrblo /= 0 ns) AND ((NOW-mrblo) < xcmfMrbWthLo)) then
		assert (false)
		    report reset_width
		    severity warning;
		mrberr <= '1';
		mrberr <= transport '0' AFTER 1 ns;
	    end if;
	end if;
    end process;

    -- check read reset recovery
    process (mrb, ckr)
        variable mrblastev, ckrlastev    : time := 0 ns;
    begin
	if (mrb'event) then
	    mrblastev := NOW;
	end if;
	if ((mrb = '1') AND rising_edge(ckr)) then
	    if ((mrblastev /= 0 ns) AND ((NOW-mrblastev) < xcmfMrbRcr)) then
		assert (false)
		    report readreset_rcvry
		    severity warning;
		rrcverr <= '1';
		rrcverr <= transport '0' AFTER 1 ns;
	    end if;
	    ckrlastev := NOW;
	end if;
    end process;

    -- check write reset recovery
    process (mrb, ckw)
        variable mrblastev, ckwlastev    : time := 0 ns;
    begin
	if (mrb'event) then
	    mrblastev := NOW;
	end if;
	if ((mrb = '1') AND rising_edge(ckw)) then
	    if ((mrblastev /= 0 ns) AND ((NOW-mrblastev) < xcmfMrbRcr)) then
		assert (false)
		    report writereset_rcvry
		    severity warning;
		wrcverr <= '1';
		wrcverr <= transport '0' AFTER 1 ns;
	    end if;
	    ckwlastev := NOW;
	end if;
    end process;

    -- check E/F flag to read clock setup
    f_dckr <= ckr after fflgSetupR;
    process (f_dckr, efb)
	variable efb_ev : time := 0 ns;
    begin
	if (cfgbits(1 downto 0) = "10") then
	    if (rising_edge(f_dckr)) then
		if ((efb_ev /= 0 ns) AND
			((NOW-efb_ev) < xcmfEfbInAtClkRdSetup + fflgSetupR))then
		    assert (false)
			report refflag_setup
			severity warning;
		    refserr <= '1';
		    refserr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (efb'event) then
		efb_ev := NOW;
	    end if;
	end if;
    end process;

    -- check H/F flag to read clock setup
    h_dckr <= ckr after hflgSetupR;
    process (h_dckr, hfb)
	variable hfb_ev : time := 0 ns;
    begin
	if (cfgbits(1 downto 0) = "10") then
	    if (rising_edge(h_dckr)) then
		if ((hfb_ev /= 0 ns) AND
			((NOW-hfb_ev) < xcmfHfbInAtClkRdSetup + hflgSetupR))then
		    assert (false)
			report rhfflag_setup
			severity warning;
		    rhfserr <= '1';
		    rhfserr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (hfb'event) then
		hfb_ev := NOW;
	    end if;
	end if;
    end process;

    -- check E/F flag to read clock hold
    r_efb <= efb after fflgHoldR;
    process (ckr, r_efb)
	variable clk_ev : time := 0 ns;
    begin
	if (cfgbits(1 downto 0) = "10") then
	    if (rising_edge(ckr)) then
		clk_ev := NOW;
	    elsif (r_efb'event) then
		if ((clk_ev /= 0 ns) AND
			((NOW-clk_ev) < xcmfEfbInAtClkRdHold + fflgHoldR)) then
		    assert (false)
			report refflag_hold
			severity warning;
		    refherr <= '1';
		    refherr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check H/F flag to read clock hold
    r_hfb <= hfb after hflgHoldR;
    process (ckr, r_hfb)
	variable clk_ev : time := 0 ns;
    begin
	if (cfgbits(1 downto 0) = "10") then
	    if (rising_edge(ckr)) then
		clk_ev := NOW;
	    elsif (r_hfb'event) then
		if ((clk_ev /= 0 ns) AND
			((NOW-clk_ev) < xcmfHfbInAtClkRdHold + hflgHoldR)) then
		    assert (false)
			report rhfflag_hold
			severity warning;
		    rhfherr <= '1';
		    rhfherr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check E/F flag to write clock setup
    f_dckw <= ckw after fflgSetupW;
    process (f_dckw, efb)
	variable efb_ev : time := 0 ns;
    begin
	if (cfgbits(1 downto 0) = "10") then
	    if (rising_edge(f_dckw)) then
		if ((efb_ev /= 0 ns) AND
			((NOW-efb_ev) < xcmfEfbInAtClkWrSetup + fflgSetupW))then
		    assert (false)
			report wefflag_setup
			severity warning;
		    wefserr <= '1';
		    wefserr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (efb'event) then
		efb_ev := NOW;
	    end if;
	end if;
    end process;

    -- check H/F flag to write clock setup
    h_dckw <= ckw after hflgSetupW;
    process (h_dckw, hfb)
	variable hfb_ev : time := 0 ns;
    begin
	if (cfgbits(1 downto 0) = "10") then
	    if (rising_edge(h_dckw)) then
		if ((hfb_ev /= 0 ns) AND
			((NOW-hfb_ev) < xcmfHfbInAtClkWrSetup + hflgSetupW))then
		    assert (false)
			report whfflag_setup
			severity warning;
		    whfserr <= '1';
		    whfserr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (hfb'event) then
		hfb_ev := NOW;
	    end if;
	end if;
    end process;

    -- check E/F flag to write clock hold
    w_efb <= efb after fflgHoldW;
    process (ckw, w_efb)
	variable clk_ev : time := 0 ns;
    begin
	if (cfgbits(1 downto 0) = "10") then
	    if (rising_edge(ckw)) then
		clk_ev := NOW;
	    elsif (w_efb'event) then
		if ((clk_ev /= 0 ns) AND
			((NOW-clk_ev) < xcmfEfbInAtClkWrHold + fflgHoldW)) then
		    assert (false)
			report wefflag_hold
			severity warning;
		    wefherr <= '1';
		    wefherr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;
    
    -- check H/F flag to write clock hold
    w_hfb <= hfb after hflgHoldW;
    process (ckw, w_hfb)
	variable clk_ev : time := 0 ns;
    begin
	if (cfgbits(1 downto 0) = "10") then
	    if (rising_edge(ckw)) then
		clk_ev := NOW;
	    elsif (hfb'event) then
		if ((clk_ev /= 0 ns) AND
			((NOW-clk_ev) < xcmfHfbInAtClkWrHold + hflgHoldW)) then
		    assert (false)
			report whfflag_hold
			severity warning;
		    whfherr <= '1';
		    whfherr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check the skews between read and write for setting the flags
    process (ckr, ckw)
    	variable ckr_re	: time := 0 ns;
    	variable ckw_re	: time := 0 ns;
    begin
	if (cfgbits(1 downto 0) = "01") then
	    if (rising_edge(ckr)) then
		ckr_re := NOW;
	    end if;
	    if (rising_edge(ckw)) then
		ckw_re := NOW;
	    end if;

	    if (rising_edge(ckr) AND (mrb = '1')) then
		-- empty
		if (((NOW-ckw_re) < xcmfRdWrSkewEfb) AND (efb = '0')) then
		    assert (false)
			report write2read_skew1
			severity note;
		end if;
		-- programmable empty
		if (((NOW-ckw_re) < xcmfRdWrSkewPafeb) AND (paem = '0')) then
		    assert (false)
			report write2read_skew2
			severity note;
		end if;
	    end if;

	    if (rising_edge(ckw) AND (mrb = '1')) then
		-- full
		if (((NOW-ckr_re) < xcmfRdWrSkewHfb) AND (hfb = '0')) then
		    assert (false)
			report read2write_skew2
			severity note;
		end if;
		-- programmable full
		if (((NOW-ckr_re) < xcmfRdWrSkewPafeb) AND (pafl = '0')) then
		    assert (false)
			report read2write_skew3
			severity note;
		end if;
	    end if;
	end if;
    end process;

    -- simulate the fifo operations
    process (mrb, ckw, ckr, 
		ckwerr, enwserr, enwherr, mrberr, wrcverr,
		ckrerr, wdserr, wdherr, enrserr, enrherr, rrcverr)
	variable dtmp	: std_logic_vector(7 downto 0);
	variable dierr	: std_logic_vector(7 downto 0);
	variable doerr	: std_logic_vector(7 downto 0);
	variable wadd 	: natural := 0;
	variable radd	: natural := 0;
	variable idx	: natural := 0;
	variable top	: natural := 0;
	variable wadr	: natural;
	variable radr	: natural;
	variable mem	: chmem := memdata;
    begin

	case cfgbits(3 downto 2) is
	when "00" =>
	    top  := 512;
	when "01" =>
	    top  := 1024;
	    wadr := (wadd mod 2)*4;
	    radr := (radd mod 2)*4;
	when "10" =>
	    top  := 2048;
	    wadr := (wadd mod 4)*2;
	    radr := (radd mod 4)*2;
	when "11" =>
	    top  := 4096;
	    wadr := (wadd mod 8);
	    radr := (radd mod 8);
	end case;

	-- Condition input with errors
	if ((ckwerr OR enwserr OR enwherr OR mrberr OR wrcverr
					    OR wdserr OR wdherr) = '1') then
	    dierr := (others => 'X');
	else
	    dierr := din;
	end if;

	if (mrb = '0') then
	    idx  := 0;
	    wadd := 0;
	    radd := 0;
	    doerr := (others => '0');
	else
	    case cfgbits(1 downto 0) is
	    when "01" =>
		if (rising_edge(ckw)) then
		    if ((idx < top) AND (enw = '1') AND (full /= '0')) then
			idx := idx+1;
			case cfgbits(3 downto 2) is
			when "00" =>
			    mem(wadd) := dierr;
			when "01" =>
			    mem(wadd/2)(wadr+3 downto wadr):= dierr(3 downto 0);
			when "10" =>
			    mem(wadd/4)(wadr+1 downto wadr):= dierr(1 downto 0);
			when "11" =>
			    mem(wadd/8)(wadr) := dierr(0);
			end case;
			wadd := wadd + 1;
			if (wadd >= top) then
			    wadd := 0;
			end if;
		    end if;
		end if;
		if (rising_edge(ckr)) then
		    if ((idx > 0) AND (enr = '1') AND (empt /= '0')) then
			idx := idx-1;
			doerr := (others => '0');
			case cfgbits(3 downto 2) is
			when "00" =>
			    doerr := mem(radd);
			when "01" =>
			    doerr(3 downto 0):= mem(radd/2)(radr+3 downto radr);
			when "10" =>
			    doerr(1 downto 0):= mem(radd/4)(radr+1 downto radr);
			when "11" =>
			    doerr(0) := mem(radd/8)(radr);
			end case;
			radd := radd + 1;
			if (radd >= top) then
			    radd := 0;
			end if;
		    end if;
		end if;
	    when "10" =>
		if (rising_edge(ckw)) then
		    if (NOT((efb = '0') AND (hfb = '0')) AND (enw = '1')) then
			case cfgbits(3 downto 2) is
			when "00" =>
			    mem(wadd) := dierr;
			when "01" =>
			    mem(wadd/2)(wadr+3 downto wadr):= dierr(3 downto 0);
			when "10" =>
			    mem(wadd/4)(wadr+1 downto wadr):= dierr(1 downto 0);
			when "11" =>
			    mem(wadd/8)(wadr) := dierr(0);
			end case;
			wadd := wadd + 1;
			if (wadd >= top) then
			    wadd := 0;
			end if;
		    end if;
		end if;
		if (rising_edge(ckr)) then
		    if (NOT((efb = '0') AND (hfb = '1')) AND (enr = '1')) then
			doerr := (others => '0');
			case cfgbits(3 downto 2) is
			when "00" =>
			    doerr := mem(radd);
			when "01" =>
			    doerr(3 downto 0):= mem(radd/2)(radr+3 downto radr);
			when "10" =>
			    doerr(1 downto 0):= mem(radd/4)(radr+1 downto radr);
			when "11" =>
			    doerr(0) := mem(radd/8)(radr);
			end case;
			radd := radd + 1;
			if (radd >= top) then
			    radd := 0;
			end if;
		    end if;
		end if;
	    when others =>
	    	null;
	    end case;
	end if;

	-- Condition output with errors and the reset
	if ((ckrerr OR enrserr OR enrherr OR mrberr OR rrcverr) = '1') then
	    dtmp := (others => 'X');
	else
	    dtmp := doerr;
	end if;

	if (mrb'event) then
	    dout <= dtmp after xcmfReset2Dout;
	else
	    dout <= dtmp after xcmfClock2Dout;
	end if;

	case cfgbits(1 downto 0) is
	when "01" =>
	    if (mrb'event AND (mrb = '0')) then
		empt <= '0' after xcmfMrb2Output;
		paem <= '0' after xcmfMrb2Output;
		half <= '1' after xcmfMrb2Output;
		full <= '1' after xcmfMrb2Output;
		pafl <= '1' after xcmfMrb2Output;
	    else
		if (rising_edge(ckr)) then
		    if (idx <= 0) then
			empt <= '0' after xcmfClkRd2FlagOut;
		    else
			empt <= '1' after xcmfClkRd2FlagOut;
		    end if;
		    if (idx >= top/2) then
			half <= '0' after xcmfClkWr2FlagOut;
		    else
			half <= '1' after xcmfClkWr2FlagOut;
		    end if;
		    if (((idx <= to_integer(cfgbits(45 downto 35))) AND
							(top = 4096)) OR 
			((idx <= to_integer(cfgbits(45 downto 36))) AND
							(top = 2048)) OR 
			((idx <= to_integer(cfgbits(45 downto 37))) AND
							(top = 1024)) OR 
			((idx <= to_integer(cfgbits(45 downto 38))) AND
							(top =  512))) then
			paem <= '0' after xcmfClkRd2FlagOut;
		    else
			paem <= '1' after xcmfClkRd2FlagOut;
		    end if;
		end if;

		if (rising_edge(ckw)) then
		    if (idx >= top) then
			full <= '0' after xcmfClkWr2FlagOut;
		    else
			full <= '1' after xcmfClkWr2FlagOut;
		    end if;
		    if (idx >= top/2) then
			half <= '0' after xcmfClkWr2FlagOut;
		    else
			half <= '1' after xcmfClkWr2FlagOut;
		    end if;
		    if (((top-idx <= to_integer(cfgbits(45 downto 35))) AND
							(top = 4096)) OR 
			((top-idx <= to_integer(cfgbits(45 downto 36))) AND
							(top = 2048)) OR 
			((top-idx <= to_integer(cfgbits(45 downto 37))) AND
							(top = 1024)) OR 
			((top-idx <= to_integer(cfgbits(45 downto 38))) AND
							(top =  512))) then
			pafl <= '0' after xcmfClkWr2FlagOut;
		    else
			pafl <= '1' after xcmfClkWr2FlagOut;
		    end if;
		end if;
	    end if;
	when others  =>
	    null;
	end case;
    end process;

    process (half, full, empt, pafl, paem)
    begin
	case cfgbits(1 downto 0) is
	when "01" =>
	    hfb   <= half;
	    efb   <= full AND empt;
	    pafeb <= pafl AND paem AND full AND empt;
	when others  =>
	    hfb	<= 'Z';
	    efb	<= 'Z';
	end case;
    end process;

end sim;

library ieee;
use ieee.std_logic_1164.all;

entity c39kck is
    generic (
	cfgbits	: Bit_Vector(63 downto 0);
	xplPulseWthLo		: time;
	xplPulseWthHi		: time;
	xplMinInputDuty		: positive;
	xplMaxInputDuty		: positive;
	xplJitterUncertainty	: time;		-- unused
	xplZeroFBUncertainty	: time;		-- unused
	xplTreeFBUncertainty	: time;		-- unused
	xplMinPinClkPeriod	: time;
	xplMaxPinClkPeriod	: time;
	xplLockTime		: time;
	xplClockTreeOffset	: time;
	xckPin2GClkDirect	: time;
	xplSpreadFreqPercent	: real;		-- unused
	xplSpreadFreqKHz	: real);	-- unused
    port (
	clk	: in	std_logic_vector(3 downto 0);
	nios	: in	std_logic;
	lock	: out	std_logic;
	glclk	: out	std_logic_vector(3 downto 0));
end c39kck;

architecture sim of c39kck is

    -- To use the real silicon time, replace 3 us with xplLockTime.
    constant simLockTime: time := 3 us;

    signal clk_01	: std_logic_vector(3 downto 0);
    signal tmpglclk	: std_logic_vector(3 downto 0);
    signal feedback	: std_logic := '0';
    signal int_fdbk	: std_logic := '0';
    signal tmp_fdbk	: std_logic := '0';
    signal vco		: std_logic := '0';
    signal plllock	: std_logic := '0';
    signal lock_detect	: std_logic := '0';
    signal syncb	: std_logic := '1';
    signal cyc		: time := 0 ns;
    signal mult		: positive;
    signal pllclk	: std_logic_vector(3 downto 0);
    signal xclk		: std_logic_vector(3 downto 0);
    signal pllout	: std_logic_vector(7 downto 0);
    signal tracking	: boolean := false;
    signal speedup	: boolean;
    signal slowdown	: boolean;
    signal killvco	: boolean := false;
    signal ckwidth	: time := 0 ps;
    signal fbwidth	: time := 0 ps;

    type intarray is array (3 downto 0) of natural;
    signal divide	: intarray;
    signal phase	: intarray;

    constant clk_high		: string :=
    "Clock high width violation:";
    constant clk_low		: string :=
    "Clock low width violation:";
    constant clk_cycle_max	: string :=
    "Clock cycle maximum width violation:";
    constant clk_cycle_min	: string :=
    "Clock cycle minimum width violation:";
    constant clk_duty_cycle	: string :=
    "Clock duty cycle violation:";

    constant JitterSpec	: real := 0.01;

begin
    clk_01 <= to_X01(clk);

    -- check clk cycle, high and low times.
    process (clk_01(0))
	variable clkhi, clklo : time := 0 ns;
    begin
	if (cfgbits(0) = '1') then
	    if (clk_01(0) = '0') then
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xplPulseWthHi)) then
		    assert (false)
			report clk_high
			severity failure;
		end if;
		clklo := NOW;
	    elsif (clk_01(0) = '1') then
		if NOT ((clklo = 0 ns) OR ((NOW-clklo) >= xplPulseWthLo)) then
		   assert (false)
			report clk_low
			severity failure;
		end if;
		if NOT ((clkhi=0 ns)OR((NOW-clkhi) >= xplMinPinClkPeriod)) then
		    assert (false)
			report clk_cycle_min
			severity failure;
		end if;
		if NOT ((clkhi=0 ns)OR((NOW-clkhi) <= xplMaxPinClkPeriod)) then
		    assert (false)
			report clk_cycle_max
			severity failure;
		end if;
		-- Check the duty cycle
		if ((clklo > 0 ns) AND (clkhi > 0 ns)) AND
		    (((clklo - clkhi)*100/(NOW - clkhi) < xplMinInputDuty) OR
		     ((clklo - clkhi)*100/(NOW - clkhi) > xplMaxInputDuty)) then
		    assert (false)
			report clk_duty_cycle
			severity error;
		end if;
		clkhi := NOW;
	    end if;
	end if;
    end process;

    -- Get the feedback
    process (clk_01(1), int_fdbk)
    begin
	if (cfgbits(0) = '1') then
	    case cfgbits(5 downto 4) is
		when "11" => feedback <= '0';
		    assert(false)
		    report "Illegal PLL feedback select."
		    severity failure;
		when "10" => feedback <= clk_01(1);
		when "01" => feedback <= int_fdbk;
		when "00" => feedback <= int_fdbk;
	    end case;
	end if;
    end process;

    mult <= 1  when (cfgbits(5 downto 4)) = "10"  else
	    6  when (cfgbits(3 downto 1)) = "111" else
	    5  when (cfgbits(3 downto 1)) = "110" else
	    3  when (cfgbits(3 downto 1)) = "101" else
	    16 when (cfgbits(3 downto 1)) = "100" else
	    8  when (cfgbits(3 downto 1)) = "011" else
	    4  when (cfgbits(3 downto 1)) = "010" else
	    2  when (cfgbits(3 downto 1)) = "001" else
	    1  when (cfgbits(3 downto 1)) = "000";

    -- PLL and clock multiplier
    process (clk_01(0), feedback)
	variable fbevent: time := 0 ps;
	variable ckevent: time := 0 ps;
	variable kpwidth: time := 0 ps;
	variable width	: time := 0 ps;
	variable edges	: time := 0 ps;
	variable clock	: std_logic := '1';
	variable switch	: boolean := false;
    begin
	if (cfgbits(0) = '1') then
	    if (rising_edge(clk_01(0))) then
		kpwidth := ckwidth;
		ckwidth <= NOW - ckevent;
		ckevent := NOW;
	    end if;

	    if (rising_edge(feedback)) then
		fbwidth <= NOW - fbevent;
		fbevent := NOW;
	    end if;

	    if (rising_edge(feedback)) then
		if ((((ckwidth-fbwidth > ckwidth*JitterSpec)
		  OR  (fbwidth-ckwidth > ckwidth*JitterSpec))
			AND (plllock = '1'))
		  OR ((ckwidth-kpwidth > ckwidth*JitterSpec)
		  OR  (kpwidth-ckwidth > ckwidth*JitterSpec))) then
		    plllock <= '0';
		    syncb   <= '1';
		end if;
	    end if;

	    -- Adjust VCO depending upon the widths of the source and feedback.
	    if (rising_edge(clk_01(0)) OR rising_edge(feedback)) then
		if (rising_edge(feedback)) then
		    switch := true;
		end if;
		if (NOT switch) then
		    speedup  <= false;
		    slowdown <= false;
		elsif (rising_edge(feedback)) then
		    if    (ckwidth > fbwidth) then
			speedup  <= false;
			slowdown <= true AND (syncb = '1');
		    elsif (ckwidth < fbwidth) then
			speedup  <= true AND (syncb = '1');
			slowdown <= false;
		    else
			speedup  <= false;
			slowdown <= false;
			syncb    <= transport '0' after simLockTime/10;
			plllock  <= transport '1' after simLockTime;
		    end if;
		end if;
	    end if;
	end if;
    end process;

    -- Let the VCO run free (at 145 MHz. initially).
    process
	variable res_fs	: time := 1 fs;
	variable is_fs	: boolean;
    	variable width	: time := 6.875 ns;
    begin
	if ((res_fs + res_fs) /= res_fs) then
	    is_fs := true;
	else
	    is_fs := false;
	end if;
	if (cfgbits(0) = '1') then
	    if    (    speedup AND NOT slowdown) then
		if (ckwidth + 1 ns < fbwidth) then
		    width := width - 100 ps;
		elsif (is_fs) then
		    if    (ckwidth + 100 ps < fbwidth) then
			width := width - 10  ps;
		    elsif (ckwidth + 10  ps < fbwidth) then
			width := width - 1   ps;
		    elsif (ckwidth + 1   ps < fbwidth) then
			width := width - 100 fs;
		    elsif (ckwidth + 100 fs < fbwidth) then
			width := width - 10  fs;
		    else
			width := width - 1   fs;
		    end if;
		else
		    width := width - 1 ps;
		end if;
	    elsif (NOT speedup AND     slowdown) then
		if (ckwidth - 1 ns > fbwidth) then
		    width := width + 100 ps;
		elsif (is_fs) then
		    if    (ckwidth - 100 ps > fbwidth) then
			width := width + 10  ps;
		    elsif (ckwidth - 10  ps > fbwidth) then
			width := width + 1   ps;
		    elsif (ckwidth - 1   ps > fbwidth) then
			width := width + 100 fs;
		    elsif (ckwidth - 100 fs > fbwidth) then
			width := width + 10  fs;
		    else
			width := width + 1   fs;
		    end if;
		else
		    width := width + 1 ps;
		end if;
	    elsif (NOT speedup AND NOT slowdown AND (ckwidth > 0 ps)) then
		width := ckwidth/(ckwidth/(width - 5 ps)); -- a small fudge.
	    end if;
	    cyc <= width / 2;
	    for i in 1 to 32 loop
		wait for width/2;
		vco <= NOT vco;
	    end loop;
	    if (killvco) then
		wait on killvco;
	    end if;
	else
	    vco <= '0';
	    wait;
	end if;
    end process;

    -- Stop the VCO if the input clock is > 2X too slow after it has locked.
    process (vco, clk_01(0))
	variable ckevent: time := 0 ps;
    begin
	if (clk_01(0)'event) then
	    ckevent := NOW;
	end if;
	if (NOW-ckevent > 2 * xplMaxPinClkPeriod AND lock_detect = '1') then
	    killvco <= true;
	else
	    killvco <= false;
	end if;
    end process;

    lock_detect <= plllock when (tracking OR (cfgbits(5 downto 4) /= "10"))
		else '0';

    -- lock detect select
    process (lock_detect, nios)
    begin
	if (cfgbits(0) = '1') then
	    case cfgbits(42) is
		when '1' => lock <= lock_detect;
		when '0' => lock <= nios;
	    end case;
	end if;
    end process;

    -- VCO Frequency Check
    process (vco)
	constant tmax : time := 10.000 ns;	-- Min frequency = 100 MHz
	constant tmin : time :=  3.750 ns;	-- Max frequency = 266 MHz
	variable ckhi : time := 0 ns;
    begin
	if (cfgbits(0) = '1') then
	    if (vco = '1') then
		if (syncb = '0') then
		    if (((NOW - ckhi) < tmin) OR ((NOW - ckhi) > tmax)) then
			assert (false)
			    report "VCO frequency outside its operating range."
			    severity warning;
		    end if;
		end if;
		ckhi := NOW;
	    end if;
	end if;
    end process;

    -- phase shifter
    process (vco)
	variable width	: time := 0 ns;
	variable edges	: time := 0 ns;
    begin
	if (cfgbits(0) = '1') then
	    width := (NOW - edges);
	    edges := NOW;
	    pllout(7) <= transport vco after width*1.75; -- 315 degrees
	    pllout(6) <= transport vco after width*1.50; -- 270 degrees
	    pllout(5) <= transport vco after width*1.25; -- 225 degrees
	    pllout(4) <= transport vco after width*1.00; -- 180 degrees
	    pllout(3) <= transport vco after width*0.75; -- 135 degrees
	    pllout(2) <= transport vco after width*0.50; --  90 degrees
	    pllout(1) <= transport vco after width*0.25; --  45 degrees
	    pllout(0) <= transport vco after width*0.00; --   0 degrees
	end if;
    end process;

    -- Divide and phase select
    process
    begin
	if (cfgbits(0) = '1') then
	    for i in 0 to 3 loop
		if (cfgbits(22 + i*5) = '1') then
		    divide(i) <= 1;
		    if    (cfgbits(21+i*5 downto 18+i*5) = "0110") then
			phase(i) <= 315;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "0101") then
			phase(i) <= 270;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "0100") then
			phase(i) <= 225;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "0011") then
			phase(i) <= 180;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "0010") then
			phase(i) <= 135;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "0001") then
			phase(i) <=  90;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "0000") then
			phase(i) <=  45;
		    else
			assert(false)
			report "Illegal phase and divide select."
			severity failure;
		    end if;
		else
		    if    (cfgbits(8+i*3 downto 6+i*3)="111") then
			divide(i) <= 6;
		    elsif (cfgbits(8+i*3 downto 6+i*3)="110") then
			divide(i) <= 5;
		    elsif (cfgbits(8+i*3 downto 6+i*3)="101") then
			divide(i) <= 3;
		    elsif (cfgbits(8+i*3 downto 6+i*3)="100") then
			divide(i) <= 16;
		    elsif (cfgbits(8+i*3 downto 6+i*3)="011") then
			divide(i) <= 8;
		    elsif (cfgbits(8+i*3 downto 6+i*3)="010") then
			divide(i) <= 4;
		    elsif (cfgbits(8+i*3 downto 6+i*3)="001") then
			divide(i) <= 2;
		    elsif (cfgbits(8+i*3 downto 6+i*3)="000") then
			divide(i) <= 1;
		    end if;

		    if    (cfgbits(21+i*5 downto 18+i*5) = "1110") then
			phase(i) <= 315;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "1101") then
			phase(i) <= 270;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "1100") then
			phase(i) <= 225;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "1011") then
			phase(i) <= 180;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "1010") then
			phase(i) <= 135;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "1001") then
			phase(i) <=  90;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "1000") then
			phase(i) <=  45;
		    elsif (cfgbits(21+i*5 downto 18+i*5) = "0000") then
			phase(i) <=   0;
		    else
			assert(false)
			report "Illegal phase select."
			severity failure;
		    end if;
		end if;
	    end loop;
	end if;
	wait;
    end process;

    -- Generate 4 clocks depending on the phase.
    xclk(3) <=  pllout(7) when (phase(3) = 315) else
		pllout(6) when (phase(3) = 270) else
		pllout(5) when (phase(3) = 225) else
		pllout(4) when (phase(3) = 180) else
		pllout(3) when (phase(3) = 135) else
		pllout(2) when (phase(3) =  90) else
		pllout(1) when (phase(3) =  45) else
		pllout(0) when (phase(3) =   0);
    xclk(2) <=  pllout(7) when (phase(2) = 315) else
		pllout(6) when (phase(2) = 270) else
		pllout(5) when (phase(2) = 225) else
		pllout(4) when (phase(2) = 180) else
		pllout(3) when (phase(2) = 135) else
		pllout(2) when (phase(2) =  90) else
		pllout(1) when (phase(2) =  45) else
		pllout(0) when (phase(2) =   0);
    xclk(1) <=  pllout(7) when (phase(1) = 315) else
		pllout(6) when (phase(1) = 270) else
		pllout(5) when (phase(1) = 225) else
		pllout(4) when (phase(1) = 180) else
		pllout(3) when (phase(1) = 135) else
		pllout(2) when (phase(1) =  90) else
		pllout(1) when (phase(1) =  45) else
		pllout(0) when (phase(1) =   0);
    xclk(0) <=  pllout(7) when (phase(0) = 315) else
		pllout(6) when (phase(0) = 270) else
		pllout(5) when (phase(0) = 225) else
		pllout(4) when (phase(0) = 180) else
		pllout(3) when (phase(0) = 135) else
		pllout(2) when (phase(0) =  90) else
		pllout(1) when (phase(0) =  45) else
		pllout(0) when (phase(0) =   0);

    -- Apply the divide amount to the clocks.
    process
    begin
	wait on vco;
	if (rising_edge(vco) AND (NOW > 0 ps)) then
	    tmp_fdbk <= '1';
	    wait for  mult    * cyc;
	    tmp_fdbk <= '0';
	    wait for (mult-1) * cyc;
	end if;
    end process;

    process
    begin
	wait on xclk(3);
	if (rising_edge(xclk(3)) AND (NOW > 0 ps)) then
	    pllclk(3) <= '1';
	    wait for  divide(3)    * cyc;
	    pllclk(3) <= '0';
	    wait for (divide(3)-1) * cyc;
	end if;
    end process;

    process
    begin
	wait on xclk(2);
	if (rising_edge(xclk(2)) AND (NOW > 0 ps)) then
	    pllclk(2) <= '1';
	    wait for  divide(2)    * cyc;
	    pllclk(2) <= '0';
	    wait for (divide(2)-1) * cyc;
	end if;
    end process;

    process
    begin
	wait on xclk(1);
	if (rising_edge(xclk(1)) AND (NOW > 0 ps)) then
	    pllclk(1) <= '1';
	    wait for  divide(1)    * cyc;
	    pllclk(1) <= '0';
	    wait for (divide(1)-1) * cyc;
	end if;
    end process;

    process
    begin
	wait on xclk(0);
	if (rising_edge(xclk(0)) AND (NOW > 0 ps)) then
	    pllclk(0) <= '1';
	    wait for  divide(0)    * cyc;
	    pllclk(0) <= '0';
	    wait for (divide(0)-1) * cyc;
	end if;
    end process;

    -- global clock output mux
    process (pllclk, clk_01)
    begin
	for i in 3 downto 0 loop
	    if (cfgbits(38+i) = '1') then
		if (cfgbits(0) = '1') then
		    tmpglclk(i)<= pllclk(i);
		else
		    assert(false)
		    report "PLL powered down, no signal available for output."
		    severity failure;
		end if;
	    else
		tmpglclk(i)<= clk_01(i);
	    end if;
	end loop;
    end process;

    -- compensate for external feedback
    process (tmpglclk, feedback, clk_01(0), tmp_fdbk)
	variable ckevent : time := 0 ps;
	variable half    : time := 0 ps;
    	variable var     : time := 0 ps;
	variable delay   : time := 0 ps;
    begin
	if (cfgbits(0) = '1') then
	    if (rising_edge(clk_01(0))) then
		ckevent := NOW;
	    end if;
	    if (falling_edge(clk_01(0))) then
		half := NOW - ckevent;
	    end if;
	    if (syncb = '1') then
		if (rising_edge(feedback)) then
		    if    ((NOW - ckevent) < half) then
			var := 2*half - (NOW - ckevent);
		    else
			var := 3*half - (NOW - ckevent);
		    end if;
		end if;
		glclk    <= tmpglclk;
		int_fdbk <= tmp_fdbk;
		tracking <= false;
	    else
		if (cfgbits(5 downto 4) = "10") then
		    if (rising_edge(feedback)) then
			if    (((NOW - ckevent) > half)) then
			    if NOT tracking AND (2*half-(NOW-ckevent) > 20 ps) then
				var := var + 20 ps;
			    else
				if ((NOW - ckevent) /= 0 ps) then
				    var := var + 1 ps;
				end if;
				tracking <= true;
			    end if;
			else
			    if NOT tracking AND ((NOW - ckevent) > 20 ps) then
				var := var - 20 ps;
			    else
				if ((NOW - ckevent) /= 0 ps) then
				    var := var - 1 ps;
				end if;
				tracking <= true;
			    end if;
			end if;
		    end if;
		    glclk <= transport tmpglclk after var;
		else
		    int_fdbk <= transport tmp_fdbk after var - half;
		    if    (cfgbits(5 downto 4) = "00") then
		    	delay := xckPin2GClkDirect;
		    elsif (cfgbits(5 downto 4) = "01") then
			-- The 2*half is to add one full clock time to 
			-- remove the chance for a negative delay.
		    	delay := 2*half + xckPin2GClkDirect-xplClockTreeOffset;
		    end if;
		    glclk    <= transport tmpglclk after var - half + delay;
		    tracking <= true;
		end if;
	    end if;
	else
	    glclk    <= tmpglclk after xckPin2GClkDirect;
	end if;
    end process;

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c39kcm is
    generic (
	cfgbits	: Bit_Vector(45 downto 0);
	memdata	: chmem;
	-- Async parameters
	xcmReadAddrWthHi	: time;		-- checked parameters
	xcmWritAddrWthHi	: time;
	xcmWriEnaWthHi		: time;
	xcmAddrAtWriEnaFallSetup: time;
	xcmAddrAtWriEnaRiseSetup: time;
	xcmAddrAtWriEnaFallHold	: time;
	xcmDinAtWriEnaFallSetup	: time;
	xcmDinAtWriEnaFallHold	: time;
	xcmAddr2DoutRegD	: time;		-- applied parameters
	xcmWriEna2DoutRegD	: time;
	xcmDin2DoutRegD		: time;
	xcmDoutRegD2Dout	: time;
	-- Sync parameters
	xcmClkInWthCy		: time;		-- checked parameters
	xcmClkInWthHi		: time;
	xcmClkInWthLo		: time;
	xcmAddrAtClkInSetup	: time;
	xcmAddrAtClkInHold	: time;
	xcmWriEnaAtClkInSetup	: time;
	xcmWriEnaAtClkInHold	: time;
	xcmDinAtClkInSetup	: time;
	xcmDinAtClkInHold	: time;
	xcmClkIn2DoutRegD	: time;		-- applied parameters
	-- Output Register parameters
	xcmDoutRegCkWthCy	: time;		-- checked parameters
	xcmDoutRegCkWthHi	: time;
	xcmDoutRegCkWthLo	: time;
	xcmDoutRegSetup		: time;
	xcmDoutRegHold		: time;
	xcmDoutRegReWthHi	: time;
	xcmDoutRegReRcr		: time;
	xcmReset2Dout		: time;		-- applied parameters
	xcmClkOut2Dout		: time;
	xcmAddrTransDetect	: time);
    port (
	din_a		: in	std_logic_vector( 7 downto 0);
	din_b		: in	std_logic_vector( 7 downto 0);
	addr_a		: in	std_logic_vector(11 downto 0);
	addr_b		: in	std_logic_vector(11 downto 0);
	we_a		: in	std_logic;
	we_b		: in	std_logic;
	iclk_a		: in	std_logic := '0';
	iclk_b		: in	std_logic := '0';
	oclk_a		: in	std_logic := '0';
	oclk_b		: in	std_logic := '0';
	reset_a		: in	std_logic := '0';
	reset_b		: in	std_logic := '0';
	addr_matchb	: out	std_logic;
	dout_a		: out	std_logic_vector( 7 downto 0);
	dout_b		: out	std_logic_vector( 7 downto 0));
end c39kcm;

architecture sim of c39kcm is

    signal atmp_a,atmp_b	: std_logic_vector(11 downto 0);
    signal dtin_a,dtin_b	: std_logic_vector( 7 downto 0);
    signal dtout_a,dtout_b	: std_logic_vector( 7 downto 0);
    signal cdout_a,cdout_b	: std_logic_vector( 7 downto 0);
    signal wtmp_a,wtmp_b	: std_logic;
    signal atd_a, atd_b		: std_logic;

    -- Signals for use with negative setup and hold checks
    signal dsaddr_a	:std_logic_vector(11 downto 0);
    signal daiclk_a	:std_logic;
    signal dswe_a	:std_logic;
    signal dwiclk_a	:std_logic;
    signal dsdin_a	:std_logic_vector( 7 downto 0);
    signal ddiclk_a	:std_logic;
    signal dcdout_a	:std_logic_vector( 7 downto 0);
    signal doclk_a	:std_logic;
    signal dadin_a	:std_logic_vector( 7 downto 0);
    signal ddwe_a	:std_logic;
    signal daaddr_a	:std_logic_vector(11 downto 0);
    signal dawer_a	:std_logic;
    signal dawef_a	:std_logic;

    signal dsaddr_b	:std_logic_vector(11 downto 0);
    signal daiclk_b	:std_logic;
    signal dswe_b	:std_logic;
    signal dwiclk_b	:std_logic;
    signal dsdin_b	:std_logic_vector( 7 downto 0);
    signal ddiclk_b	:std_logic;
    signal dcdout_b	:std_logic_vector( 7 downto 0);
    signal doclk_b	:std_logic;
    signal dadin_b	:std_logic_vector( 7 downto 0);
    signal ddwe_b	:std_logic;
    signal daaddr_b	:std_logic_vector(11 downto 0);
    signal dawer_b	:std_logic;
    signal dawef_b	:std_logic;

    -- Constants for use with negative setup and hold checks
    constant syncAddrSetup	: time := timeAdjust(xcmAddrAtClkInSetup);
    constant syncAddrHold	: time := timeAdjust(xcmAddrAtClkInHold);
    constant syncWESetup	: time := timeAdjust(xcmWriEnaAtClkInSetup);
    constant syncWEHold		: time := timeAdjust(xcmWriEnaAtClkInHold);
    constant syncDataSetup	: time := timeAdjust(xcmDinAtClkInSetup);
    constant syncDataHold	: time := timeAdjust(xcmDinAtClkInHold);
    constant dataOutSetup	: time := timeAdjust(xcmDoutRegSetup);
    constant dataOutHold	: time := timeAdjust(xcmDoutRegHold);
    constant asyncAddrSetupF	: time := timeAdjust(xcmAddrAtWriEnaFallSetup);
    constant asyncAddrSetupR	: time := timeAdjust(xcmAddrAtWriEnaRiseSetup);
    constant asyncAddrHold	: time := timeAdjust(xcmAddrAtWriEnaFallHold);
    constant asyncDataSetup	: time := timeAdjust(xcmDinAtWriEnaFallSetup);
    constant asyncDataHold	: time := timeAdjust(xcmDinAtWriEnaFallHold);

    constant unk	: string := " Setting output unknown.";

    -- Port A check signals and errors
    signal iclkerr_a	: std_logic;
    constant iclk_width_a	: string :=
    "Input clock A cycle width violation:"	& unk;
    constant iclk_low_a		: string :=
    "Input clock A low width violation:"	& unk;
    constant iclk_high_a	: string :=
    "Input clock A high width violation:"	& unk;

    signal aserr_a	: std_logic;
    constant addr2iclk_setup_a	: string :=
    "Address A to input clock setup violation:"	& unk;

    signal aherr_a	: std_logic;
    constant addr2iclk_hold_a	: string :=
    "Input clock to address A hold violation:"	& unk;

    signal wserr_a	: std_logic;
    constant write2iclk_setup_a	: string :=
    "Write A to clock setup violation:"		& unk;

    signal wherr_a	: std_logic;
    constant write2iclk_hold_a	: string :=
    "Clock to write A hold violation:"		& unk;

    signal dserr_a	: std_logic;
    constant data2iclk_setup_a	: string :=
    "Data A to clock setup violation:"		& unk;

    signal dherr_a	: std_logic;
    constant data2iclk_hold_a	: string :=
    "Clock to data A hold violation:"		& unk;

    signal wrwerr_a	: std_logic;
    constant write_width_a	: string :=
    "Minimum write width A violation:"		& unk;

    signal wcycerr_a	: std_logic;
    constant writeaddr_cycle_a	: string :=
    "Minimum write cycle A violation:"		& unk;

    signal rcycerr_a	: std_logic;
    constant readaddr_cycle_a	: string :=
    "Minimum read cycle A violation:"		& unk;

    signal awserr_a	: std_logic;
    constant addr2westart_setup_a: string :=
    "Address to we A start setup violation:"	& unk;
    constant addr2weend_setup_a: string :=
    "Address to we A end setup violation:"	& unk;

    signal awherr_a	: std_logic;
    constant addr2we_hold_a	: string :=
    "We to address A hold violation:"		& unk;

    signal dwserr_a	: std_logic;
    constant data2we_setup_a	: string :=
    "Data A to we setup violation:"		& unk;

    signal dwherr_a	: std_logic;
    constant data2we_hold_a	: string :=
    "We to data A hold violation:"		& unk;

    signal oclkerr_a	: std_logic;
    constant outputclock_width_a: string :=
    "Output clock A cycle width violation:"	& unk;
    constant outputclock_low_a	: string :=
    "Output clock A low width violation:"	& unk;
    constant outputclock_high_a	: string :=
    "Output clock A high width violation:"	& unk;

    signal rcverr_a	: std_logic;
    constant outreg_rcvry_a	: string :=
    "Output reg. A reset recovery violation:"	& unk;

    signal rsterr_a	: std_logic;
    constant reset_width_a	: string :=
    "Reset A width violation:"			& unk;

    signal oserr_a	: std_logic;
    constant data2oclk_setup_a	: string :=
    "Data to output clock setup violation:"	& unk;
    constant addr2oclk_setup_a	: string :=
    "Address to output clock setup violation:"	& unk;
    constant we2oclk_setup_a	: string :=
    "WE to output clock setup violation:"	& unk;
    constant iclk2oclk_setup_a	: string :=
    "In clock to out clock setup violation:"	& unk;

    signal oherr_a	: std_logic;
    constant data2oclk_hold_a	: string :=
    "Output clock to data hold violation:"	& unk;
    constant addr2oclk_hold_a	: string :=
    "Output clock to address hold violation:"	& unk;
    constant we2oclk_hold_a	: string :=
    "Output clock to WE hold violation:"	& unk;
    constant iclk2oclk_hold_a	: string :=
    "Out clock to in clock hold violation:"	& unk;

    -- Port B check signals and errors
    signal iclkerr_b	: std_logic;
    constant iclk_width_b	: string :=
    "Input clock B cycle width violation:"	& unk;
    constant iclk_low_b		: string :=
    "Input clock B low width violation:"	& unk;
    constant iclk_high_b	: string :=
    "Input clock B high width violation:"	& unk;

    signal aserr_b	: std_logic;
    constant addr2iclk_setup_b	: string :=
    "Address B to input clock setup violation:"	& unk;
    
    signal aherr_b	: std_logic;
    constant addr2iclk_hold_b	: string :=
    "Input clock to address B hold violation:"	& unk;

    signal wserr_b	: std_logic;
    constant write2iclk_setup_b	: string :=
    "Write B to clock setup violation:"		& unk;

    signal wherr_b	: std_logic;
    constant write2iclk_hold_b	: string :=
    "Clock to write B hold violation:"		& unk;

    signal dserr_b	: std_logic;
    constant data2iclk_setup_b	: string :=
    "Data B to clock setup violation:"		& unk;

    signal dherr_b	: std_logic;
    constant data2iclk_hold_b	: string :=
    "Clock to data B hold violation:"		& unk;

    signal wrwerr_b	: std_logic;
    constant write_width_b	: string :=
    "Minimum write width B violation:"		& unk;

    signal wcycerr_b	: std_logic;
    constant writeaddr_cycle_b	: string :=
    "Minimum write cycle B violation:"		& unk;

    signal rcycerr_b	: std_logic;
    constant readaddr_cycle_b	: string :=
    "Minimum read cycle B violation:"		& unk;

    signal awserr_b	: std_logic;
    constant addr2westart_setup_b: string :=
    "Address to we B start setup violation:"	& unk;
    constant addr2weend_setup_b: string :=
    "Address to we B end setup violation:"	& unk;

    signal awherr_b	: std_logic;
    constant addr2we_hold_b	: string :=
    "We to address B hold violation:"		& unk;

    signal dwserr_b	: std_logic;
    constant data2we_setup_b	: string :=
    "Data B to we setup violation:"		& unk;

    signal dwherr_b	: std_logic;
    constant data2we_hold_b	: string :=
    "We to data B hold violation:"		& unk;

    signal oclkerr_b	: std_logic;
    constant outputclock_width_b: string :=
    "Output clock B cycle width violation:"	& unk;
    constant outputclock_low_b	: string :=
    "Output clock B low width violation:"	& unk;
    constant outputclock_high_b	: string :=
    "Output clock B high width violation:"	& unk;

    signal rcverr_b	: std_logic;
    constant outreg_rcvry_b	: string :=
    "Output reg. B reset recovery violation:"	& unk;
    
    signal rsterr_b	: std_logic;
    constant reset_width_b	: string :=
    "Reset B width violation:"			& unk;

    signal oserr_b	: std_logic;
    constant data2oclk_setup_b	: string :=
    "Data to output clock setup violation:"	& unk;
    constant addr2oclk_setup_b	: string :=
    "Address to output clock setup violation:"	& unk;
    constant we2oclk_setup_b	: string :=
    "WE to output clock setup violation:"	& unk;
    constant iclk2oclk_setup_b	: string :=
    "In clock to out clock setup violation:"	& unk;

    signal oherr_b	: std_logic;
    constant data2oclk_hold_b	: string :=
    "Output clock to data hold violation:"	& unk;
    constant addr2oclk_hold_b	: string :=
    "Output clock to address hold violation:"	& unk;
    constant we2oclk_hold_b	: string :=
    "Output clock to WE hold violation:"	& unk;
    constant iclk2oclk_hold_b	: string :=
    "Out clock to in clock hold violation:"	& unk;

begin

    -- check sync iclk_a cycle, high and low times.
    process (iclk_a)
	variable clkhi, clklo : time := 0 ns;
    begin
	if (cfgbits(4) = '1') then
	    if (iclk_a = '0') then
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcmClkInWthHi)) then
		    assert (false)
			report iclk_width_a
			severity warning;
		    iclkerr_a <= '1'; 
		    iclkerr_a <= transport '0' AFTER 1 ns;
		end if;
		clklo := NOW;
	    elsif (iclk_a = '1') then
		if NOT ((clklo = 0 ns) OR ((NOW-clklo) >= xcmClkInWthLo)) then
		   assert (false)
			report iclk_low_a
			severity warning;
		    iclkerr_a <= '1'; 
		    iclkerr_a <= transport '0' AFTER 1 ns;
		end if;
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcmClkInWthCy)) then
		    assert (false)
			report iclk_high_a
			severity warning;
		    iclkerr_a <= '1'; 
		    iclkerr_a <= transport '0' AFTER 1 ns;
		end if;
		clkhi := NOW;
	    end if;
	end if;
    end process;

    -- check sync iclk_b cycle, high and low times.
    process (iclk_b)
	variable clkhi, clklo : time := 0 ns;
    begin
	if (cfgbits(17) = '1') then
	    if (iclk_b = '0') then
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcmClkInWthHi)) then
		    assert (false)
			report iclk_width_b
			severity warning;
		    iclkerr_b <= '1'; 
		    iclkerr_b <= transport '0' AFTER 1 ns;
		end if;
		clklo := NOW;
	    elsif (iclk_b = '1') then
		if NOT ((clklo = 0 ns) OR ((NOW-clklo) >= xcmClkInWthLo)) then
		   assert (false)
			report iclk_low_b
			severity warning;
		    iclkerr_b <= '1'; 
		    iclkerr_b <= transport '0' AFTER 1 ns;
		end if;
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcmClkInWthCy)) then
		    assert (false)
			report iclk_high_b
			severity warning;
		    iclkerr_b <= '1'; 
		    iclkerr_b <= transport '0' AFTER 1 ns;
		end if;
		clkhi := NOW;
	    end if;
	end if;
    end process;

    -- check sync address setup _a
    daiclk_a <= iclk_a after syncAddrSetup;
    process (addr_a, daiclk_a)
    	variable addrev : time := 0 ns;
    begin
    	if (cfgbits(4) = '1') then
	    if (rising_edge(daiclk_a)) then
		if ((addrev /= 0 ns) AND 
			((NOW-addrev) < xcmAddrAtClkInSetup+syncAddrSetup)) then
		    assert (false)
			report addr2iclk_setup_a
			severity warning;
		    aserr_a <= '1'; 
		    aserr_a <= transport '0' AFTER 1 ns;
		end if;
	    elsif (addr_a'event) then
	    	addrev := NOW;
	    end if;
	end if;
    end process;

    -- check sync address hold _a
    dsaddr_a <= addr_a after syncAddrHold;
    process (dsaddr_a, iclk_a)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(4) = '1') then
	    if (rising_edge(iclk_a)) then
	    	clckev := NOW;
	    elsif (dsaddr_a'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcmAddrAtClkInHold+syncAddrHold)) then
		    assert (false)
			report addr2iclk_hold_a
			severity warning;
		    aherr_a <= '1'; 
		    aherr_a <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check sync address setup _b
    daiclk_b <= iclk_b after syncAddrSetup;
    process (addr_b, daiclk_b)
    	variable addrev : time := 0 ns;
    begin
    	if (cfgbits(17) = '1') then
	    if (rising_edge(daiclk_b)) then
		if ((addrev /= 0 ns) AND 
			((NOW-addrev) < xcmAddrAtClkInSetup+syncAddrSetup)) then
		    assert (false)
			report addr2iclk_setup_b
			severity warning;
		    aserr_b <= '1'; 
		    aserr_b <= transport '0' AFTER 1 ns;
		end if;
	    elsif (addr_b'event) then
	    	addrev := NOW;
	    end if;
	end if;
    end process;

    -- check sync address hold _b
    dsaddr_b <= addr_b after syncAddrHold;
    process (dsaddr_b, iclk_b)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(17) = '1') then
	    if (rising_edge(iclk_b)) then
	    	clckev := NOW;
	    elsif (dsaddr_b'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcmAddrAtClkInHold+syncAddrHold)) then
		    assert (false)
			report addr2iclk_hold_b
			severity warning;
		    aherr_b <= '1'; 
		    aherr_b <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check sync write setup _a
    dwiclk_a <= iclk_a after syncWESetup;
    process (we_a, dwiclk_a)
    	variable writev : time := 0 ns;
    begin
    	if (cfgbits(4) = '1') then
	    if (rising_edge(dwiclk_a)) then
		if ((writev /= 0 ns) AND 
			((NOW-writev) < xcmWriEnaAtClkInSetup+syncWESetup)) then
		    assert (false)
			report write2iclk_setup_a
			severity warning;
		    wserr_a <= '1'; 
		    wserr_a <= transport '0' AFTER 1 ns;
		end if;
	    elsif (we_a'event) then
	    	writev := NOW;
	    end if;
	end if;
    end process;

    -- check sync write hold _a
    dswe_a <= we_a after syncWEHold;
    process (dswe_a, iclk_a)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(4) = '1') then
	    if (rising_edge(iclk_a)) then
	    	clckev := NOW;
	    elsif (dswe_a'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcmWriEnaAtClkInHold+syncWEHold)) then
		    assert (false)
			report write2iclk_hold_a
			severity warning;
		    wherr_a <= '1'; 
		    wherr_a <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check sync write setup _b
    dwiclk_b <= iclk_b after syncWESetup;
    process (we_b, dwiclk_b)
    	variable writev : time := 0 ns;
    begin
    	if (cfgbits(17) = '1') then
	    if (rising_edge(dwiclk_b)) then
		if ((writev /= 0 ns) AND 
			((NOW-writev) < xcmWriEnaAtClkInSetup+syncWESetup)) then
		    assert (false)
			report write2iclk_setup_b
			severity warning;
		    wserr_b <= '1'; 
		    wserr_b <= transport '0' AFTER 1 ns;
		end if;
	    elsif (we_b'event) then
	    	writev := NOW;
	    end if;
	end if;
    end process;

    -- check sync write hold _b
    dswe_b <= we_b after syncWEHold;
    process (dswe_b, iclk_b)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(17) = '1') then
	    if (rising_edge(iclk_b)) then
	    	clckev := NOW;
	    elsif (dswe_b'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcmWriEnaAtClkInHold+syncWEHold)) then
		    assert (false)
			report write2iclk_hold_b
			severity warning;
		    wherr_b <= '1'; 
		    wherr_b <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check sync data setup _a
    ddiclk_a <= iclk_a after syncDataSetup;
    process (din_a, ddiclk_a)
    	variable dataev : time := 0 ns;
    begin
    	if (cfgbits(5) = '1') then
	    if (rising_edge(ddiclk_a)) then
		if ((dataev /= 0 ns) AND 
			((NOW-dataev) < xcmDinAtClkInSetup+syncDataSetup)) then
		    assert (false)
			report data2iclk_setup_a
			severity warning;
		    dserr_a <= '1'; 
		    dserr_a <= transport '0' AFTER 1 ns;
		end if;
	    elsif (din_a'event) then
	    	dataev := NOW;
	    end if;
	end if;
    end process;

    -- check sync data hold _a
    dsdin_a <= din_a after syncDataHold;
    process (dsdin_a, iclk_a)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(5) = '1') then
	    if (rising_edge(iclk_a)) then
	    	clckev := NOW;
	    elsif (dsdin_a'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcmDinAtClkInHold+syncDataHold)) then
		    assert (false)
			report data2iclk_hold_a
			severity warning;
		    dherr_a <= '1'; 
		    dherr_a <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check sync data setup _b
    ddiclk_b <= iclk_b after syncDataSetup;
    process (din_b, ddiclk_b)
    	variable dataev : time := 0 ns;
    begin
    	if (cfgbits(18) = '1') then
	    if (rising_edge(ddiclk_b)) then
		if ((dataev /= 0 ns) AND 
			((NOW-dataev) < xcmDinAtClkInSetup+syncDataSetup)) then
		    assert (false)
			report data2iclk_setup_b
			severity warning;
		    dserr_b <= '1'; 
		    dserr_b <= transport '0' AFTER 1 ns;
		end if;
	    elsif (din_b'event) then
	    	dataev := NOW;
	    end if;
	end if;
    end process;

    -- check sync data hold _b
    dsdin_b <= din_b after syncDataHold;
    process (dsdin_b, iclk_b)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(18) = '1') then
	    if (rising_edge(iclk_b)) then
	    	clckev := NOW;
	    elsif (dsdin_b'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcmDinAtClkInHold+syncDataHold)) then
		    assert (false)
			report data2iclk_hold_b
			severity warning;
		    dherr_b <= '1'; 
		    dherr_b <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check async write_a minimum valid
    process (we_a)
	variable write_ev : time := 0 ns;
    begin
	if ((cfgbits(4) = '0') AND (we_a = '0')) then
	    if NOT ((write_ev = 0 ns) OR ((NOW - write_ev) >= xcmWriEnaWthHi)) then
		assert (false)
		    report write_width_a
		    severity warning;
		wrwerr_a <= '1'; 
		wrwerr_a <= transport '0' AFTER 1 ns;
	    end if;
	    write_ev := NOW;
	end if;
    end process;

    -- check async write_b minimum valid
    process (we_b)
	variable write_ev : time := 0 ns;
    begin
	if ((cfgbits(17) = '0') AND (we_b = '0')) then
	    if NOT ((write_ev = 0 ns) OR ((NOW - write_ev) >= xcmWriEnaWthHi)) then
		assert (false)
		    report write_width_b
		    severity warning;
		wrwerr_b <= '1'; 
		wrwerr_b <= transport '0' AFTER 1 ns;
	    end if;
	    write_ev := NOW;
	end if;
    end process;

    -- Generate the ATD for A
    process (addr_a)
    begin
    	if (cfgbits(4) = '0') then
	    atd_a <= '1';
	    atd_a <= transport '0' after xcmAddrTransDetect;
	end if;
    end process;

    -- Generate the ATD for B
    process (addr_b)
    begin
    	if (cfgbits(17) = '0') then
	    atd_b <= '1';
	    atd_b <= transport '0' after xcmAddrTransDetect;
	end if;
    end process;

    -- check async data to write setup _a
    ddwe_a <= we_a after asyncDataSetup;
    process (din_a, ddwe_a)
    	variable dataev : time := 0 ns;
    begin
    	if (cfgbits(5) = '0') then
	    if (falling_edge(ddwe_a)) then
		if ((dataev /= 0 ns) AND 
		    ((NOW-dataev) < xcmDinAtWriEnaFallSetup+asyncDataSetup))then
		    assert (false)
			report data2we_setup_a
			severity warning;
		    dwserr_a <= '1'; 
		    dwserr_a <= transport '0' AFTER 1 ns;
		end if;
	    elsif (din_a'event) then
	    	dataev := NOW;
	    end if;
	end if;
    end process;

    -- check async data to write hold _a
    dadin_a <= din_a after asyncDataHold;
    process (dadin_a, we_a)
    	variable writev : time := 0 ns;
    begin
    	if (cfgbits(5) = '0') then
	    if (falling_edge(we_a)) then
	    	writev := NOW;
	    elsif (dadin_a'event) then
		if ((writev /= 0 ns) AND
		    ((NOW-writev) < xcmDinAtWriEnaFallHold+asyncDataHold)) then
		    assert (false)
			report data2we_hold_a
			severity warning;
		    dwherr_a <= '1'; 
		    dwherr_a <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check async data to write setup _b
    ddwe_b <= we_b after asyncDataSetup;
    process (din_b, ddwe_b)
    	variable dataev : time := 0 ns;
    begin
    	if (cfgbits(18) = '0') then
	    if (falling_edge(ddwe_b)) then
		if ((dataev /= 0 ns) AND 
		    ((NOW-dataev) < xcmDinAtWriEnaFallSetup+asyncDataSetup))then
		    assert (false)
			report data2we_setup_b
			severity warning;
		    dwserr_b <= '1'; 
		    dwserr_b <= transport '0' AFTER 1 ns;
		end if;
	    elsif (din_b'event) then
	    	dataev := NOW;
	    end if;
	end if;
    end process;

    -- check async data to write hold _b
    dadin_b <= din_b after asyncDataHold;
    process (dadin_b, we_b)
    	variable writev : time := 0 ns;
    begin
    	if (cfgbits(18) = '0') then
	    if (falling_edge(we_b)) then
	    	writev := NOW;
	    elsif (dadin_b'event) then
		if ((writev /= 0 ns) AND
		    ((NOW-writev) < xcmDinAtWriEnaFallHold+asyncDataHold)) then
		    assert (false)
			report data2we_hold_b
			severity warning;
		    dwherr_b <= '1'; 
		    dwherr_b <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check async address to write rising setup _a
    dawer_a <= we_a after asyncAddrSetupR;
    process (addr_a, dawer_a)
    	variable addrev : time := 0 ns;
    begin
    	if (cfgbits(4) = '0') then
	    if (rising_edge(dawer_a)) then
		if ((addrev /= 0 ns) AND 
		((NOW-addrev) < xcmAddrAtWriEnaRiseSetup+asyncAddrSetupR)) then
		    assert (false)
			report addr2westart_setup_a
			severity warning;
		    awserr_a <= '1'; 
		    awserr_a <= transport '0' AFTER 1 ns;
		end if;
	    elsif (addr_a'event) then
	    	addrev := NOW;
	    end if;
	end if;
    end process;

    -- check async address to write falling setup _a
    dawef_a <= we_a after asyncAddrSetupF;
    process (addr_a, dawef_a)
    	variable addrev : time := 0 ns;
    begin
    	if (cfgbits(4) = '0') then
	    if (falling_edge(dawef_a)) then
		if ((addrev /= 0 ns) AND 
		((NOW-addrev) < xcmAddrAtWriEnaFallSetup+asyncAddrSetupF)) then
		    assert (false)
			report addr2weend_setup_a
			severity warning;
		    awserr_a <= '1'; 
		    awserr_a <= transport '0' AFTER 1 ns;
		end if;
	    elsif (addr_a'event) then
	    	addrev := NOW;
	    end if;
	end if;
    end process;

    -- check async address to write hold _a
    daaddr_a <= addr_a after asyncAddrHold;
    process (daaddr_a, we_a)
    	variable writev : time := 0 ns;
    begin
    	if (cfgbits(4) = '0') then
	    if (falling_edge(we_a)) then
	    	writev := NOW;
	    elsif (daaddr_a'event) then
		if ((writev /= 0 ns) AND
		    ((NOW-writev) < xcmAddrAtWriEnaFallHold+asyncAddrHold)) then
		    assert (false)
			report addr2we_hold_a
			severity warning;
		    awherr_a <= '1'; 
		    awherr_a <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check async address to write rising setup _b
    dawer_b <= we_b after asyncAddrSetupR;
    process (addr_b, dawer_b)
    	variable addrev : time := 0 ns;
    begin
    	if (cfgbits(17) = '0') then
	    if (rising_edge(dawer_b)) then
		if ((addrev /= 0 ns) AND 
		((NOW-addrev) < xcmAddrAtWriEnaRiseSetup+asyncAddrSetupR)) then
		    assert (false)
			report addr2westart_setup_b
			severity warning;
		    awserr_b <= '1'; 
		    awserr_b <= transport '0' AFTER 1 ns;
		end if;
	    elsif (addr_b'event) then
	    	addrev := NOW;
	    end if;
	end if;
    end process;

    -- check async address to write falling setup _b
    dawef_b <= we_b after asyncAddrSetupF;
    process (addr_b, dawef_b)
    	variable addrev : time := 0 ns;
    begin
    	if (cfgbits(17) = '0') then
	    if (falling_edge(dawef_b)) then
		if ((addrev /= 0 ns) AND 
		((NOW-addrev) < xcmAddrAtWriEnaFallSetup+asyncAddrSetupF)) then
		    assert (false)
			report addr2weend_setup_b
			severity warning;
		    awserr_b <= '1'; 
		    awserr_b <= transport '0' AFTER 1 ns;
		end if;
	    elsif (addr_b'event) then
	    	addrev := NOW;
	    end if;
	end if;
    end process;

    -- check async address to write hold _b
    daaddr_b <= addr_b after asyncAddrHold;
    process (daaddr_b, we_b)
    	variable writev : time := 0 ns;
    begin
    	if (cfgbits(17) = '0') then
	    if (falling_edge(we_b)) then
	    	writev := NOW;
	    elsif (daaddr_b'event) then
		if ((writev /= 0 ns) AND
		    ((NOW-writev) < xcmAddrAtWriEnaFallHold+asyncAddrHold)) then
		    assert (false)
			report addr2we_hold_b
			severity warning;
		    awherr_b <= '1'; 
		    awherr_b <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check sync oclk_a cycle, high and low times.
    process (oclk_a)
	variable clkhi, clklo : time := 0 ns;
    begin
	if (cfgbits(4) = '1') then
	    if (oclk_a = '0') then
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcmDoutRegCkWthHi)) then
		    assert (false)
			report outputclock_high_a
			severity warning;
		    oclkerr_a <= '1'; 
		    oclkerr_a <= transport '0' AFTER 1 ns;
		end if;
		clklo := NOW;
	    elsif (oclk_a = '1') then
		if NOT ((clklo = 0 ns) OR ((NOW-clklo) >= xcmDoutRegCkWthLo)) then
		   assert (false)
			report outputclock_low_a
			severity warning;
		    oclkerr_a <= '1'; 
		    oclkerr_a <= transport '0' AFTER 1 ns;
		end if;
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcmDoutRegCkWthCy)) then
		    assert (false)
			report outputclock_width_a
			severity warning;
		    oclkerr_a <= '1'; 
		    oclkerr_a <= transport '0' AFTER 1 ns;
		end if;
		clkhi := NOW;
	    end if;
	end if;
    end process;

    -- check sync oclk_b cycle, high and low times.
    process (oclk_b)
	variable clkhi, clklo : time := 0 ns;
    begin
	if (cfgbits(17) = '1') then
	    if (oclk_b = '0') then
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcmDoutRegCkWthHi)) then
		    assert (false)
			report outputclock_high_b
			severity warning;
		    oclkerr_b <= '1'; 
		    oclkerr_b <= transport '0' AFTER 1 ns;
		end if;
		clklo := NOW;
	    elsif (oclk_b = '1') then
		if NOT ((clklo = 0 ns) OR ((NOW-clklo) >= xcmDoutRegCkWthLo)) then
		   assert (false)
			report outputclock_low_b
			severity warning;
		    oclkerr_b <= '1'; 
		    oclkerr_b <= transport '0' AFTER 1 ns;
		end if;
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcmDoutRegCkWthCy)) then
		    assert (false)
			report outputclock_width_b
			severity warning;
		    oclkerr_b <= '1'; 
		    oclkerr_b <= transport '0' AFTER 1 ns;
		end if;
		clkhi := NOW;
	    end if;
	end if;
    end process;

    -- check output register A reset recovery and reset width
    process (reset_a, oclk_a)
	variable clrlastev, clklastev, clrhi : time := 0 ns;
    begin
    	if (cfgbits(6) = '1') then
	    if (reset_a'event) then
		clrlastev := NOW;
		if (reset_a = '1') then
		    clrhi := NOW;
		else
		    if NOT ((clrhi = 0 ns) OR ((NOW-clrhi) >= xcmDoutRegReWthHi)) then
			assert (false)
			    report reset_width_a
			    severity warning;
			rsterr_a <= '1'; 
			rsterr_a <= transport '0' AFTER 1 ns;
		    end if;
		end if;
	    end if;
	    if ((reset_a = '0') AND rising_edge(oclk_a)) then
		if NOT((clrlastev = 0 ns) OR ((NOW-clrlastev) >= xcmDoutRegReRcr)) then
		    assert (false)
			report outreg_rcvry_a
			severity warning;
		    rcverr_a <= '1';
		    rcverr_a <= transport '0' AFTER 1 ns;
		end if;
		clklastev := NOW;
	    end if;
	end if;
    end process;

    -- check output register B reset recovery and reset width
    process (reset_b, oclk_b)
	variable clrlastev, clklastev, clrhi : time := 0 ns;
    begin
    	if (cfgbits(19) = '1') then
	    if (reset_b'event) then
		clrlastev := NOW;
		if (reset_b = '1') then
		    clrhi := NOW;
		else
		    if NOT ((clrhi = 0 ns) OR ((NOW-clrhi) >= xcmDoutRegReWthHi)) then
			assert (false)
			    report reset_width_b
			    severity warning;
			rsterr_b <= '1'; 
			rsterr_b <= transport '0' AFTER 1 ns;
		    end if;
		end if;
	    end if;
	    if ((reset_b = '0') AND rising_edge(oclk_b)) then
		if NOT((clrlastev = 0 ns) OR ((NOW-clrlastev) >= xcmDoutRegReRcr)) then
		    assert (false)
			report outreg_rcvry_b
			severity warning;
		    rcverr_b <= '1';
		    rcverr_b <= transport '0' AFTER 1 ns;
		end if;
		clklastev := NOW;
	    end if;
	end if;
    end process;

    -- check sync data to oclk setup _a
    doclk_a <= oclk_a after dataOutSetup;
    process (cdout_a, doclk_a)
    	variable dataev : time := 0 ns;
    begin
    	if (cfgbits(6) = '1') then
	    if ((reset_a = '0') AND rising_edge(doclk_a)) then
		if ((dataev /= 0 ns) AND 
			((NOW-dataev) < xcmDoutRegSetup+dataOutSetup)) then
		    assert (false)
			report data2oclk_setup_a
			severity warning;
		    oserr_a <= '1'; 
		    oserr_a <= transport '0' AFTER 1 ns;
		end if;
	    elsif (cdout_a'event) then
	    	dataev := NOW;
	    end if;
	end if;
    end process;

    -- check sync data to oclk hold _a
    dcdout_a <= cdout_a after dataOutHold;
    process (dcdout_a, oclk_a)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(6) = '1') then
	    if ((reset_a = '0') AND rising_edge(oclk_a)) then
	    	clckev := NOW;
	    elsif (dcdout_a'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcmDoutRegHold+dataOutHold)) then
		    assert (false)
			report data2oclk_hold_a
			severity warning;
		    oherr_a <= '1'; 
		    oherr_a <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check sync data to oclk setup _b
    doclk_b <= oclk_b after dataOutSetup;
    process (cdout_b, doclk_b)
    	variable dataev : time := 0 ns;
    begin
    	if (cfgbits(19) = '1') then
	    if ((reset_b = '0') AND rising_edge(doclk_b)) then
		if ((dataev /= 0 ns) AND 
			((NOW-dataev) < xcmDoutRegSetup+dataOutSetup)) then
		    assert (false)
			report data2oclk_setup_b
			severity warning;
		    oserr_b <= '1'; 
		    oserr_b <= transport '0' AFTER 1 ns;
		end if;
	    elsif (cdout_b'event) then
	    	dataev := NOW;
	    end if;
	end if;
    end process;

    -- check sync data to oclk hold _b
    dcdout_b <= cdout_b after dataOutHold;
    process (dcdout_b, oclk_b)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(19) = '1') then
	    if ((reset_b = '0') AND rising_edge(oclk_b)) then
	    	clckev := NOW;
	    elsif (dcdout_b'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcmDoutRegHold+dataOutHold)) then
		    assert (false)
			report data2oclk_hold_b
			severity warning;
		    oherr_b <= '1'; 
		    oherr_b <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- Simulate functionality
    process (iclk_a, addr_a, we_a, atd_a)
	variable wreg : std_logic;
    begin
	if (cfgbits(4) = '1') then
	-- Synchronous Address/Write port A
	    if (rising_edge(iclk_a)) then
		atmp_a <= addr_a;
	    end if;
	    wtmp_a <= we_a AND iclk_a;
	else
	-- Asynchronous Address/Write port A
	    if(falling_edge(atd_a) OR (xcmAddrTransDetect <= 0 ns)) then
		atmp_a <= addr_a;
	    end if;
	    wtmp_a <= we_a;
	end if;
    end process;

    process (iclk_b, addr_b, we_b, atd_b)
	variable wreg : std_logic;
    begin
	if (cfgbits(17) = '1') then
	-- Synchronous Address/Write port B
	    if (rising_edge(iclk_b)) then
		atmp_b <= addr_b;
	    end if;
	    wtmp_b <= we_b AND iclk_b;
	else
	-- Asynchronous Address/Write port B
	    if(falling_edge(atd_b) OR (xcmAddrTransDetect <= 0 ns)) then
		atmp_b <= addr_b;
	    end if;
	    wtmp_b <= we_b;
	end if;
    end process;

    process (iclk_a, din_a)
    begin
	if (cfgbits(5) = '1') then
	-- Synchronous Data port A
	    if (rising_edge(iclk_a)) then
		dtin_a <= din_a;
	    end if;
	else
	-- Asynchronous Data port A
	    dtin_a <= din_a;
	end if;
    end process;

    process (iclk_b, din_b)
    begin
	if (cfgbits(18) = '1') then
	-- Synchronous Data port B
	    if (rising_edge(iclk_b)) then
		dtin_b <= din_b;
	    end if;
	else
	-- Asynchronous Data port B
	    dtin_b <= din_b;
	end if;
    end process;

    -- simulate the dual port operations
    process (dtin_a, atmp_a, wtmp_a, iclk_a, dtin_b, atmp_b, wtmp_b, iclk_b)
	variable mem	: chmem := memdata;
	variable vecta	: natural;
	variable vectb	: natural;
	variable btsela	: natural;
	variable btselb	: natural;
	variable dataa	: std_logic_vector(7 downto 0);
	variable datab	: std_logic_vector(7 downto 0);
    begin

	vecta := to_integer(atmp_a(11 downto 3));
	vectb := to_integer(atmp_b(11 downto 3));

	-- busy is asserted whenever the two address are the same
	-- the user is responsible to arbitrate based on that information
	if (vecta = vectb) then
	    addr_matchb <= '0';
	else
	    addr_matchb <= '1';
	end if;

	-- Write the array from port A
	if (wtmp_a = '1') then
	    case cfgbits(3 downto 2) is
		when "00" =>
		    mem(vecta) := dtin_a;
		when "01" =>
		    btsela := to_integer(atmp_a(2 downto 2));
		    mem(vecta)(btsela*4+3 downto btsela*4)
					:= dtin_a(3 downto 0);
		when "10" =>
		    btsela := to_integer(atmp_a(2 downto 1));
		    mem(vecta)(btsela*2+1 downto btsela*2)
					:= dtin_a(1 downto 0);
		when "11" =>
		    btsela := to_integer(atmp_a(2 downto 0));
		    mem(vecta)(btsela) := dtin_a(0);
	    end case;
	end if;

	-- Write the array from port B
	-- This arbitration may be removed, the user should arbitrate.
	if (((wtmp_b = '1') AND (vecta /= vectb)) OR
	    ((wtmp_b = '1') AND (vecta  = vectb) AND (wtmp_a /= '1'))) then
	    case cfgbits(3 downto 2) is
		when "00" =>
		    mem(vectb) := dtin_b;
		when "01" =>
		    btselb := to_integer(atmp_b( 2 downto 2));
		    mem(vectb)(btselb*4+3 downto btselb*4)
					:= dtin_b(3 downto 0);
		when "10" =>
		    btselb := to_integer(atmp_b(2 downto 1));
		    mem(vectb)(btselb*2+1 downto btselb*2)
					:= dtin_b(1 downto 0);
		when "11" =>
		    btselb := to_integer(atmp_b(2 downto 0));
		    mem(vectb)(btselb) := dtin_b(0);
	    end case;
	end if;

	-- Read the array from port A
	dataa := (others => '0');
	case cfgbits(3 downto 2) is
	    when "00" =>
		dataa := mem(vecta);
	    when "01" =>
		btsela := to_integer(atmp_a(2 downto 2));
		dataa(3 downto 0) := mem(vecta)(btsela*4+3 downto btsela*4);
	    when "10" =>
		btsela := to_integer(atmp_a(2 downto 1));
		dataa(1 downto 0) := mem(vecta)(btsela*2+1 downto btsela*2);
	    when "11" =>
		btsela := to_integer(atmp_a(2 downto 0));
	    	dataa(0) := mem(vecta)(btsela);
	end case;

	-- Read the array from port B
	datab := (others => '0');
	case cfgbits(3 downto 2) is
	    when "00" =>
		datab := mem(vectb);
	    when "01" =>
		btselb := to_integer(atmp_b(2 downto 2));
		datab(3 downto 0) := mem(vectb)(btselb*4+3 downto btselb*4);
	    when "10" =>
		btselb := to_integer(atmp_b(2 downto 1));
		datab(1 downto 0) := mem(vectb)(btselb*2+1 downto btselb*2);
	    when "11" =>
		btselb := to_integer(atmp_b(2 downto 0));
	    	datab(0) := mem(vectb)(btselb);
	end case;

	if (cfgbits(4) = '0') then
	-- async delays port A
	    if (atmp_a'event) then
		dtout_a <= dataa after (xcmAddr2DoutRegD - xcmAddrTransDetect);
	    elsif ((wtmp_a'event) AND (wtmp_a = '1')) then
		dtout_a <= dataa after xcmWriEna2DoutRegD;
	    elsif ((dtin_a'event) AND (wtmp_a = '1')) then
		dtout_a <= dataa after xcmDin2DoutRegD;
	    else
		dtout_a <= dataa;
	    end if;
	else
	-- sync delays port A
	    if (rising_edge(iclk_a)) then
		dtout_a <= dataa after xcmClkIn2DoutRegD;
	    else
		dtout_a <= dataa;
	    end if;
	end if;

	if (cfgbits(17) = '0') then
	-- async delays port B
	    if (atmp_b'event) then
		dtout_b <= datab after (xcmAddr2DoutRegD - xcmAddrTransDetect);
	    elsif ((wtmp_b'event) AND (wtmp_b = '1')) then
		dtout_b <= datab after xcmWriEna2DoutRegD;
	    elsif ((dtin_b'event) AND (wtmp_b = '1')) then
		dtout_b <= datab after xcmDin2DoutRegD;
	    else
		dtout_b <= datab;
	    end if;
	else
	-- sync delays port B
	    if (rising_edge(iclk_b)) then
		dtout_b <= datab after xcmClkIn2DoutRegD;
	    else
		dtout_b <= datab;
	    end if;
	end if;

    end process;

    -- condition the A ouput with errors that may have happened
    process (dtout_a,iclkerr_a,aserr_a,aherr_a,wserr_a,wherr_a,dserr_a,dherr_a,
	     wrwerr_a,rcycerr_a,wcycerr_a,dwserr_a,dwherr_a,awserr_a,awherr_a)
    begin
	if (   iclkerr_a='1' OR   aserr_a='1' OR  aherr_a='1' OR  wserr_a='1'
	    OR   wherr_a='1' OR   dserr_a='1' OR  dherr_a='1' OR wrwerr_a='1'
	    OR rcycerr_a='1' OR wcycerr_a='1' OR dwserr_a='1' OR dwherr_a='1'
	    OR  awserr_a='1' OR  awherr_a='1') then

	    cdout_a <= (others => 'X');
	else
	    cdout_a <= dtout_a;
	end if;
    end process;

    -- condition the B ouput with errors that may have happened
    process (dtout_b,iclkerr_b,aserr_b,aherr_b,wserr_b,wherr_b,dserr_b,dherr_b,
	     wrwerr_b,rcycerr_b,wcycerr_b,dwserr_b,dwherr_b,awserr_b,awherr_b)
    begin
	if (   iclkerr_b='1' OR   aserr_b='1' OR  aherr_b='1' OR  wserr_b='1'
	    OR   wherr_b='1' OR   dserr_b='1' OR  dherr_b='1' OR wrwerr_b='1'
	    OR rcycerr_b='1' OR wcycerr_b='1' OR dwserr_b='1' OR dwherr_b='1'
	    OR  awserr_b='1' OR  awherr_b='1') then

	    cdout_b <= (others => 'X');
	else
	    cdout_b <= dtout_b;
	end if;
    end process;

    process (reset_a,oclk_a,cdout_a,oclkerr_a,oserr_a,oherr_a,rsterr_a,rcverr_a)
    begin
	if (cfgbits(6) = '1') then
	-- Synchronous Read port A
	    if (reset_a = '1') then
		dout_a <= (others => '0') after xcmReset2Dout;
	    elsif (oclkerr_a = '1' OR  oserr_a = '1' OR oherr_a = '1'
		OR  rsterr_a = '1' OR rcverr_a = '1') then
		dout_a <= (others => 'X');
	    elsif (rising_edge(oclk_a)) then
		dout_a <= cdout_a after xcmClkOut2Dout;
	    end if;
	else
	-- Asynchronous Read port A
	    dout_a <= cdout_a after xcmDoutRegD2Dout;
	end if;
    end process;

    process (reset_b,oclk_b,cdout_b,oclkerr_b,oserr_b,oherr_b,rsterr_b,rcverr_b)
    begin
	if (cfgbits(19) = '1') then
	-- Synchronous Read port B
	    if (reset_b = '1') then
		dout_b <= (others => '0') after xcmReset2Dout;
	    elsif (oclkerr_b = '1' OR  oserr_b = '1' OR oherr_b = '1'
		OR  rsterr_b = '1' OR rcverr_b = '1') then
		dout_b <= (others => 'X');
	    elsif (rising_edge(oclk_b)) then
		dout_b <= cdout_b after xcmClkOut2Dout;
	    end if;
	else
	-- Asynchronous Read port B
	    dout_b <= cdout_b after xcmDoutRegD2Dout;
	end if;
    end process;

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c39kcr is
    generic (
	cfgbits	: Bit_Vector(13 downto 0);
	memdata	: clmem;
	-- asynchronous parameters
	xcrReadAddrWthHi	: time;		-- checked parameters
	xcrWritAddrWthHi	: time;
	xcrWriEnaWthHi		: time;
	xcrAddrAtWriEnaFallSetup: time;
	xcrAddrAtWriEnaRiseSetup: time;
	xcrAddrAtWriEnaFallHold	: time;
	xcrDinAtWriEnaFallSetup	: time;
	xcrDinAtWriEnaFallHold	: time;
	xcrAddr2DoutRegD	: time;		-- applied parameters
	xcrWriEna2DoutRegD	: time;
	xcrDin2DoutRegD		: time;
	xcrDoutRegD2Dout	: time;
	-- synchronous input parameters
	xcrClkInWthCy		: time;		-- checked parameters
	xcrClkInWthHi		: time;
	xcrClkInWthLo		: time;
	xcrAddrAtClkInSetup	: time;
	xcrAddrAtClkInHold	: time;
	xcrWriEnaAtClkInSetup	: time;
	xcrWriEnaAtClkInHold	: time;
	xcrDinAtClkInSetup	: time;
	xcrDinAtClkInHold	: time;
	xcrClkIn2DoutRegD	: time;		-- applied parameters
	-- synchronous output parameters
	xcrDoutRegCkWthHi	: time;		-- checked parameters
	xcrDoutRegCkWthLo	: time;
	xcrDoutRegCkWthCy	: time;
	xcrDoutRegSetup		: time;
	xcrDoutRegHold		: time;
	xcrDoutRegReRcr		: time;
	xcrDoutRegReWthHi	: time;
	xcrClkOut2Dout		: time;		-- applied parameters
	xcrReset2Dout		: time;
	xcrAddrTransDetect	: time);
    port (
	din	: in	std_logic_vector( 7 downto 0);
	addr	: in	std_logic_vector(12 downto 0);
	we	: in	std_logic;
	iclk	: in	std_logic;
	oclk	: in	std_logic;
	reset	: in	std_logic;
	dout	: out	std_logic_vector( 7 downto 0));
end c39kcr;

architecture sim of c39kcr is

    signal atmp		: std_logic_vector(12 downto 0);
    signal dtin		: std_logic_vector( 7 downto 0);
    signal dtout	: std_logic_vector( 7 downto 0);
    signal cdout	: std_logic_vector( 7 downto 0);
    signal wtmp		: std_logic;
    signal atd		: std_logic;

    -- Signals for use with negative setup and hold checks
    signal dsaddr	:std_logic_vector(12 downto 0);
    signal daiclk	:std_logic;
    signal dswe		:std_logic;
    signal dwiclk	:std_logic;
    signal dsdin	:std_logic_vector( 7 downto 0);
    signal ddiclk	:std_logic;
    signal dcdout	:std_logic_vector( 7 downto 0);
    signal doclk	:std_logic;
    signal dadin	:std_logic_vector( 7 downto 0);
    signal ddwe		:std_logic;
    signal daaddr	:std_logic_vector(12 downto 0);
    signal dawer	:std_logic;
    signal dawef	:std_logic;

    -- Constants for use with negative setup and hold checks
    constant syncAddrSetup	: time := timeAdjust(xcrAddrAtClkInSetup);
    constant syncAddrHold	: time := timeAdjust(xcrAddrAtClkInHold);
    constant syncWESetup	: time := timeAdjust(xcrWriEnaAtClkInSetup);
    constant syncWEHold		: time := timeAdjust(xcrWriEnaAtClkInHold);
    constant syncDataSetup	: time := timeAdjust(xcrDinAtClkInSetup);
    constant syncDataHold	: time := timeAdjust(xcrDinAtClkInHold);
    constant dataOutSetup	: time := timeAdjust(xcrDoutRegSetup);
    constant dataOutHold	: time := timeAdjust(xcrDoutRegHold);
    constant asyncAddrSetupF	: time := timeAdjust(xcrAddrAtWriEnaFallSetup);
    constant asyncAddrSetupR	: time := timeAdjust(xcrAddrAtWriEnaRiseSetup);
    constant asyncAddrHold	: time := timeAdjust(xcrAddrAtWriEnaFallHold);
    constant asyncDataSetup	: time := timeAdjust(xcrDinAtWriEnaFallSetup);
    constant asyncDataHold	: time := timeAdjust(xcrDinAtWriEnaFallHold);

    constant unk	: string := " Setting output unknown.";

    signal iclkerr	: std_logic;
    constant iclk_high		: string :=
    "Input clock high width violation:"		& unk;
    constant iclk_low		: string :=
    "Input clock low width violation:"		& unk;
    constant iclk_cycle		: string :=
    "Input clock cycle width violation:"	& unk;

    signal aserr	: std_logic;
    constant address_setup	: string :=
    "Address to input clock setup violation:"	& unk;

    signal aherr	: std_logic;
    constant address_hold	: string :=
    "Input clock to address hold violation:"	& unk;

    signal wserr	: std_logic;
    constant write_setup	: string :=
    "Write to input clock setup violation:"	& unk;

    signal wherr	: std_logic;
    constant write_hold		: string :=
    "Input clock to write hold violation:"	& unk;

    signal dserr	: std_logic;
    constant data_setup		: string :=
    "Data to input clock setup violation:"	& unk;

    signal dherr	: std_logic;
    constant data_hold		: string :=
    "Input clock to data hold violation:"	& unk;

    signal oclkerr	: std_logic;
    constant oclk_high		: string :=
    "Output clock high width violation:"	& unk;
    constant oclk_low		: string :=
    "Output clock low width violation:"		& unk;
    constant oclk_cycle		: string :=
    "Output clock cycle width violation:"	& unk;

    signal rcverr	: std_logic;
    constant outreg_rcvry	: string :=
    "Output register reset recovery violation:"	& unk;

    signal rsterr	: std_logic;
    constant reset_width	: string :=
    "Reset width violation:"			& unk;

    signal oserr	: std_logic;
    constant data2oclk_setup	: string :=
    "Data to output clock setup violation:"	& unk;

    signal oherr	: std_logic;
    constant data2oclk_hold	: string :=
    "Output clock to data hold violation:"	& unk;

    signal wrwerr	: std_logic;
    constant write_width	: string :=
    "Minimum write width violation:"		& unk;

    signal rcycerr	: std_logic;
    constant read_cycle		: string :=
    "Minimum read cycle violation:"		& unk;

    signal wcycerr	: std_logic;
    constant write_cycle	: string :=
    "Minimum write cycle violation:"		& unk;

    signal dwserr	: std_logic;
    constant data2we_setup	: string :=
    "Data to we setup violation:"		& unk;

    signal dwherr	: std_logic;
    constant data2we_hold	: string :=
    "We to data hold violation:"		& unk;

    signal awserr	: std_logic;
    constant addr2westart_setup	: string :=
    "Address to we start setup violation:"	& unk;
    constant addr2weend_setup	: string :=
    "Address to we end setup violation:"	& unk;

    signal awherr	: std_logic;
    constant addr2we_hold	: string :=
    "We to address hold violation:"		& unk;

begin

    -- check iclk cycle, high and low times.
    process (iclk)
	variable clkhi, clklo : time := 0 ns;
    begin
	if ((cfgbits(2) = '1') OR (cfgbits(3) = '1')) then
	    if (iclk = '0') then
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcrClkInWthHi)) then
		    assert (false)
			report iclk_high
			severity warning;
		    iclkerr <= '1';
		    iclkerr <= transport '0' AFTER 1 ns;
		end if;
		clklo := NOW;
	    elsif (iclk = '1') then
		if NOT ((clklo = 0 ns) OR ((NOW-clklo) >= xcrClkInWthLo)) then
		   assert (false)
			report iclk_low
			severity warning;
		    iclkerr <= '1';
		    iclkerr <= transport '0' AFTER 1 ns;
		end if;
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcrClkInWthCy)) then
		    assert (false)
			report iclk_cycle
			severity warning;
		    iclkerr <= '1';
		    iclkerr <= transport '0' AFTER 1 ns;
		end if;
		clkhi := NOW;
	    end if;
	end if;
    end process;

    -- check sync address setup
    daiclk <= iclk after syncAddrSetup;
    process (addr, daiclk)
    	variable addrev : time := 0 ns;
    begin
    	if (cfgbits(2) = '1') then
	    if (rising_edge(daiclk)) then
		if ((addrev /= 0 ns) AND 
			((NOW-addrev) < xcrAddrAtClkInSetup+syncAddrSetup)) then
		    assert (false)
			report address_setup
			severity warning;
		    aserr <= '1'; 
		    aserr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (addr'event) then
	    	addrev := NOW;
	    end if;
	end if;
    end process;

    -- check sync address hold
    dsaddr <= addr after syncAddrHold;
    process (dsaddr, iclk)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(2) = '1') then
	    if (rising_edge(iclk)) then
	    	clckev := NOW;
	    elsif (dsaddr'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcrAddrAtClkInHold+syncAddrHold)) then
		    assert (false)
			report address_hold
			severity warning;
		    aherr <= '1'; 
		    aherr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check sync write setup
    dwiclk <= iclk after syncWESetup;
    process (we, dwiclk)
    	variable writev : time := 0 ns;
    begin
    	if (cfgbits(2) = '1') then
	    if (rising_edge(dwiclk)) then
		if ((writev /= 0 ns) AND 
			((NOW-writev) < xcrWriEnaAtClkInSetup+syncWESetup)) then
		    assert (false)
			report write_setup
			severity warning;
		    wserr <= '1'; 
		    wserr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (we'event) then
	    	writev := NOW;
	    end if;
	end if;
    end process;

    -- check sync write hold
    dswe <= we after syncWEHold;
    process (dswe, iclk)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(2) = '1') then
	    if (rising_edge(iclk)) then
	    	clckev := NOW;
	    elsif (dswe'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcrWriEnaAtClkInHold+syncWEHold)) then
		    assert (false)
			report write_hold
			severity warning;
		    wherr <= '1'; 
		    wherr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check sync data setup
    ddiclk <= iclk after syncDataSetup;
    process (din, ddiclk)
    	variable dataev : time := 0 ns;
    begin
    	if (cfgbits(3) = '1') then
	    if (rising_edge(ddiclk)) then
		if ((dataev /= 0 ns) AND 
			((NOW-dataev) < xcrDinAtClkInSetup+syncDataSetup)) then
		    assert (false)
			report data_setup
			severity warning;
		    dserr <= '1'; 
		    dserr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (din'event) then
	    	dataev := NOW;
	    end if;
	end if;
    end process;

    -- check sync data hold
    dsdin <= din after syncDataHold;
    process (dsdin, iclk)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(3) = '1') then
	    if (rising_edge(iclk)) then
	    	clckev := NOW;
	    elsif (dsdin'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcrDinAtClkInHold+syncDataHold)) then
		    assert (false)
			report data_hold
			severity warning;
		    dherr <= '1'; 
		    dherr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check oclk cycle, high and low times.
    process (oclk)
	variable clkhi, clklo : time := 0 ns;
    begin
	if (cfgbits(8) = '1') then
	    if (oclk = '0') then
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcrDoutRegCkWthHi)) then
		    assert (false)
			report oclk_high
			severity warning;
		    oclkerr <= '1';
		    oclkerr <= transport '0' AFTER 1 ns;
		end if;
		clklo := NOW;
	    elsif (oclk = '1') then
		if NOT ((clklo = 0 ns) OR ((NOW-clklo) >= xcrDoutRegCkWthLo)) then
		   assert (false)
			report oclk_low
			severity warning;
		    oclkerr <= '1';
		    oclkerr <= transport '0' AFTER 1 ns;
		end if;
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xcrDoutRegCkWthCy)) then
		    assert (false)
			report oclk_cycle
			severity warning;
		    oclkerr <= '1';
		    oclkerr <= transport '0' AFTER 1 ns;
		end if;
		clkhi := NOW;
	    end if;
	end if;
    end process;

        -- check output register reset recovery and reset width
    process (reset, oclk)
	variable clrlastev, clklastev, clrhi : time := 0 ns;
    begin
    	if (cfgbits(8) = '1') then
	    if (reset'event) then
		clrlastev := NOW;
		if (reset = '1') then
		    clrhi := NOW;
		else
		    if NOT ((clrhi = 0 ns) OR ((NOW-clrhi) >= xcrDoutRegReWthHi)) then
			assert (false)
			    report reset_width
			    severity warning;
			rsterr <= '1'; 
			rsterr <= transport '0' AFTER 1 ns;
		    end if;
		end if;
	    end if;
	    if ((reset = '0') AND rising_edge(oclk)) then
		if NOT((clrlastev = 0 ns) OR ((NOW-clrlastev) >= xcrDoutRegReRcr)) then
		    assert (false)
			report outreg_rcvry
			severity warning;
		    rcverr <= '1';
		    rcverr <= transport '0' AFTER 1 ns;
		end if;
		clklastev := NOW;
	    end if;
	end if;
    end process;

    -- check sync data to oclk setup
    doclk <= oclk after dataOutSetup;
    process (cdout, doclk)
    	variable dataev : time := 0 ns;
    begin
    	if (cfgbits(8) = '1') then
	    if ((reset = '0') AND rising_edge(doclk)) then
		if ((dataev /= 0 ns) AND 
			((NOW-dataev) < xcrDoutRegSetup+dataOutSetup)) then
		    assert (false)
			report data2oclk_setup
			severity warning;
		    oserr <= '1'; 
		    oserr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (cdout'event) then
	    	dataev := NOW;
	    end if;
	end if;
    end process;

    -- check sync data to oclk hold
    dcdout <= cdout after dataOutHold;
    process (dcdout, oclk)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(8) = '1') then
	    if ((reset = '0') AND rising_edge(oclk)) then
	    	clckev := NOW;
	    elsif (dcdout'event) then
		if ((clckev /= 0 ns) AND
			((NOW-clckev) < xcrDoutRegHold+dataOutHold)) then
		    assert (false)
			report data2oclk_hold
			severity warning;
		    oherr <= '1'; 
		    oherr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check async write minimum valid
    process (we)
	variable write_ev : time := 0 ns;
    begin
	if ((cfgbits(2) = '0') AND (we = '0')) then
	    if NOT ((write_ev = 0 ns) OR ((NOW - write_ev) >= xcrWriEnaWthHi)) then
		assert (false)
		    report write_width
		    severity warning;
		wrwerr <= '1';
		wrwerr <= transport '0' AFTER 1 ns;
	    end if;
	    write_ev := NOW;
	end if;
    end process;

    -- Generate the ATD
    process (addr)
    begin
    	if (cfgbits(2) = '0') then
	    atd <= '1';
	    atd <= transport '0' after xcrAddrTransDetect;
	end if;
    end process;

    -- check async data to write setup
    ddwe <= we after asyncDataSetup;
    process (din, ddwe)
    	variable dataev : time := 0 ns;
    begin
    	if (cfgbits(3) = '0') then
	    if (falling_edge(ddwe)) then
		if ((dataev /= 0 ns) AND 
		    ((NOW-dataev) < xcrDinAtWriEnaFallSetup+asyncDataSetup))then
		    assert (false)
			report data2we_setup
			severity warning;
		    dwserr <= '1'; 
		    dwserr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (din'event) then
	    	dataev := NOW;
	    end if;
	end if;
    end process;

    -- check async data to write hold
    dadin <= din after asyncDataHold;
    process (dadin, we)
    	variable writev : time := 0 ns;
    begin
    	if (cfgbits(3) = '0') then
	    if (falling_edge(we)) then
	    	writev := NOW;
	    elsif (dadin'event) then
		if ((writev /= 0 ns) AND
		    ((NOW-writev) < xcrDinAtWriEnaFallHold+asyncDataHold)) then
		    assert (false)
			report data2we_hold
			severity warning;
		    dwherr <= '1'; 
		    dwherr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check async address to write rising setup
    dawer <= we after asyncAddrSetupR;
    process (addr, dawer)
    	variable addrev : time := 0 ns;
    begin
    	if (cfgbits(2) = '0') then
	    if (rising_edge(dawer)) then
		if ((addrev /= 0 ns) AND 
		((NOW-addrev) < xcrAddrAtWriEnaRiseSetup+asyncAddrSetupR)) then
		    assert (false)
			report addr2westart_setup
			severity warning;
		    awserr <= '1'; 
		    awserr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (addr'event) then
	    	addrev := NOW;
	    end if;
	end if;
    end process;

    -- check async address to write falling setup
    dawef <= we after asyncAddrSetupF;
    process (addr, dawef)
    	variable addrev : time := 0 ns;
    begin
    	if (cfgbits(2) = '0') then
	    if (falling_edge(dawef)) then
		if ((addrev /= 0 ns) AND 
		((NOW-addrev) < xcrAddrAtWriEnaFallSetup+asyncAddrSetupF)) then
		    assert (false)
			report addr2weend_setup
			severity warning;
		    awserr <= '1'; 
		    awserr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (addr'event) then
	    	addrev := NOW;
	    end if;
	end if;
    end process;

    -- check async address to write hold
    daaddr <= addr after asyncAddrHold;
    process (daaddr, we)
    	variable writev : time := 0 ns;
    begin
    	if (cfgbits(2) = '0') then
	    if (falling_edge(we)) then
	    	writev := NOW;
	    elsif (daaddr'event) then
		if ((writev /= 0 ns) AND
		    ((NOW-writev) < xcrAddrAtWriEnaFallHold+asyncAddrHold)) then
		    assert (false)
			report addr2we_hold
			severity warning;
		    awherr <= '1'; 
		    awherr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    process (iclk, addr, we, atd)
    begin
	if (cfgbits(2) = '1') then
	-- Synchronous Address/Write
	    if (rising_edge(iclk)) then
		atmp <= addr;
	    end if;
	    wtmp <= we AND iclk;
	else
	-- Asynchronous Address/Write
	    if (falling_edge(atd) OR (xcrAddrTransDetect <= 0 ns)) then
		atmp <= addr;
	    end if;
	    wtmp <= we;
	end if;
    end process;

    process (iclk, din)
    begin
	if (cfgbits(3) = '1') then
	-- Synchronous Data
	    if (rising_edge(iclk)) then
		dtin <= din;
	    end if;
	else
	-- Asynchronous Data
	    dtin <= din;
	end if;
    end process;

    process (dtin, atmp, wtmp, iclk)
	variable mem	: clmem := memdata;
	variable vect	: natural;
	variable btsel	: natural;
	variable data	: std_logic_vector(7 downto 0);
    begin

	vect := to_integer(atmp(12 downto 3));

	-- Write the array
	if (wtmp = '1') then
	    case cfgbits(1 downto 0) is
		when "00" =>
		    mem(vect) := dtin;
		when "01" =>
		    btsel := to_integer(atmp(2 downto 2));
		    mem(vect)(btsel*4+3 downto btsel*4) := dtin(3 downto 0);
		when "10" =>
		    btsel := to_integer(atmp(2 downto 1));
		    mem(vect)(btsel*2+1 downto btsel*2) := dtin(1 downto 0);
		when "11" =>
		    btsel := to_integer(atmp(2 downto 0));
		    mem(vect)(btsel) := dtin(0);
	    end case;
	end if;

	data := (others => '0');

	-- Read the array
	case cfgbits(1 downto 0) is
	    when "00" =>
		data := mem(vect);
	    when "01" =>
		btsel := to_integer(atmp(2 downto 2));
		data(3 downto 0) := mem(vect)(btsel*4+3 downto btsel*4);
	    when "10" =>
		btsel := to_integer(atmp(2 downto 1));
		data(1 downto 0) := mem(vect)(btsel*2+1 downto btsel*2);
	    when "11" =>
		btsel := to_integer(atmp(2 downto 0));
	    	data(0) := mem(vect)(btsel);
	end case;

	if (cfgbits(3) = '0') then
	-- async delays
	    if (atmp'event) then
		-- addresses have already been delayed, so account for it.
		dtout <= data after (xcrAddr2DoutRegD - xcrAddrTransDetect);
	    elsif ((wtmp'event) AND (wtmp = '1')) then
		dtout <= data after xcrWriEna2DoutRegD;
	    elsif ((dtin'event) AND (wtmp = '1')) then
		dtout <= data after xcrDin2DoutRegD;
	    else
		dtout <= data;
	    end if;
	else
	-- sync delays
	    if (rising_edge(iclk)) then
		dtout <= data after xcrClkIn2DoutRegD;
	    else
		dtout <= data;
	    end if;
	end if;

    end process;

    -- condition the data with errors that may have happened
    process(dtout,iclkerr,aserr,aherr,wserr,wherr,dserr,dherr,
	    wrwerr,rcycerr,wcycerr,dwserr,dwherr,awserr,awherr)
    begin
    if (   iclkerr='1' OR   aserr='1' OR  aherr='1' OR  wserr='1'
	OR   wherr='1' OR   dserr='1' OR   dherr='1' OR wrwerr='1'
	OR rcycerr='1' OR wcycerr='1' OR  dwserr='1' OR dwherr='1'
	OR  awserr='1' OR  awherr='1') then
	    cdout <= (others => 'X');
	else
	    cdout <= dtout;
	end if;
    end process;

    process (reset, oclk, cdout, oclkerr, oserr, oherr, rsterr, rcverr)
    begin
	if (cfgbits(8) = '1') then
	-- Synchronous Read
	    if (reset = '1') then
		dout <= (others => '0') after xcrReset2Dout;
	    elsif (oclkerr = '1' OR oserr = '1' OR oherr = '1'
		    OR rsterr = '1' OR rcverr = '1') then
	    	dout <= (others => 'X');
	    elsif (rising_edge(oclk)) then
		dout <= cdout after xcrClkOut2Dout;
	    end if;
	else
	-- Asynchronous Read
	    dout <= cdout after xcrDoutRegD2Dout;
	end if;
    end process;

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c39kio is
    generic (
	cfgbits			: Bit_Vector(35 downto 0);
	xioClockWthHi		: time;		-- Checked parameters
	xioClockWthLo		: time;
	xioClockWthCy		: time;
	xioResetRcr		: time;
	xioResetWthHi		: time;
	xioIoRegSetup		: time;
	xioIoRegHold		: time;
	xioIoRegEnSup		: time;
	xioIoRegEnHld		: time;
	xioOeRegSetup		: time;
	xioOeRegHold		: time;
	xioFromChip2Pin		: time;		-- applied parameters
	xioFromChip2IoRegD	: time;
	xioIoRegCk2Pin		: time;
	xioIoRegRe2Pin		: time;
	xioIoRegRe2ToChip	: time;
	xioOeRegCk2PinEA	: time;
	xioOeRegCk2PinER	: time;
	xioOeRegRe2PinER	: time;
	xioOutEna2PinEA		: time;
	xioOutEna2PinER		: time;
	xioPin2IoRegD		: time;
	xioIoRegCk2ToChip	: time;		-- May be Vert or Hori
	xioPin2ToChip		: time;		-- May be Vert or Hori
	xioAddOslow		: time;
	xioAddEAslow		: time;
	xioAddERslow		: time;
	xioAdd			: time);
    -- xioAdd is the delay added by bus hold and any IO standard.
    port (
	oe	: in	std_logic;
	din	: in	std_logic;
	en	: in	std_logic;
	clk	: in	std_logic;
	clr	: in	std_logic;
	fb	: out	std_logic;
	iop	: inout	std_logic);
end c39kio;

architecture sim of c39kio is

    signal d, qi, qo, q, ena			: std_logic;
    signal iop_01, en_01, oe_01, clr_01		: std_logic;
    signal declk, den, ddclk, dd, doeclk, doe	: std_logic;

    -- Adjust the setup and hold reference times if they are negative.
    constant enSetup	: time := timeAdjust(xioIoRegEnSup);
    constant enHold	: time := timeAdjust(xioIoRegEnHld);
    constant dSetup	: time := timeAdjust(xioIoRegSetup);
    constant dHold	: time := timeAdjust(xioIoRegHold);
    constant oeSetup	: time := timeAdjust(xioOeRegSetup);
    constant oeHold	: time := timeAdjust(xioOeRegHold);

    constant unk	: string := " Setting output unknown.";

    signal clkerr	: std_logic;
    constant clk_high		: string :=
    "Clock high width violation:"		& unk;
    constant clk_low		: string :=
    "Clock low width violation:"		& unk;
    constant clk_cycle		: string :=
    "Clock cycle width violation:"		& unk;

    signal clrerr	: std_logic;
    constant reset_width	: string :=
    "Reset width violation:"			& unk;

    signal crcverr	: std_logic;
    constant reset_rcvry	: string :=
    "Reset recovery violation:"			& unk;

    signal orstuperr	: std_logic;
    constant odata2clk_setup	: string :=
    "Output Data to clock setup violation:"	& unk;

    signal orholderr	: std_logic;
    constant odata2clk_hold	: string :=
    "Clock to output data hold violation:"	& unk;

    signal enstuperr	: std_logic;
    constant enable2clk_setup	: string :=
    "Enable to clock setup violation:"		& unk;

    signal enholderr	: std_logic;
    constant enable2clk_hold	: string :=
    "Clock to enable hold violation:"		& unk;

    signal oestuperr	: std_logic;
    constant oe2clk_setup	: string :=
    "OE to clock setup violation:"		& unk;

    signal oeholderr	: std_logic;
    constant oe2clk_hold	: string :=
    "Clock to OE hold violation:"		& unk;

begin

    -- don't propogate anything except 1, 0, or X.
    oe_01  <= to_X01(oe);
    iop_01 <= to_X01(iop);
    en_01  <= to_X01(en);
    clr_01 <= to_X01(clr);

    -- check clk cycle, high and low times.
    process (clk)
	variable clkhi, clklo : time := 0 ns;
    begin
	if ((cfgbits(2)= '1') OR (cfgbits(3)= '1') OR (cfgbits(17)= '1')) then
	    if (clk = '0') then
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xioClockWthHi)) then
		    assert (false)
			report clk_high
			severity warning;
		    clkerr <= '1';
		    clkerr <= transport '0' AFTER 1 ns;
		end if;
		clklo := NOW;
	    elsif (clk = '1') then
		if NOT ((clklo = 0 ns) OR ((NOW-clklo) >= xioClockWthLo)) then
		   assert (false)
			report clk_low
			severity warning;
		    clkerr <= '1';
		    clkerr <= transport '0' AFTER 1 ns;
		end if;
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xioClockWthCy)) then
		    assert (false)
			report clk_cycle
			severity warning;
		    clkerr <= '1';
		    clkerr <= transport '0' AFTER 1 ns;
		end if;
		clkhi := NOW;
	    end if;
	end if;
    end process;

    -- check reset recovery and reset width
    process (clr_01, clk)
        variable clrlastev, clklastev, clrhi : time := 0 ns;
    begin
	if ((cfgbits(2)= '1') OR (cfgbits(3)= '1') OR (cfgbits(17)= '1')) then
            if (clr_01'event) then
                clrlastev := NOW;
                if (clr_01 = '1') then
                    clrhi := NOW;
                else
                    if NOT ((clrhi=0 ns) OR ((NOW-clrhi) >= xioResetWthHi)) then
                        assert (false)
                            report reset_width
                            severity warning;
                        clrerr <= '1'; 
                        clrerr <= transport '0' AFTER 1 ns;
                    end if;
                end if;
            end if;
            if ((clr_01 = '0') AND rising_edge(clk)) then
                if NOT((clrlastev=0 ns) OR ((NOW-clrlastev)>=xioResetRcr)) then
                    assert (false)
			report reset_rcvry
                        severity warning;
                    crcverr <= '1';
                    crcverr <= transport '0' AFTER 1 ns;
                end if;
                clklastev := NOW;
            end if;
        end if;
    end process;

    -- Enable setup check
    declk <= clk after enSetup;
    process (en_01, declk)
    	variable enevent : time := 0 ns;
    begin
	if ((cfgbits(2) = '1') OR (cfgbits(3) = '1')) then
	    if ((clr_01 = '0') AND rising_edge(declk)) then
		if ((enevent /= 0 ns) AND
		    ((NOW-enevent) < xioIoRegEnSup-enSetup)) then
		    assert (false)
			report enable2clk_setup
			severity warning;
		    enstuperr <= '1'; 
		    enstuperr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (en_01'event) then
		enevent := NOW;
	    end if;
	end if;
    end process;

    -- Enable hold check
    den <= en_01 after enHold;
    process (den, clk)
    	variable clkevent : time := 0 ns;
    begin
	if ((cfgbits(2) = '1') OR (cfgbits(3) = '1')) then
	    if ((clr_01 = '0') AND rising_edge(clk)) then
		clkevent := NOW;
	    elsif (den'event) then
		if ((clkevent /= 0 ns) AND
		    ((NOW-clkevent) < xioIoRegEnHld-enHold)) then
		    assert (false)
			report enable2clk_hold
			severity warning;
		    enholderr <= '1'; 
		    enholderr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- Data setup check
    ddclk <= clk after dSetup;
    process (d, ddclk)
    	variable dataevent : time := 0 ns;
    begin
	if ((cfgbits(2) = '1') OR (cfgbits(3) = '1')) then
	    if ((clr_01='0') AND (en_01='1') AND rising_edge(ddclk)) then
		if ((dataevent /= 0 ns) AND
		    ((NOW-dataevent) < xioIoRegSetup+dSetup)) then
		    assert (false)
			report odata2clk_setup
			severity warning;
		    orstuperr <= '1'; 
		    orstuperr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (d'event) then
		dataevent := NOW;
	    end if;
	end if;
    end process;

    -- Data hold check
    dd <= d after dHold;
    process (dd, clk)
    	variable clkevent : time := 0 ns;
    begin
	if ((cfgbits(2) = '1') OR (cfgbits(3) = '1')) then
	    if ((clr_01='0') AND (en_01='1') AND rising_edge(clk)) then
		clkevent := NOW;
	    elsif (dd'event) then
		if ((clkevent /= 0 ns) AND
		    ((NOW-clkevent) < xioIoRegHold+dHold)) then
		    assert (false)
			report odata2clk_hold
			severity warning;
		    orholderr <= '1'; 
		    orholderr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- OE setup check
    doeclk <= clk after oeSetup;
    process (oe_01, doeclk)
    	variable oeevent : time := 0 ns;
    begin
    	if (cfgbits(17) = '0') then
	    if ((clr_01 = '0') AND rising_edge(doeclk)) then
		if ((oeevent /= 0 ns) AND 
		    ((NOW-oeevent) < xioOeRegSetup+oeSetup)) then
		    assert (false)
			report oe2clk_setup
			severity warning;
		    oestuperr <= '1'; 
		    oestuperr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (oe_01'event) then
		oeevent := NOW;
	    end if;
	end if;
    end process;

    -- OE hold check
    doe <= oe_01 after oeHold;
    process (doe, clk)
    	variable clkevent : time := 0 ns;
    begin
    	if (cfgbits(17) = '0') then
	    -- setup check
	    if ((clr_01 = '0') AND rising_edge(clk)) then
		clkevent := NOW;
	    elsif (doe'event) then
		if ((clkevent /= 0 ns) AND
		    ((NOW-clkevent) < xioOeRegHold+oeHold)) then
		    assert (false)
			report oe2clk_hold
			severity warning;
		    oeholderr <= '1'; 
		    oeholderr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- generate the "D" input
    with cfgbits(1) select
	d <= din    after xioFromChip2IoRegD when '1',
	     iop_01 after xioPin2IoRegD      when '0';

    -- generate the I/O register
    process (d, clr_01, clk, clkerr, crcverr, clrerr,
		enstuperr, enholderr, orstuperr, orholderr)
    begin
	if ((cfgbits(2) = '1') OR (cfgbits(3) = '1')) then
	    if    (clr_01 = '1') then
		qo <= '0' after xioIoRegRe2Pin;
		qi <= '0' after xioIoRegRe2ToChip;
	    elsif  (clkerr='1' OR crcverr='1' OR clrerr='1' OR enstuperr='1'
		    OR enholderr='1' OR orstuperr='1' OR orholderr='1') then
		qo <= 'X' after xioIoRegCk2Pin;
		qi <= 'X' after xioIoRegCk2ToChip;
	    elsif ((en_01 = '1') AND rising_edge(clk)) then
		qo <=  d  after xioIoRegCk2Pin;
		qi <=  d  after xioIoRegCk2ToChip;
	    end if;
	end if;
    end process;

    -- generate the output select muxes
    process (qo, qi, din, iop_01)
    begin
	case cfgbits(3 downto 2) is
	when "00" =>
	    fb <= iop_01 after xioPin2ToChip;
	    q  <= din    after xioFromChip2Pin;
	when "01" =>
	    fb <= qi;
	    q  <= din    after xioFromChip2Pin;
	when "10" =>
	    fb <= iop_01 after xioPin2ToChip;
	    q  <= qo;
	when "11" =>
	    fb <= qi;
	    q  <= qo;
	end case;
    end process;

    -- generate the output enable register
    process (oe_01, clr_01, clk, oestuperr, oeholderr, clkerr, crcverr, clrerr)
    begin
    	if (cfgbits(17) = '1') then		-- not registered
	    if (cfgbits(6) = '0') then
		if (oe_01 = '1') then
		    ena <= oe_01 after xioOutEna2PinEA;
		else
		    ena <= oe_01 after xioOutEna2PinER;
		end if;
	    else
		if (cfgbits(5) = '0') then
		    if (oe_01 = '1') then
			ena <= oe_01 after xioOutEna2PinEA;
		    else
			ena <= oe_01 after xioOutEna2PinER;
		    end if;
		else
		    if (cfgbits(4) = '1') then
			ena <= '0';
		    else
			ena <= '1';
		    end if;
		end if;
	    end if;
	else					-- registered
	    if (clr_01 = '1') then
		ena <= '0' after xioOeRegRe2PinER;
	    elsif  (clkerr='1' OR crcverr='1' OR clrerr='1'
				    OR oestuperr='1' OR oeholderr='1') then
	    	ena <= 'X' after xioOeRegCk2PinER;
	    elsif (rising_edge(clk)) then
		if (oe_01 = '1') then
		    ena <= oe_01 after xioOeRegCk2PinEA;
		else
		    ena <= oe_01 after xioOeRegCk2PinER;
		end if;
	    end if;
	end if;
    end process;

    -- generate the TRI-STATE buffer
    process (ena, q)
    	variable lastout : std_logic := '0';
    begin
    	if (ena'event) then
	    if (ena = '1') then
		if (cfgbits(0) = '1') then
		    iop <=  q  after xioadd + xioAddEAslow;
		else
		    iop <=  q  after xioAdd;
		end if;
		lastout :=  q;
	    elsif (ena = 'X') then
		if (cfgbits(0) = '1') then
		    iop <= 'X' after xioadd + xioAddERslow;
		else
		    iop <= 'X' after xioAdd;
		end if;
	    	lastout := 'X';
	    else
		if (cfgbits(16) = '0') then
		    if    (lastout = 'X') then
			iop <= 'W' after xioAdd;
		    elsif (lastout = '1') then
			iop <= 'H' after xioAdd;
		    else
			iop <= 'L' after xioAdd;
		    end if;
		else
		    iop <= 'Z' after xioAdd;
		end if;
	    end if;
	else
	    if (ena = '1') then
		if (cfgbits(0) = '1') then
		    iop <= q after xioAdd + xioAddOslow;
		else
		    iop <= q after xioAdd;
		end if;
		lastout := q;
	    elsif (ena = 'X') then
	    	iop <= 'X';
	    	lastout := 'X';
	    else
		if (cfgbits(16) = '0') then
		    if    (lastout = 'X') then
			iop <= 'W';
		    elsif (lastout = '1') then
			iop <= 'H';
		    else
			iop <= 'L';
		    end if;
		else
		    iop <= 'Z';
		end if;
	    end if;
	end if;
    end process; 

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c39kmc is
    generic (
	cfgbits	: Bit_Vector(11 downto 0);
	xlbRegSetup	: time;		-- checked parameters
	xlbRegHold	: time;
	xlbRegCkWthHi	: time;
	xlbRegCkWthLo	: time;
	xlbRegCkWthCy	: time;
	xlbRegPrRcr	: time;
	xlbRegPrWthHi	: time;
	xlbRegReRcr	: time;
	xlbRegReWthHi	: time;
	xlbSelin2Selout	: time;		-- applied parameters
	xlbCpt2Selout	: time;
	xlbCpt2RegD	: time;
	xlbEqn2RegD	: time;
	xlbSelin2RegD	: time;
	xlbRegQ2RegD	: time;
	xlbRegD2ToPim	: time;
	xlbRegCk2ToPim	: time;
	xlbRegPr2ToPim	: time;
	xlbRegRe2ToPim	: time);
    port (
	selin	: in	std_logic;
	cpt	: in	std_logic_vector(1 downto 0);
	set	: in	std_logic;
	clr	: in	std_logic;
	clk	: in	std_logic;
	din	: in	std_logic;
	selout	: out	std_logic;
	qout	: out	std_logic);
end c39kmc;

architecture sim of c39kmc is

    signal qp		: std_logic := '0';
    signal qn		: std_logic := '1';
    signal cmxout,c3	: std_logic;
    signal regd		: std_logic;
    signal xorin	: std_logic_vector(1 downto 0);
    signal dclk		: std_logic;
    signal dregd	: std_logic;

    constant dataSetup	: time := timeAdjust(xlbRegSetup);
    constant dataHold	: time := timeAdjust(xlbRegHold);
    constant unk	: string := " Setting output unknown.";

    signal clkerr	: std_logic;
    constant clk_high		: string :=
    "Clock high width violation:"	& unk;
    constant clk_low		: string :=
    "Clock low width violation:"	& unk;
    constant clk_cycle		: string :=
    "Clock cycle width violation:"	& unk;

    signal stuperr	: std_logic;
    constant data_setup		: string :=
    "Data to clock setup violation:"	& unk;

    signal holderr	: std_logic;
    constant data_hold		: string :=
    "Clock to data hold violation:"	& unk;

    signal clrerr	: std_logic;
    constant reset_width	: string :=
    "Reset width violation:"		& unk;

    signal crcverr	: std_logic;
    constant reset_rcvry	: string :=
    "Reset recovery violation:"		& unk;

    signal seterr	: std_logic;
    constant preset_width	: string :=
    "Preset width violation:"		& unk;

    signal srcverr	: std_logic;
    constant preset_rcvry	: string :=
    "Preset recovery violation:"	& unk;

begin

    -- check clk cycle, high and low times.
    process (clk)
	variable clkhi, clklo : time := 0 ns;
    begin
	if (cfgbits(11) = '1') then
	    if (clk = '0') then
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xlbRegCkWthHi)) then
		    assert (false)
			report clk_high
			severity warning;
		    clkerr <= '1';
		    clkerr <= transport '0' AFTER 1 ns;
		end if;
		clklo := NOW;
	    elsif (clk = '1') then
		if NOT ((clklo = 0 ns) OR ((NOW-clklo) >= xlbRegCkWthLo)) then
		   assert (false)
			report clk_low
			severity warning;
		    clkerr <= '1';
		    clkerr <= transport '0' AFTER 1 ns;
		end if;
		if NOT ((clkhi = 0 ns) OR ((NOW-clkhi) >= xlbRegCkWthCy)) then
		    assert (false)
			report clk_cycle
			severity warning;
		    clkerr <= '1';
		    clkerr <= transport '0' AFTER 1 ns;
		end if;
		clkhi := NOW;
	    end if;
	end if;
    end process;

    -- check setup
    dclk <= clk after dataSetup;
    process (regd, dclk)
    	variable dataev : time := 0 ns;
    begin
    	if (cfgbits(11) = '1') then
	    if ((clr = '0') AND (set = '0') AND rising_edge(dclk)) then
		if ((dataev/=0 ns) AND ((NOW-dataev)<xlbRegSetup+dataSetup))then
		    assert (false)
			report data_setup
			severity warning;
		    stuperr <= '1'; 
		    stuperr <= transport '0' AFTER 1 ns;
		end if;
	    elsif (regd'event) then
	    	dataev := NOW;
	    end if;
	end if;
    end process;

    -- check hold
    dregd <= regd after dataHold;
    process (dregd, clk)
    	variable clckev : time := 0 ns;
    begin
    	if (cfgbits(11) = '1') then
	    if ((clr = '0') AND (set = '0') AND rising_edge(clk)) then
	    	clckev := NOW;
	    elsif (dregd'event) then
		if ((clckev/=0 ns) AND ((NOW-clckev)<xlbRegHold+dataHold)) then
		    assert (false)
			report data_hold
			severity warning;
		    holderr <= '1'; 
		    holderr <= transport '0' AFTER 1 ns;
		end if;
	    end if;
	end if;
    end process;

    -- check reset recovery and reset width
    process (clr, clk)
        variable clrlastev, clklastev, clrhi : time := 0 ns;
    begin
        if (cfgbits(11) = '1') then
            if (clr'event) then
                clrlastev := NOW;
                if (clr = '1') then
                    clrhi := NOW;
                else
                    if NOT ((clrhi=0 ns) OR ((NOW-clrhi) >= xlbRegReWthHi)) then
                        assert (false)
                            report reset_width
                            severity warning;
                        clrerr <= '1'; 
                        clrerr <= transport '0' AFTER 1 ns;
                    end if;
                end if;
            end if;
            if ((clr = '0') AND rising_edge(clk)) then
                if NOT((clrlastev=0 ns) OR ((NOW-clrlastev)>=xlbRegReRcr)) then
                    assert (false)
			report reset_rcvry
                        severity warning;
                    crcverr <= '1';
                    crcverr <= transport '0' AFTER 1 ns;
                end if;
                clklastev := NOW;
            end if;
        end if;
    end process;

    -- check preset recovery and preset width
    process (set, clk)
        variable setlastev, clklastev, sethi : time := 0 ns;
    begin
        if (cfgbits(11) = '1') then
            if (set'event) then
                setlastev := NOW;
                if (set = '1') then
                    sethi := NOW;
                else
                    if NOT ((sethi=0 ns) OR ((NOW-sethi) >= xlbRegPrWthHi)) then
                        assert (false)
                            report preset_width
                            severity warning;
                        seterr <= '1'; 
                        seterr <= transport '0' AFTER 1 ns;
                    end if;
                end if;
            end if;
            if ((set = '0') AND rising_edge(clk)) then
                if NOT((setlastev=0 ns) OR ((NOW-setlastev)>=xlbRegPrRcr)) then
                    assert (false)
			report preset_rcvry
                        severity warning;
                    srcverr <= '1';
                    srcverr <= transport '0' AFTER 1 ns;
                end if;
                clklastev := NOW;
            end if;
        end if;
    end process;

    -- generate selout and carry chain mux output
    process (cpt, selin)
    begin
	if (cfgbits(2) = '0') then
	    selout <= cpt(0) after xlbCpt2Selout;
	    cmxout <= cpt(0) after xlbCpt2RegD;
    	elsif ( selin'event AND (selin = '0')) then
	    selout <= transport     cpt(0) after xlbSelin2Selout;
	    cmxout <= transport     cpt(0) after xlbSelin2RegD;
    	elsif ( selin'event AND (selin = '1')) then
	    selout <= transport NOT cpt(1) after xlbSelin2Selout;
	    cmxout <= transport NOT cpt(1) after xlbSelin2RegD;
    	elsif (cpt(0)'event AND (selin = '0')) then
	    selout <= transport     cpt(0) after xlbCpt2Selout;
	    cmxout <= transport     cpt(0) after xlbCpt2RegD;
    	elsif (cpt(1)'event AND (selin = '1')) then
	    selout <= transport NOT cpt(1) after xlbCpt2Selout;
	    cmxout <= transport NOT cpt(1) after xlbCpt2RegD;
	end if;
    end process;

    -- generate the XOR inputs
    c3 <= '1' when cfgbits(3) = '1' else '0';

    with cfgbits(1 downto 0) select
    	xorin(1) <= qp after xlbRegQ2RegD when "00",
		qn after xlbRegQ2RegD when "01",
		cmxout when "10",
		c3 when "11";

    xorin(0) <= din after xlbEqn2RegD;

    -- generate the "D" input
    regd  <= xorin(1) XOR xorin(0);

    -- generate the register
    process (set,clr,clk,regd,qp,
		stuperr,holderr,crcverr,srcverr,seterr,clrerr,clkerr)
    begin
    	if (cfgbits(11) = '1') then
	    if    (clr = '1') then
		qp <=      '0' after xlbRegRe2ToPim;
		qn <=      '1' after xlbRegRe2ToPim;
	    elsif (set = '1') then
		qp <=      '1' after xlbRegPr2ToPim;
		qn <=      '0' after xlbRegPr2ToPim;
	    elsif(stuperr='1' OR holderr='1' OR crcverr='1' OR srcverr='1' OR
		   seterr='1' OR clrerr='1'  OR clkerr='1') then
	    	qp <=      'X' after xlbRegCk2ToPim;
	    	qn <=      'X' after xlbRegCk2ToPim;
	    elsif (rising_edge(clk)) then
		qp <=     regd after xlbRegCk2ToPim;
		qn <= NOT regd after xlbRegCk2ToPim;
	    end if;
	    qout <= qp;
	else
	    qout <= regd after xlbRegD2ToPim;
	end if;
    end process;

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c2gffo is
port (	data_in	: in    std_logic_vector(15 downto 0);
	rstb	: in    std_logic;
	wrclk	: in    std_logic;
	out_2d	: out   std_logic_vector(15 downto 0);
	rdclk	: in    std_logic;
	fifoerr	: out   std_logic;
	fifoempty:inout std_logic);
end c2gffo;

architecture sim of c2gffo is

    signal intrstb	: std_logic;
    signal fifoclr	: std_logic;
    signal undflow_err	: std_logic;
    signal ovflow_err	: std_logic;
    signal d_avl	: std_logic;
    signal d_avl_sync1	:std_logic;
    signal d_avl_sync2	:std_logic;
    signal d_avl_sync2_d:std_logic;
    signal rstb_d	: std_logic;
    signal rstb_2d	: std_logic;
    signal fifofull	: std_logic;
    signal rdcnt	: integer range 0 to 5;
    signal rdcnt_sync1	: integer range 0 to 5;
    signal rdcnt_sync2	: integer range 0 to 5;
    signal wrcnt	: integer range 0 to 5;
    signal wrcnt_sync1	: integer range 0 to 5;
    signal wrcnt_sync2	: integer range 0 to 5;
    signal fifoclrcnt	: integer range 0 to 9;
    signal data_out	: std_logic_vector(15 downto 0);
    signal out_d	: std_logic_vector(15 downto 0);
    signal temp1	: std_logic_vector(15 downto 0);
    signal temp2	: std_logic_vector(15 downto 0);
    signal temp3	: std_logic_vector(15 downto 0);
    signal temp4	: std_logic_vector(15 downto 0);
    signal temp5	: std_logic_vector(15 downto 0);
    signal temp6	: std_logic_vector(15 downto 0);

begin

    Write: process (wrclk, intrstb)
    begin
	if (intrstb = '0') then
	    wrcnt	<=  0;
	    rdcnt_sync1	<=  0;
	    rdcnt_sync2	<=  0;
	    ovflow_err	<= '0' after 200 ps;
	    d_avl	<= '0';
	    fifofull	<= '0';
	elsif (rising_edge(wrclk)) then
	    d_avl <= '1';

	    if (fifofull = '0') then
		if (wrcnt = 5) then
		    wrcnt <= 0;
		else
		    wrcnt <= wrcnt + 1;
		end if;
	    else
		ovflow_err <= '1';
	    end if;

	    if (((wrcnt-rdcnt_sync1) >= 5) OR ((rdcnt_sync1-wrcnt) = 1)) then
		fifofull <= '1';
	    else
		fifofull <= '0';
	    end if;

	    rdcnt_sync1 <= rdcnt;
	    rdcnt_sync2 <= rdcnt_sync1;

	end if;

	if (rising_edge(wrclk)) then
	    rstb_d  <= rstb;
	    rstb_2d <= rstb_d;
	    if (fifofull = '0') then
	    	case (wrcnt) is
		    when 0 => temp1 <= data_in;
		    when 1 => temp2 <= data_in;
		    when 2 => temp3 <= data_in;
		    when 3 => temp4 <= data_in;
		    when 4 => temp5 <= data_in;
		    when 5 => temp6 <= data_in;
		end case;
	    end if;
	end if;
    end process;

    Read: process (rdclk, intrstb)
    begin
	if (intrstb = '0') then
	    rdcnt	<=  0;
	    wrcnt_sync1	<=  0;
	    wrcnt_sync2	<=  0;
	    d_avl_sync1	<= '0';
	    d_avl_sync2	<= '0';
	    fifoempty	<= '1';
	    fifoclrcnt	<=  0;
	    data_out	<= x"5555";
	elsif (rising_edge(rdclk)) then
	    case (rdcnt) is
		when 0 => data_out <= temp1;
		when 1 => data_out <= temp2;
		when 2 => data_out <= temp3;
		when 3 => data_out <= temp4;
		when 4 => data_out <= temp5;
		when 5 => data_out <= temp6;
	    end case;

	    out_d <= data_out;
	    out_2d <= out_d;

	    if (rdcnt /= wrcnt_sync1) then
		if (rdcnt = 5) then
		    rdcnt <= 0;
		else
		    rdcnt <= rdcnt + 1;
		end if;
	    end if;

	    wrcnt_sync1 <= wrcnt;
	    wrcnt_sync2 <= wrcnt_sync1;

	    d_avl_sync1 <= d_avl;
	    d_avl_sync2 <= d_avl_sync1;

	    if (rdcnt = wrcnt_sync1) then
		fifoempty <= '1';
	    else
		fifoempty <= '0';
	    end if;

	    if ((undflow_err = '1') OR (ovflow_err = '1')) then
		fifoclrcnt <= 1;
	    elsif (fifoclrcnt /= 0) then
		fifoclrcnt <= fifoclrcnt + 1;
	    end if;
	end if;
    end process;

    d_avl_sync2_d <= d_avl_sync2 after 200 ps;

    fifoerr	<= undflow_err OR ovflow_err;
    undflow_err	<= fifoempty AND d_avl_sync2_d;
    fifoclr	<= '1' when (fifoclrcnt = 9) else '0';
    intrstb	<= rstb AND NOT fifoclr;

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c2gcor is
port (txd	: in    std_logic_vector (15 downto 0);
    txclki	: in	std_logic;
    fifo_rstb	: in	std_logic;
    loop_time	: in	std_logic;
    diagloop	: in	std_logic;
    loopa	: in	std_logic;
    lineloop	: in	std_logic;
    resetb	: in	std_logic;
    pwrdnb	: in	std_logic;
    lockrefb	: in	std_logic;
    refclk	: in	std_logic;
    rd_in	: in	std_logic;
    sd		: in	std_logic;
    td_out	: out	std_logic;
    fifo_err	: inout	std_logic;
    txclko	: inout	std_logic;
    rxd		: out	std_logic_vector (15 downto 0) := (others => '0');
    rxclk	: inout	std_logic;
    lfib	: out	std_logic;
    locked	: out   std_logic);
end c2gcor;

architecture sim of c2gcor is

    signal txd_reg	: std_logic_vector (15 downto 0);
    signal rx_dat16	: std_logic_vector (15 downto 0);
    signal rx_dat16_bak	: std_logic_vector (15 downto 0);
    signal fifo_out	: std_logic_vector (15 downto 0);
    signal fifo_out_d	: std_logic_vector (15 downto 0);
    signal fifo_out_2d	: std_logic_vector (15 downto 0);
    signal rx_sd_cnt16	: natural;
    signal rx_cnt16	: natural;
    signal cnt16	: natural;
    signal shiftcnt	: natural;
    signal vco_buprox	: natural;
    signal vco_buprox_1	: natural;
    signal rd_in_d	: std_logic;
    signal out_1	: std_logic;
    signal retimed_data	: std_logic;
    signal done16	: std_logic;
    signal done16_rec	: std_logic;
    signal within_range	: std_logic;
    signal cntrstb	: std_logic;
    signal rxpll_in	: std_logic;
    signal tx_bit_clock	: std_logic;
    signal lfi_1	: std_logic;
    signal fifomt	: std_logic;
    signal fifomt_d	: std_logic;
    signal fifomt_2d	: std_logic;
    signal fifomt_2d_V	: std_logic;
    signal fifomt_3d	: std_logic;
    signal fifomt_d_tx	: std_logic := '1';
    signal fifomt_2d_tx	: std_logic := '1';
    signal fifomt_3d_tx	: std_logic := '1';
    signal fifomt_4d_tx	: std_logic := '1';
    signal fifomt_4d_tv	: std_logic := '1';
    signal out_1_d	: std_logic;
    signal txclk_pll	: std_logic := '0';
    signal recovered_clk: std_logic := '0';
    signal sd_d		: std_logic;
    signal fifo_rstb_d	: std_logic;
    signal fifo_rstb_2d	: std_logic;

    signal timestamp_in_0	: time := 0 fs;
    signal timestamp_in_1	: time := 0 fs;
    signal timestamp_in_2	: time := 0 fs;
    signal timestamp_out_0	: time := 0 fs;
    signal timestamp_out_1	: time := 0 fs;
    signal timestamp_clk_0	: time := 0 fs;
    signal timestamp_clk_1	: time := 0 fs;
    signal dur_rec_clk		: time := 0 fs;
    signal duration_in_0	: time := 0 fs;
    signal duration_in_1	: time := 0 fs;
    signal duration_in		: time := 0 fs;
    signal duration_clk		: time := 0 fs;
    signal duration_txclk	: time := 0 fs;
    signal duration_in_0_d	: time := 0 fs;
    signal duration_in_last	: time := 0 fs;

begin

    -- parallel input to serial output

    U0: c2gffo port map
	    (data_in	=> txd_reg,
	    rstb	=> fifo_rstb,
	    wrclk	=> txclki,
	    out_2d	=> fifo_out,
	    rdclk	=> txclko,
	    fifoerr	=> fifo_err,
	    fifoempty	=> fifomt);

    P1: process (txclki)
    begin
	if (rising_edge(txclki) AND (pwrdnb = '1')) then
	    txd_reg <= txd;
	end if;
    end process;

    P2: process (txclko, resetb)
    begin
    	if (resetb = '0') then
	    fifo_rstb_d  <= '0';
	    fifo_rstb_2d <= '0';
	elsif (rising_edge(txclko)) then
	    fifo_rstb_d  <= fifo_rstb;
	    fifo_rstb_2d <= fifo_rstb_d;
	    fifomt_d_tx  <= fifomt;
	    fifomt_2d_tx <= fifomt_d_tx;
	    fifomt_3d_tx <= fifomt_2d_tx;
	end if;
    end process;

    P3: process (txclko, fifomt_2d_tx)
    begin
    	if (fifomt_2d_tx = '1') then
	    fifo_out_d <= x"5555";
	elsif (rising_edge(txclko)) then
	    fifo_out_d <= fifo_out;
	end if;
    end process;

    P4: process (txclko, fifomt_2d_tx)
    begin
    	if (fifomt_2d_tx = '1') then
	    fifo_out_2d <= x"5555";
	elsif (falling_edge(txclko)) then
	    fifo_out_2d <= fifo_out_d;
	end if;
    end process;

    P5: process (txclko)
    begin
	if (falling_edge(txclko)) then
	    fifomt_4d_tx <= fifomt_3d_tx;
	end if;
    end process;

    P6: process (tx_bit_clock, resetb)
    begin
    	if (resetb = '0') then
	    out_1	<= '0';
	    shiftcnt	<= 15;
	elsif (rising_edge(tx_bit_clock)) then
	    if ((pwrdnb = '1') AND
		    (fifo_rstb_2d = '0') AND (fifo_rstb_d = '1')) then
	    	out_1 <= '0';
	    elsif ((pwrdnb = '1') AND (fifomt_4d_tx = '1')) then
	    	out_1 <= NOT out_1;
		shiftcnt <= 15;
	    elsif (pwrdnb = '1') then
	    	out_1 <= fifo_out_2d(shiftcnt);
		if (shiftcnt = 0) then
		    shiftcnt <= 15;
		else
		    shiftcnt <= shiftcnt - 1;
		end if;
	    end if;
	end if;
    end process;

    P7: process (tx_bit_clock, resetb)
    begin
    	if (resetb  = '0') then
	    cnt16  <=  0;
	elsif (rising_edge(tx_bit_clock) AND (pwrdnb = '1')) then
	    if (cnt16 = 15) then
		cnt16 <= 0;
	    else
		cnt16 <= cnt16 + 1;
	    end if;
	end if;
    end process;

    P7a: process (tx_bit_clock, resetb)
    begin
    	if (resetb  = '0') then
	    txclko <= '0';
	elsif (falling_edge(tx_bit_clock) AND (pwrdnb = '1')) then
	    if (cnt16 = 8) then
		txclko <= '0';
	    elsif (cnt16 = 0) then
		txclko <= '1';
	    end if;
	end if;
    end process;

    td_out <= retimed_data when (lineloop = '1') else
		     rd_in when (loopa = '1')    else out_1;

    tx_bit_clock <= recovered_clk when (loop_time = '1') else txclk_pll;

    -- serial input to parallel output

    P7b: process (out_1_d, rd_in_d, tx_bit_clock)
    begin
    	if (diagloop = '1') then
	    if(rising_edge(tx_bit_clock)) then
		rxpll_in <= out_1_d;
	    end if;
	else
	    if (rd_in_d'event) then
		rxpll_in <= rd_in_d;
	    end if;
	end if;
    end process;
    rd_in_d  <= rd_in after 10 ps;--10 ps;

    P8: process (recovered_clk, resetb)
    begin
    	if (resetb  = '0') then
	    vco_buprox <= 0;
	elsif (rising_edge(recovered_clk) AND (vco_buprox /= 131072)) then
	    vco_buprox <= vco_buprox + 1;
	end if;
    end process;

    P8a: process (rxpll_in, resetb)
    begin
    	if (resetb  = '0') then
	    vco_buprox_1 <= 0;
	elsif (rising_edge(rxpll_in) AND (vco_buprox_1 /= 32768)) then
	    vco_buprox_1 <= vco_buprox_1 + 1;
	end if;
    end process;

    P9: process (recovered_clk)
    begin
     	if (pwrdnb = '1' AND falling_edge(recovered_clk)) then
	    out_1_d <= out_1;
	    fifomt_4d_tv <= fifomt_4d_tx;
	    sd_d <= sd;
	elsif (falling_edge(recovered_clk)) then
	    sd_d <= sd;
	end if;
    end process;

    P9a: process (duration_in_0, duration_clk)
    begin
	if (duration_clk > 0 fs) then
	    if (((16.0*time_to_real(duration_in_0)/(time_to_real(duration_clk)))
		    <= 1.0002)  AND
		((16.0*time_to_real(duration_in_0)/(time_to_real(duration_clk)))
		    >= 0.9998)) then
		within_range <= '1';
	    else
		within_range <= '0';
	    end if;
	end if;
    end process;

    P10: process (pwrdnb, rxpll_in, diagloop, fifomt_2d)
    begin
	if (pwrdnb = '1') then
	    if ((diagloop = '1' AND fifomt_2d = '1') OR (diagloop = '0')) then
		timestamp_in_0 <= NOW;
		timestamp_in_1 <= timestamp_in_0;
		timestamp_in_2 <= timestamp_in_1;
	    end if;
	end if;
    end process;

    P11: process (refclk)
    begin
	if (pwrdnb = '1' AND rising_edge(refclk)) then
	    timestamp_clk_0 <= NOW;
	    timestamp_clk_1 <= timestamp_clk_0;
	end if;
    end process;

    P12: process (within_range)
    begin
    	if (falling_edge(within_range)) then
	    duration_in_last <= duration_in after 1 ps; --ps;
	end if;
    end process;

    P12x: process (duration_in_0)
    begin
	duration_in_0_d <= duration_in_0 after 1 ps; --ps;
    end process;

    P12a: process (duration_in_0_d)
    begin
    	if (within_range = '1') then
	    duration_in <= duration_in_0;
	else
	    duration_in <= duration_in_last;
	end if;
    end process;

    P12b: process (pwrdnb, timestamp_in_0, timestamp_in_1, timestamp_clk_0,
		    duration_in, timestamp_clk_1, sd, lockrefb, within_range,
		    diagloop, lfi_1)
    	variable var_clk : time;
    begin
     	if (pwrdnb = '1') then
	    duration_in_0 <= timestamp_in_0 - timestamp_in_1;

	    var_clk      := timestamp_clk_0 - timestamp_clk_1;
	    duration_clk <= var_clk;

	    if (lockrefb = '0' OR ((diagloop = '0') AND (sd = '0'))) then
		dur_rec_clk <= (var_clk / 16);
	    elsif (lfi_1 = '1') then
		dur_rec_clk <= duration_in;
	    else
		dur_rec_clk <= (var_clk / 16);
	    end if;
	    duration_txclk <= var_clk / 32;

	end if;
    end process;

     P13: process
     begin
	wait on refclk, pwrdnb, done16;
     	if (pwrdnb = '1') then
	    if (duration_txclk /= 0 fs) then
		for i in 1 to 32 loop
		    wait for duration_txclk;
		    txclk_pll <= NOT txclk_pll;
		end loop;
		done16 <= '1';
		wait for 5 fs;
		done16 <= '0';
	    end if;
	end if;
     end process;

    P15: process
    begin
	wait on pwrdnb, done16_rec, dur_rec_clk;
	if (pwrdnb = '1') then
	    if (dur_rec_clk /= 0 fs) then
		for i in 1 to 32 loop
		    wait for dur_rec_clk/2;
		    recovered_clk <= NOT recovered_clk;
		end loop;
		done16_rec <= '1';
		wait for 5 fs;
		done16_rec <= '0';
	    end if;
	end if;
     end process;

    P17: process (recovered_clk, resetb)
     begin
     	if (resetb = '0') then
	    rx_cnt16  <=  0;
	    fifomt_2d <= '1';
	    fifomt_3d <= '1';
	elsif ((pwrdnb = '1') AND (rising_edge(recovered_clk))) then
	    if (rx_cnt16 = 15) then
		rx_cnt16 <= 0;
	    else
		rx_cnt16 <= rx_cnt16 + 1;
	    end if;
	    fifomt_2d <= fifomt_d;
	    fifomt_3d <= fifomt_2d;
	end if;
     end process;

    P17a: process (recovered_clk, resetb)
     begin
     	if (resetb = '0') then
	    rxclk <= '1';
	elsif ((pwrdnb = '1') AND (falling_edge(recovered_clk))) then
	    if (rx_cnt16 = 8) then
		rxclk <= '1';
	    elsif (rx_cnt16 = 0) then
		rxclk <= '0';
	    end if;
	end if;
     end process;

     P18: process (recovered_clk, resetb)
     begin
     	if (resetb = '0') then
	    fifomt_d <= '1';
	elsif ((pwrdnb = '1') AND (rising_edge(recovered_clk))) then
	    fifomt_d <= fifomt_4d_tv;
	end if;
     end process;
     
     P19: process (refclk, resetb)
     begin
     	if (resetb = '0') then
	    lfi_1 <= '0';
	elsif ((within_range = '1') AND (pwrdnb = '1') AND
		(vco_buprox   = 131072) AND (vco_buprox_1 = 32768)  AND
		(rising_edge(refclk))) then
	    lfi_1 <= '1';
	elsif ((pwrdnb = '0') AND (within_range = '0')) then
	    lfi_1 <= '0';
	end if;
     end process;

     locked <= lfi_1;
     lfib <= lfi_1 AND lockrefb AND (diagloop OR sd);

     P20: process (recovered_clk, resetb)
     begin
     	if (resetb = '0') then
	    rx_dat16     <= (others => '0');
	    rx_dat16_bak <= (others => '0');
	    retimed_data <= '0';
	elsif ((pwrdnb = '1') AND (rising_edge(recovered_clk))) then
	    rx_dat16(rx_sd_cnt16) <= retimed_data;
	    if (rx_sd_cnt16 = 15) then
		rx_dat16_bak <= rx_dat16;
	    end if;
	    retimed_data <= rxpll_in;
	end if;
     end process;

     cntrstb <= resetb AND NOT (fifomt_2d AND diagloop);
     fifomt_2d_V <= fifomt_2d after 1 ps; --ps;

     P21: process (recovered_clk, cntrstb)
     begin
     	if (cntrstb = '0') then
	    rx_sd_cnt16  <= 15;
	elsif ((pwrdnb = '1') AND (rising_edge(recovered_clk))) then
	    if ((diagloop = '1' AND fifomt_2d_V = '0') OR (diagloop = '0')) then
		if (rx_sd_cnt16 = 0) then
		    rx_sd_cnt16 <= 15;
		else
		    rx_sd_cnt16 <= rx_sd_cnt16 - 1;
		end if;
	    end if;
	end if;
     end process;

     P22: process (rxclk, resetb)
     begin
     	if (resetb = '0') then
	    rxd <= (others => '0');
	elsif ((pwrdnb = '1') AND falling_edge(rxclk)) then
	    rxd <= rx_dat16_bak;
	end if;
     end process;

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c25g01serdes is
    port(txd		: in	std_logic_vector (15 downto 0);
	fifo_rstb	: in	std_logic;
	loop_time	: in	std_logic;
	diagloop	: in	std_logic;
	loopa		: in	std_logic;
	lineloop	: in	std_logic;
	resetb		: in	std_logic;
	pwrdnb		: in	std_logic;
	lockrefb	: in	std_logic;
	refclk_n	: in	std_logic;
	refclk_p	: in	std_logic;
	serial_in_n	: in	std_logic := '0';
	serial_in_p	: in	std_logic := '1';
	sd		: in	std_logic := '0';
	serial_out_n	: out	std_logic;
	serial_out_p	: out	std_logic;
	fifo_err	: out	std_logic;
	txclk		: out	std_logic;
	rxd		: out	std_logic_vector (15 downto 0);
	rxclk		: out	std_logic;
	lfib		: out	std_logic);
end c25g01serdes;

architecture sim of c25g01serdes is

    signal refclk	: std_logic;
    signal rd_in	: std_logic;
    signal td_out	: std_logic;
    signal txclki	: std_logic;
    signal t_rxd	: std_logic_vector (15 downto 0);
    signal t_txclk	: std_logic;
    signal t_fifo_err	: std_logic;
    signal t_rxclk	: std_logic;

    signal in_there	: std_logic;
    signal in_there_x	: std_logic;
    signal in_there_d	: std_logic;
    signal locked	: std_logic;
    signal duration_in		: real := 6425.0/16.0;
    signal duration_in_0	: real := 0.0;
    signal refclk_period	: real := 0.0;
    signal timestamp_in_0	: time := 0 ps;
    signal timestamp_in_1	: time := 0 ps;

    constant txclk_period_min	: time	:= 6380 ps;
    constant txclk_period_max	: time	:= 6470 ps;
    constant txclk_period_vio	: string
	:= "ERROR-001: TXCLK Period Violation";

    constant txclk_dutycy_min	: real	:= 0.43;
    constant txclk_dutycy_max	: real	:= 0.57;
    constant txclk_dutycy_vio	: string
	:= "ERROR-002: TXCLK Duty-cycle Violation";

    constant rxclk_period_min	: time	:= 6380 ps;
    constant rxclk_period_max	: time	:= 6470 ps;
    constant rxclk_period_vio	: string
	:= "ERROR-005: RXCLK Period Violation";

    constant rxclk_dutycy_min	: real	:= 0.43;
    constant rxclk_dutycy_max	: real	:= 0.57;
    constant rxclk_dutycy_vio	: string
	:= "ERROR-006: RXCLK Duty Cycle Violation";

    constant rfclk_period_min	: time	:= 6380 ps;
    constant rfclk_period_max	: time	:= 6470 ps;
    constant rfclk_period_vio	: string
	:= "ERROR-007: REFCLK Period Violation";

    constant rfclk_dutycy_min	: real	:= 0.35;
    constant rfclk_dutycy_max	: real	:= 0.65;
    constant rfclk_dutycy_vio	: string
	:= "ERROR-008: REFCLK Duty Cycle Violation";

    constant rfclk_freqtol	: real	:= 0.0001; -- +/- 100 ppm
    constant rfclk_freqtol_vio : string
	:= "ERROR-009: REFCLK Frequency Tolerance Violation";

    constant txds		: time	:= 1500 ps;
    constant txds_vio		: string
	:= "ERROR-010: Write Data setup Violation to posedge of TXCLK";

    constant txdh		: time	:= 500 ps;
    constant txdh_vio		: string
	:= "ERROR-011: Write Data Hold Violation from posedge of TXCLK";

    constant rxds		: time	:= 2200 ps;
    constant rxds_vio		: string
	:= "ERROR-012: Recovered Data Setup Violation w.r.t. posedge of REFCLK";

    constant rxdh		: time	:= 2200 ps;
    constant rxdh_vio		: string
	:= "ERROR-013: Recovered Data Hold Violation w.r.t. posedge of REFCLK";

begin

    -- check txclk period and duty cycle
    process (t_txclk)
	variable txckhi	: time := 0 ns;
	variable txcklo	: time := 0 ns;
	variable tcy	: real;
    begin
	if (pwrdnb = '1') then
	    if (t_txclk = '0') then
		txcklo := NOW;
	    elsif (t_txclk = '1') then
		if ((txckhi /= 0 ns) AND (txcklo /= 0 ns)) then
		    tcy := (time_to_real(NOW-txcklo)/time_to_real(NOW-txckhi));
		    if((tcy < txclk_dutycy_min) OR (tcy > txclk_dutycy_max))then
			assert (locked /= '1')
			    report txclk_dutycy_vio severity warning;
		    end if;
		end if;
		if (((txckhi/=0 ns) AND ((NOW-txckhi) < txclk_period_min)) OR
		    ((txckhi/=0 ns) AND ((NOW-txckhi) > txclk_period_max))) then
		    assert (locked /= '1')
			report txclk_period_vio severity warning;
		end if;
		txckhi := NOW;
	    end if;
	end if;
    end process;

    -- check transmit data setup and hold
    process (txd, t_txclk)
    	variable tdataevent : time := 0 ns;
    	variable tclkevent  : time := 0 ns;
    begin
	if (pwrdnb = '1') then
	    if (rising_edge(t_txclk)) then
		if ((tdataevent /= 0 ns) AND
		    ((NOW - tdataevent) < txds)) then
		    assert (locked /= '1')
			report txds_vio severity warning;
		end if;
		tclkevent := NOW;
	    elsif (txd'event) then
		if ((tclkevent /= 0 ns) AND
		    ((NOW - tclkevent) < txdh)) then
		    assert (locked /= '1')
			report txdh_vio severity warning;
		end if;
		tdataevent := NOW;
	    end if;
	end if;
    end process;

    -- check rxclk period and duty cycle
    process (t_rxclk)
	variable rxckhi	: time := 0 ns;
	variable rxcklo	: time := 0 ns;
	variable rcy	: real;
    begin
	if (pwrdnb = '1') then
	    if (t_rxclk = '0') then
		rxcklo := NOW;
	    elsif (t_rxclk = '1') then
		if ((rxckhi /= 0 ns) AND (rxcklo /= 0 ns)) then
		    rcy := (time_to_real(NOW-rxcklo)/time_to_real(NOW-rxckhi));
		    if((rcy < rxclk_dutycy_min) OR (rcy > rxclk_dutycy_max))then
			assert (locked /= '1')
			    report rxclk_dutycy_vio severity warning;
		    end if;
		end if;
		if (((rxckhi/=0 ns) AND ((NOW-rxckhi) < rxclk_period_min)) OR
		    ((rxckhi/=0 ns) AND ((NOW-rxckhi) > rxclk_period_max))) then
		    assert (locked /= '1')
			report rxclk_period_vio severity warning;
		end if;
		rxckhi := NOW;
	    end if;
	end if;
    end process;

    -- check recovered data setup and hold
    process (t_rxd, t_rxclk)
    	variable rdataevent : time := 0 ns;
    	variable rclkevent  : time := 0 ns;
    begin
	if (pwrdnb = '1') then
	    if (rising_edge(t_rxclk)) then
		if ((rdataevent /= 0 ns) AND
		    ((NOW - rdataevent) < rxds)) then
		    assert (locked /= '1')
			report rxds_vio severity warning;
		end if;
		rclkevent := NOW;
	    elsif (t_rxd'event) then
		if ((rclkevent /= 0 ns) AND
		    ((NOW - rclkevent) < rxdh)) then
		    assert (locked /= '1')
			report rxdh_vio severity warning;
		end if;
		rdataevent := NOW;
	    end if;
	end if;
    end process;

    -- check refclk period and duty cycle
    process (refclk)
	variable rfckhi	: time := 0 ns;
	variable rfcklo	: time := 0 ns;
	variable fcy	: real;
    begin
	if (pwrdnb = '1') then
	    if (refclk = '0') then
		rfcklo := NOW;
	    elsif (refclk = '1') then
		if ((rfckhi /= 0 ns) AND (rfcklo /= 0 ns)) then
		    fcy := (time_to_real(NOW-rfcklo)/time_to_real(NOW-rfckhi));
		    if((fcy < rfclk_dutycy_min) OR (fcy > rfclk_dutycy_max))then
			assert (locked /= '1')
			    report rfclk_dutycy_vio severity warning;
		    end if;
		end if;
		refclk_period <= time_to_real(NOW - rfckhi);
		if (((rfckhi/=0 ns) AND ((NOW-rfckhi) < rfclk_period_min)) OR
		    ((rfckhi/=0 ns) AND ((NOW-rfckhi) > rfclk_period_max))) then
		    assert (locked /= '1')
			report rfclk_period_vio severity warning;
		end if;
		rfckhi := NOW;
	    end if;
	end if;
    end process;

    -- check refclk freqency tolerance
    process (rd_in, pwrdnb)
    begin
	if (pwrdnb = '1') then
	    timestamp_in_0 <= NOW;
	    timestamp_in_1 <= timestamp_in_0;
	    in_there <= '1';
	end if;
    end process;

    process (rd_in)
    begin
	if ((pwrdnb = '1') AND rising_edge(rd_in)) then
	    in_there_x <= in_there;
	    in_there_d <= in_there_x;
	end if;
    end process;

    process (timestamp_in_0, timestamp_in_1)
    begin
    	duration_in_0 <= time_to_real(timestamp_in_0 - timestamp_in_1);
    end process;

    process (duration_in_0, refclk_period, pwrdnb)
    begin
	if ((pwrdnb = '1') AND (refclk_period > 0.0) AND
	((16.0 * duration_in_0)/refclk_period <= (1.0 + rfclk_freqtol) AND
	((16.0 * duration_in_0)/refclk_period >= (1.0 - rfclk_freqtol)))) then
	    duration_in <= duration_in_0;
	end if;
    end process;

    process (refclk)
    begin
	if ((pwrdnb = '1') AND (rising_edge(refclk)) AND (in_there_d = '1')
	    AND (resetb = '1') AND (refclk_period > 0.0) AND
	    ((16.0 * duration_in)/refclk_period > (1.0 + rfclk_freqtol) OR
	    ((16.0 * duration_in)/refclk_period < (1.0 - rfclk_freqtol)))) then
		assert (locked /= '1')
		    report rfclk_freqtol_vio severity warning;
	 end if;
    end process;

    fifo_err	<= t_fifo_err;
    rxclk	<= t_rxclk;
    txclki	<= t_txclk;
    txclk	<= t_txclk;
    rxd		<= t_rxd;

    refclk <= refclk_p    AND NOT refclk_n;
    rd_in  <= serial_in_p AND NOT serial_in_n;

    U1: c2gcor port map
	(txd		=>	txd,
	txclki		=>	txclki,
	fifo_rstb	=>	fifo_rstb,
	loop_time	=>	loop_time,
	diagloop	=>	diagloop,
	loopa		=>	loopa,
	lineloop	=>	lineloop,
	resetb		=>	resetb,
	pwrdnb		=>	pwrdnb,
	lockrefb	=>	lockrefb,
	refclk		=>	refclk,
	rd_in		=>	rd_in,
	sd		=>	sd,
	td_out		=>	td_out,
	fifo_err	=>	t_fifo_err,
	txclko		=>	t_txclk,
	rxd		=>	t_rxd,
	rxclk		=>	t_rxclk,
	lfib		=>	lfib,
	locked		=>	locked);

    serial_out_n <= NOT td_out;
    serial_out_p <=     td_out;

end sim;

library ieee;
use ieee.std_logic_1164.all;

use work.primitive.all;

entity c2gserdes is
    port(txd		: in	std_logic_vector (15 downto 0);
	fifo_rstb	: in	std_logic;
	loop_time	: in	std_logic;
	diagloop	: in	std_logic;
	loopa		: in	std_logic;
	lineloop	: in	std_logic;
	resetb		: in	std_logic;
	pwrdnb		: in	std_logic;
	lockrefb	: in	std_logic;
	refclk_n	: in	std_logic;
	refclk_p	: in	std_logic;
	serial_in_n	: in	std_logic := '0';
	serial_in_p	: in	std_logic := '1';
	sd		: in	std_logic := '0';
	serial_out_n	: out	std_logic;
	serial_out_p	: out	std_logic;
	fifo_err	: out	std_logic;
	txclk		: out	std_logic;
	rxd		: out	std_logic_vector (15 downto 0);
	rxclk		: out	std_logic;
	lfib		: out	std_logic);
end c2gserdes;
architecture sim of c2gserdes is
begin
    UA: c25g01serdes port map (
	txd		=>	txd,
	fifo_rstb	=>	fifo_rstb,
	loop_time	=>	loop_time,
	diagloop	=>	diagloop,
	loopa		=>	loopa,
	lineloop	=>	lineloop,
	resetb		=>	resetb,
	pwrdnb		=>	pwrdnb,
	lockrefb	=>	lockrefb,
	refclk_n	=>	refclk_n,
	refclk_p	=>	refclk_p,
	serial_in_n	=>	serial_in_n,
	serial_in_p	=>	serial_in_p,
	sd		=>	sd,
	serial_out_n	=>	serial_out_n,
	serial_out_p	=>	serial_out_p,
	fifo_err	=>	fifo_err,
	txclk		=>	txclk,
	rxd		=>	rxd,
	rxclk		=>	rxclk,
	lfib		=>	lfib);
end sim;
