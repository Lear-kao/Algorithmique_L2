#def des variables
CC = gcc
EXE = exe
INC_Dir = headers
SRC_Dir_Ex = TD2
SRC_Dir_Gen = prog_gen
OBJ_Dir = obj
#DATA_Dir = "chemin relatif au makefile des data"

CFLAGS = -std=c99 -pedantic  -g -I$(INC_Dir)
#LDFLAGS = -l("lib  perso") -L("chemin d'accès lib perso") -lm

#Regle  par  défaut
default: $(EXE)

#ensemble des règles
$(OBJ_Dir)/fct.o : $(SRC_Dir_Gen)/func_fils.c $(INC_Dir)/headrs_fils.h
	$(CC) -c $(SRC_Dir_Gen)/func_fils.c $(CFLAGS) -o $(OBJ_Dir)/fct.o

$(OBJ_Dir)/ar_bin.o : $(SRC_Dir_Gen)/func_a_b.c $(INC_Dir)/headrs_fils.h
	$(CC) -c $(SRC_Dir_Gen)/func_a_b.c $(CFLAGS) -o $(OBJ_Dir)/ar_bin.o

$(OBJ_Dir)/comp.o : main.c $(INC_Dir)/headrs_fils.h
	$(CC) -c main.c $(CFLAGS) -o $(OBJ_Dir)/comp.o

$(EXE): $(OBJ_Dir)/fct.o $(OBJ_Dir)/ar_bin.o $(OBJ_Dir)/comp.o 
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ_Dir)/fct.o $(OBJ_Dir)/ar_bin.o $(OBJ_Dir)/comp.o

clean:
	rm -f $(OBJ_Dir)/*.o