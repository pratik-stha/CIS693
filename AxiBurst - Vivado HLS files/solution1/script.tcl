############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project AxiBurst
set_top AxiBurst
add_files C:/Users/16167/Downloads/axi4_burst/axi4_sqrt.cpp
add_files C:/Users/16167/Downloads/axi4_burst/axi4_sqrt.hpp
open_solution "solution1"
set_part {xc7z020clg400-1}
create_clock -period 10 -name default
config_export -format ip_catalog -rtl verilog
#source "./AxiBurst/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog
