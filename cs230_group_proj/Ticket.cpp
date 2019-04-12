#include "Ticket.h"
#include <iostream>

using namespace std;
//defaut constructor
Ticket::Ticket(){
	setTickID("");
	setOwnID("");
	setTechName1("");
	setTechName2("");
	setWorkHours1(0);
	setWorkHours2(0);
	setExpertise1(0);
	setExpertise2(0);
	setParts("");
	setPartCost(0);
	setIssue("");
	setStatus("Pending");
	setInstallDate("");
	setFinishDate("");
}
//mutator definitions
void Ticket::setTickID(string tickid){
	tickid = tickid;
}
void Ticket::setOwnID(string ownid){
	ownid = ownid;
}
void Ticket::setTechName1(string techname){
	techname1 = techname;
}
void Ticket::setTechName2(string techname){
	techname2 = techname;
}
void Ticket::setWorkHours1(double workhours){
	workhours1 = workhours;
}
void Ticket::setWorkHours2(double workhours){
	workhours2 = workhours;
}
void Ticket::setExpertise1(int expertise){
	expertise1 = expertise;
}
void Ticket::setExpertise2(int expertise){
	expertise2 = expertise;
}
void Ticket::setParts(string parts){
	parts = parts;
}
void Ticket::setPartCost(double partcost){
	partcost = partcost;
}
void Ticket::setIssue(string issue){
	issue = issue;
}
void Ticket::setStatus(string status){
	status = status;
}
void Ticket::setInstallDate(string installdate){
	installdate = installdate;
}
void Ticket::setFinishDate(string finishdate){
	finishdate = finishdate;
}
//accessor definitions
string Ticket::getTickID(){
	return tickid;
}
string Ticket::getOwnID(){
	return ownid;
}
string Ticket::getTechName1(){
	return techname1;
}
string Ticket::getTechName2(){
	return techname2;
}
double Ticket::getWorkHours1(){
	return workhours1;
}
double Ticket::getWorkHours2(){
	return workhours2;
}
int Ticket::getExpertise1(){
	return expertise1;
}
int Ticket::getExpertise2(){
	return expertise2;
}
string Ticket::getParts(){
	return parts;
}
double Ticket::getPartCost(){
	return partcost;
}
string Ticket::getIssue(){
	return issue;
}
string Ticket::getStatus(){
	return status;
}
string Ticket::getInstallDate(){
	return installdate;
}
string Ticket::getFinishDate(){
	return finishdate;
}

