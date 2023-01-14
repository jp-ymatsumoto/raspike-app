mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))
APPL_COBJS += hackspi.o starter.o wheel.o linemonitor.o linetracer.o scenario.o scenario_tracer.o cycle_timer.o
APPL_LIBS += -lm
APPL_DIRS += \
	$(mkfile_path)app \
	$(mkfile_path)utils
INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)utils
