.PHONY: clean All

All:
	@echo "----------Building project:[ 7Nov2022SLLStack - Debug ]----------"
	@cd "7Nov2022" && "$(MAKE)" -f  "7Nov2022SLLStack.mk"
clean:
	@echo "----------Cleaning project:[ 7Nov2022SLLStack - Debug ]----------"
	@cd "7Nov2022" && "$(MAKE)" -f  "7Nov2022SLLStack.mk" clean
