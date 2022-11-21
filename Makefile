.PHONY: clean All

All:
	@echo "----------Building project:[ 21Nov2022 - Debug ]----------"
	@cd "21Nov2022" && "$(MAKE)" -f  "21Nov2022.mk"
clean:
	@echo "----------Cleaning project:[ 21Nov2022 - Debug ]----------"
	@cd "21Nov2022" && "$(MAKE)" -f  "21Nov2022.mk" clean
