HEADERS_PATH = include/
SOURCE = source/*
HEADERS = $(HEADERS_PATH)
FLAGS = -Wall -ansi -pedantic
OBJECT = magic

$(OBJECT): $(SOURCE) $(HEADERS)
	gcc $(SOURCE) -I $(HEADERS_PATH) -o $(OBJECT) $(FLAGS)