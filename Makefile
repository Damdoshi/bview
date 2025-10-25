## Jason Brillante "Damdoshi" -------    ---  -- --- -    ---  --    - -- -   -
## Hanged Bunny Studio 2014-2021 ----- -- - -- -  -  -- -- - -- --  -- -- -- --
## Pentacle Technologie 2008-2021 ---- -- -    - - - -- -- - -- ---- -    -- --
## ----------------------------------    -- -- - --- -    ---  --   -- -- -   -
## Bunny picture viewer -------------------------------------------------------

## ----------------------------------------------------------------------------
## Configuration --------------------------------------------------------------

  CC		=	b++
  BIN		=	bview
  FLAG		=	-W -Wall -g -g3 -ggdb

  INCLUDE	=	-I./include/ -DDEBUG
  SRC		=	$(wildcard src/*.cpp)
  OBJ		=	$(SRC:.cpp=.o)

  ## Rules ------------------------------------------------------------------
  all:		bin
  bin:		$(OBJ)
		@$(CC) $(OBJ) -o $(BIN) $(LIBPATH) $(LIB)
		@echo "[OUT] " $(BIN)
		@echo $(BIN) | tr '[:lower:]' '[:upper:]'
  .cpp.o:
		@$(CC) $(INCLUDE) $(FLAG) -c $< -o $@
		@echo "[$(CC)]" $<
  clean:
		@rm -f $(OBJ)
  fclean:	clean
		@rm -f $(BIN)
  re:		fclean all

  install:
		cp $(BIN) /usr/bin/
  package:
		dpkg-buildpackage -us -uc

## ----------------------------------------------------------------------------
## MISC -----------------------------------------------------------------------

  .PHONY: all clean fclean re

  .SUFFIXES: .cpp .o
