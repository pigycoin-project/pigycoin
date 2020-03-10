.PHONY: FORCE
all: FORCE
	$(MAKE) -C .. pigycoin_qt test_pigycoin_qt
clean: FORCE
	$(MAKE) -C .. pigycoin_qt_clean test_pigycoin_qt_clean
check: FORCE
	$(MAKE) -C .. test_pigycoin_qt_check
pigycoin-qt pigycoin-qt.exe: FORCE
	 $(MAKE) -C .. pigycoin_qt
