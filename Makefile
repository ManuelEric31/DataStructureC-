.PHONY: clean All

All:
	@echo "----------Building project:[ 7Nov2022SLLQueue - Debug ]----------"
	@cd "7Nov2022SLLQueue" && "$(MAKE)" -f  "7Nov2022SLLQueue.mk"
clean:
	@echo "----------Cleaning project:[ 7Nov2022SLLQueue - Debug ]----------"
	@cd "7Nov2022SLLQueue" && "$(MAKE)" -f  "7Nov2022SLLQueue.mk" clean
