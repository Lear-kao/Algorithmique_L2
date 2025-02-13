#def des variables
CC = gcc
EXE = exe
INC_Dir = headers
SRC_Dir_Ex = TD2
SRC_Dir_Gen = prog_gen
#OBJ_Dir = fich_obj
#DATA_Dir = "chemin relatif au makefile des data"

CFLAGS = -std=c99 -Wall -pedantic  -g -I$(INC_Dir)
#LDFLAGS = -l("lib  perso") -L("chemin d'accès lib perso") -lm

#Regle  par  défaut
default: $(EXE)

#ensemble des règles
$(OBJ_Dir)/fct.o : $(SRC_Dir_Gen)/func_fils.c $(INC_Dir)/headrs_fils.h
	$(CC) -c $(SRC_Dir_Gen)/func_fils.c $(CFLAGS) -o $(OBJ_Dir)/fct.o

#$(OBJ_Dir)/fct2.o : $(SRC_Dir)/Ex2.c $(INC_Dir)/headrs_type.h
#	$(CC) -c $(SRC_Dir)/Ex2.c $(CFLAGS) -o $(OBJ_Dir)/fct2.o

$(OBJ_Dir)/comp.o : $(SRC_Dir_Ex)/exo1.c $(INC_Dir)/headrs_type.h
	$(CC) -c $(SRC_Dir_Ex)/exo1.c $(CFLAGS) -o $(OBJ_Dir)/comp.o

$(EXE): $(OBJ_Dir)/fct.o $(OBJ_Dir)/fct2.o $(OBJ_Dir)/comp.o 
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ_Dir)/fct.o $(OBJ_Dir)/comp.o

clean:
	rm -f $(OBJ_Dir)/*.o