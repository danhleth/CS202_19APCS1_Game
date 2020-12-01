#include"CGAME.h"

CGAME::CGAME() :axt(NULL), axh(NULL), akl(NULL), ac(NULL), cn() {}; //Chuẩn bị dữ liệu cho tất cả các đối tượng
void CGAME::drawGame() { 
}
CPEOPLE CGAME::getPeople() {//Lấy thông tin người
	CPEOPLE tmp;
	return tmp;
}
CVEHICLE* CGAME::getVehicle() {//Lấy danh sách các xe
	return NULL;
}
CANIMAL* CGAME::getAnimal() { //Lấy danh sách các thú
	return NULL;

}
void CGAME::resetGame() { // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	delete[] axt; axt = NULL;//don't have pointer in object
	delete[] axh; axh = NULL;
	delete[] akl; akl = NULL;
	delete[] ac;  ac = NULL;
	CPEOPLE tmp;
	cn = tmp;
}
void CGAME::exitGame(HANDLE t) { // Thực hiện thoát Thread
	system("cls");
	GotoXY(40, 10);
	printf("END GAME!!!\n");
	TerminateThread(t, 0);
	exit(1);
}
void CGAME::startGame() { // Thực hiện bắt đầu vào trò chơi
}
void CGAME::loadGame(istream) { // Thực hiện tải lại trò chơi đã lưu
}
void CGAME::saveGame(istream) { // Thực hiện lưu lại dữ liệu trò chơi
}
void CGAME::pauseGame(HANDLE) { // Tạm dừng Thread
}
void CGAME::resumeGame(HANDLE) { //Quay lai Thread
}
void CGAME::updatePosPeople(char) { //Thực hiện điều khiển di chuyển của CPEOPLE
}
void CGAME::updatePosVehicle() { //Thực hiện cho CTRUCK & CCAR di chuyển
}
void CGAME::updatePosAnimal() {//Thực hiện cho CDINAUSOR & CBIRD di chuyển	
}