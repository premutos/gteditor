check_PROGRAMS = \
	test-staff

test_staff_CXXFLAGS = -I$(top_builddir)/src
test_staff_SOURCES = \
	test_staff.cc
test_staff_LDADD = \
	$(top_builddir)/src/gui/Staff.o \
	$(top_builddir)/src/lib/libgteditor-lib.la \
	-lboost_program_options
