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
void Ticket::setTickID(string tickid_input){
	tickid = tickid_input;
}
void Ticket::setOwnID(string ownids_input){
	ownid = ownids_input;
}
void Ticket::setTechName1(string techname_input){
	techname1 = techname_input;
}
void Ticket::setTechName2(string techname_input){
	techname2 = techname_input;
}
void Ticket::setWorkHours1(double workhours_input){
	workhours1 = workhours_input;
}
void Ticket::setWorkHours2(double workhours_input){
	workhours2 = workhours_input;
}
void Ticket::setExpertise1(int expertise_input){
	expertise1 = expertise_input;
}
void Ticket::setExpertise2(int expertise_input){
	expertise2 = expertise_input;
}
void Ticket::setParts(string parts_input){
	parts = parts_input;
}
void Ticket::setPartCost(double partcost_input){
	partcost = partcost_input;
}
void Ticket::setIssue(string issue_input){
	issue = issue_input;
}
void Ticket::setStatus(string status_input){
	status = status_input;
}
void Ticket::setInstallDate(string installdate_input){
	installdate = installdate_input;
}
void Ticket::setFinishDate(string finishdate_input){
	finishdate = finishdate_input;
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

