R=R
PKG          := ropencv
PKG_VERSION  := 0.1.1

PKG_ROOT_DIR := $(shell pwd)
PKG_DIST_ROOT_DIR := ../$(PKG).tmp
PKG_HIDDEN_FILES  := Makefile 

install: 
	@echo '====== Installing Package ======'
	@(cd ..; ${R} CMD INSTALL $(PKG))
	@echo '====== Installing finished ======'
	@echo ' '

check:	
	@echo '====== Checking Package ======'
	@(export R_DEVELOP_MODE=TRUE; cd ..; ${R} CMD check $(PKG))
	@echo '====== Checking finished ======'
	@echo ' '

dist:	
	@echo '====== Building Distribution ======'
	cp -rp $(PKG_ROOT_DIR) $(PKG_DIST_ROOT_DIR)
	@(cd ..; $(RM) -r $(PKG_HIDDEN_FILES); R CMD build $(PKG))
	$(RM) -r $(PKG_DIST_ROOT_DIR)
	@echo '====== Building finished ======'
	@echo ' '
	@echo '====== Checking Package ======'
	@(export R_DEVELOP_MODE=TRUE; cd ..; ${R} CMD check $(PKG)_$(PKG_VERSION).tar.gz)
	@echo '====== Checking finished  ======'
	@echo ' '