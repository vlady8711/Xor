#include "stimulus.h"
#include "xor.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]) {
	/* 
	sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated",
                                           sc_core::SC_DO_NOTHING );
	*/
	sc_signal<bool> ASig, BSig, FSig;
	sc_clock TestClk("TestClock", 10, SC_NS, 0.5);
	sc_trace_file *fp;
	
	stimulus Stim1("Stimulus");
	Stim1.A(ASig);
	Stim1.B(BSig);
	Stim1.Clk(TestClk);
	
	monitor Monitor1("Monitor");
	Monitor1.A(ASig);
	Monitor1.B(BSig);
	Monitor1.F(FSig);
	Monitor1.Clk(TestClk);

	xor_ DUV("xor");
	DUV.A(ASig);
	DUV.B(BSig);
	DUV.F(FSig);




	fp = sc_create_vcd_trace_file("wave");


	sc_trace(fp, TestClk, "Clk");
	sc_trace(fp, ASig, "A");
	sc_trace(fp, BSig, "B");
	sc_trace(fp, FSig, "F");

	sc_start();

	sc_close_vcd_trace_file(fp);



	return 0;
}