int isNum(char c){
	int ascii = (int) c;
	ascii -= (int) '0';
	if(ascii >= 0 && ascii <= 9){
		return 1;
	}else{
		return 0;
	}
}

/*
 * I know this is the shitty way to do it,
 * but I did it this way anyway, get over it.
*/
int isBE(char c){
	if(c == '{')
		return 1;
	if(c == '}')
		return 1;
	if(c == '~')
		return 1;
	if(c == '|')
		return 1;
	
	return 0;
}
