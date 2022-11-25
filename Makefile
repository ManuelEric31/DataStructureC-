.PHONY: clean All

All:
	@echo "----------Building project:[ CircularDLLProject - Debug ]----------"
	@cd "CircularDLLProject" && "$(MAKE)" -f  "CircularDLLProject.mk"
clean:
	@echo "----------Cleaning project:[ CircularDLLProject - Debug ]----------"
	@cd "CircularDLLProject" && "$(MAKE)" -f  "CircularDLLProject.mk" clean
