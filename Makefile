.PHONY: clean All

All:
	@echo "----------Building project:[ 26Sept2022 - Debug ]----------"
	@cd "26Sept2022" && "$(MAKE)" -f  "26Sept2022.mk"
clean:
	@echo "----------Cleaning project:[ 26Sept2022 - Debug ]----------"
	@cd "26Sept2022" && "$(MAKE)" -f  "26Sept2022.mk" clean
