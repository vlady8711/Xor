#include "stimulus.h"
#include "xor.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]) {
	sc_signal<bool> input_1, input_2, output;
	sc_clock test_clock("TestClock", 10, SC_NS, 0.5);
	sc_trace_file *trace_file;
	
	stimulus stimulus_1("Stimulus");
	stimulus_1.input_1(input_1);
	stimulus_1.input_2(input_2);
	stimulus_1.clock(test_clock);
	
	monitor monitor_1("Monitor");
	monitor_1.input_1(input_1);
	monitor_1.input_2(input_2);
	monitor_1.output(output);
	monitor_1.clock(test_clock);

	xor_ xor_1("Xor");
	xor_1.input_1(input_1);
	xor_1.input_2(input_2);
	xor_1.output(output);

	trace_file = sc_create_vcd_trace_file("wave");


	sc_trace(trace_file, test_clock, "Clock");
	sc_trace(trace_file, input_1, "Input_1");
	sc_trace(trace_file, input_2, "Input_2");
	sc_trace(trace_file, output, "Output");

	sc_start();

	sc_close_vcd_trace_file(trace_file);

	return 0;
}