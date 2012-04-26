check_PROGRAMS = \
	test-sheet \
	test-staff

test_sheet_CXXFLAGS = -I$(top_builddir)/src
test_sheet_SOURCES = \
	test_sheet.cc
test_sheet_LDADD = \
	$(top_builddir)/src/gui/Sheet.o \
	$(top_builddir)/src/gui/Staff.o \
	$(top_builddir)/src/lib/libgteditor-lib.la \
	-lboost_program_options

test_staff_CXXFLAGS = -I$(top_builddir)/src
test_staff_SOURCES = \
	test_staff.cc
test_staff_LDADD = \
	$(top_builddir)/src/gui/Staff.o \
	$(top_builddir)/src/lib/libgteditor-lib.la \
	-lboost_program_options
