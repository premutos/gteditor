SUBDIRS = lib gui 

sbin_PROGRAMS = gteditor

gteditor_SOURCES = \
	GTEditor.cc \
	Configuration.cc

gteditor_LDADD = \
	$(top_builddir)/src/lib/libgteditor-lib.la \
	$(top_builddir)/src/gui/libgteditor-gui.la \
	-lboost_thread -lboost_system -lboost_program_options

gteditor_LDFLAGS = -pthread
