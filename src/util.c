int isNum(char c){
	int ascii = (int) c;
	ascii -= (int) '0';
	if(ascii >= 0 && ascii <= 9){
		return 1;
	}else{
		return 0;
	}
}