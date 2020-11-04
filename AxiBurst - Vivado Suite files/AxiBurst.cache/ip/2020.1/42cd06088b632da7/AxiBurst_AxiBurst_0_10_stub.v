// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.1 (win64) Build 2902540 Wed May 27 19:54:49 MDT 2020
// Date        : Tue Nov  3 19:34:41 2020
// Host        : Megatron running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ AxiBurst_AxiBurst_0_10_stub.v
// Design      : AxiBurst_AxiBurst_0_10
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "AxiBurst,Vivado 2020.1" *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix(s_axi_sqrt_AWADDR, s_axi_sqrt_AWVALID, 
  s_axi_sqrt_AWREADY, s_axi_sqrt_WDATA, s_axi_sqrt_WSTRB, s_axi_sqrt_WVALID, 
  s_axi_sqrt_WREADY, s_axi_sqrt_BRESP, s_axi_sqrt_BVALID, s_axi_sqrt_BREADY, 
  s_axi_sqrt_ARADDR, s_axi_sqrt_ARVALID, s_axi_sqrt_ARREADY, s_axi_sqrt_RDATA, 
  s_axi_sqrt_RRESP, s_axi_sqrt_RVALID, s_axi_sqrt_RREADY, ap_clk, ap_rst_n, interrupt, 
  m_axi_output_r_AWADDR, m_axi_output_r_AWLEN, m_axi_output_r_AWSIZE, 
  m_axi_output_r_AWBURST, m_axi_output_r_AWLOCK, m_axi_output_r_AWREGION, 
  m_axi_output_r_AWCACHE, m_axi_output_r_AWPROT, m_axi_output_r_AWQOS, 
  m_axi_output_r_AWVALID, m_axi_output_r_AWREADY, m_axi_output_r_WDATA, 
  m_axi_output_r_WSTRB, m_axi_output_r_WLAST, m_axi_output_r_WVALID, 
  m_axi_output_r_WREADY, m_axi_output_r_BRESP, m_axi_output_r_BVALID, 
  m_axi_output_r_BREADY, m_axi_output_r_ARADDR, m_axi_output_r_ARLEN, 
  m_axi_output_r_ARSIZE, m_axi_output_r_ARBURST, m_axi_output_r_ARLOCK, 
  m_axi_output_r_ARREGION, m_axi_output_r_ARCACHE, m_axi_output_r_ARPROT, 
  m_axi_output_r_ARQOS, m_axi_output_r_ARVALID, m_axi_output_r_ARREADY, 
  m_axi_output_r_RDATA, m_axi_output_r_RRESP, m_axi_output_r_RLAST, 
  m_axi_output_r_RVALID, m_axi_output_r_RREADY)
/* synthesis syn_black_box black_box_pad_pin="s_axi_sqrt_AWADDR[4:0],s_axi_sqrt_AWVALID,s_axi_sqrt_AWREADY,s_axi_sqrt_WDATA[31:0],s_axi_sqrt_WSTRB[3:0],s_axi_sqrt_WVALID,s_axi_sqrt_WREADY,s_axi_sqrt_BRESP[1:0],s_axi_sqrt_BVALID,s_axi_sqrt_BREADY,s_axi_sqrt_ARADDR[4:0],s_axi_sqrt_ARVALID,s_axi_sqrt_ARREADY,s_axi_sqrt_RDATA[31:0],s_axi_sqrt_RRESP[1:0],s_axi_sqrt_RVALID,s_axi_sqrt_RREADY,ap_clk,ap_rst_n,interrupt,m_axi_output_r_AWADDR[31:0],m_axi_output_r_AWLEN[7:0],m_axi_output_r_AWSIZE[2:0],m_axi_output_r_AWBURST[1:0],m_axi_output_r_AWLOCK[1:0],m_axi_output_r_AWREGION[3:0],m_axi_output_r_AWCACHE[3:0],m_axi_output_r_AWPROT[2:0],m_axi_output_r_AWQOS[3:0],m_axi_output_r_AWVALID,m_axi_output_r_AWREADY,m_axi_output_r_WDATA[31:0],m_axi_output_r_WSTRB[3:0],m_axi_output_r_WLAST,m_axi_output_r_WVALID,m_axi_output_r_WREADY,m_axi_output_r_BRESP[1:0],m_axi_output_r_BVALID,m_axi_output_r_BREADY,m_axi_output_r_ARADDR[31:0],m_axi_output_r_ARLEN[7:0],m_axi_output_r_ARSIZE[2:0],m_axi_output_r_ARBURST[1:0],m_axi_output_r_ARLOCK[1:0],m_axi_output_r_ARREGION[3:0],m_axi_output_r_ARCACHE[3:0],m_axi_output_r_ARPROT[2:0],m_axi_output_r_ARQOS[3:0],m_axi_output_r_ARVALID,m_axi_output_r_ARREADY,m_axi_output_r_RDATA[31:0],m_axi_output_r_RRESP[1:0],m_axi_output_r_RLAST,m_axi_output_r_RVALID,m_axi_output_r_RREADY" */;
  input [4:0]s_axi_sqrt_AWADDR;
  input s_axi_sqrt_AWVALID;
  output s_axi_sqrt_AWREADY;
  input [31:0]s_axi_sqrt_WDATA;
  input [3:0]s_axi_sqrt_WSTRB;
  input s_axi_sqrt_WVALID;
  output s_axi_sqrt_WREADY;
  output [1:0]s_axi_sqrt_BRESP;
  output s_axi_sqrt_BVALID;
  input s_axi_sqrt_BREADY;
  input [4:0]s_axi_sqrt_ARADDR;
  input s_axi_sqrt_ARVALID;
  output s_axi_sqrt_ARREADY;
  output [31:0]s_axi_sqrt_RDATA;
  output [1:0]s_axi_sqrt_RRESP;
  output s_axi_sqrt_RVALID;
  input s_axi_sqrt_RREADY;
  input ap_clk;
  input ap_rst_n;
  output interrupt;
  output [31:0]m_axi_output_r_AWADDR;
  output [7:0]m_axi_output_r_AWLEN;
  output [2:0]m_axi_output_r_AWSIZE;
  output [1:0]m_axi_output_r_AWBURST;
  output [1:0]m_axi_output_r_AWLOCK;
  output [3:0]m_axi_output_r_AWREGION;
  output [3:0]m_axi_output_r_AWCACHE;
  output [2:0]m_axi_output_r_AWPROT;
  output [3:0]m_axi_output_r_AWQOS;
  output m_axi_output_r_AWVALID;
  input m_axi_output_r_AWREADY;
  output [31:0]m_axi_output_r_WDATA;
  output [3:0]m_axi_output_r_WSTRB;
  output m_axi_output_r_WLAST;
  output m_axi_output_r_WVALID;
  input m_axi_output_r_WREADY;
  input [1:0]m_axi_output_r_BRESP;
  input m_axi_output_r_BVALID;
  output m_axi_output_r_BREADY;
  output [31:0]m_axi_output_r_ARADDR;
  output [7:0]m_axi_output_r_ARLEN;
  output [2:0]m_axi_output_r_ARSIZE;
  output [1:0]m_axi_output_r_ARBURST;
  output [1:0]m_axi_output_r_ARLOCK;
  output [3:0]m_axi_output_r_ARREGION;
  output [3:0]m_axi_output_r_ARCACHE;
  output [2:0]m_axi_output_r_ARPROT;
  output [3:0]m_axi_output_r_ARQOS;
  output m_axi_output_r_ARVALID;
  input m_axi_output_r_ARREADY;
  input [31:0]m_axi_output_r_RDATA;
  input [1:0]m_axi_output_r_RRESP;
  input m_axi_output_r_RLAST;
  input m_axi_output_r_RVALID;
  output m_axi_output_r_RREADY;
endmodule
