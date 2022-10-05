.PHONY: clean All

All:
	@echo "----------Building project:[ 4Oct2022 - Debug ]----------"
	@cd "4Oct2022" && "$(MAKE)" -f  "4Oct2022.mk"
clean:
	@echo "----------Cleaning project:[ 4Oct2022 - Debug ]----------"
	@cd "4Oct2022" && "$(MAKE)" -f  "4Oct2022.mk" clean
