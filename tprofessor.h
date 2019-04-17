#ifndef TPROFESSOR_H
#define TPROFESSOR_H
#include<string>
#include "tpessoa.h"

using std::string;

class TProfessor : public TPessoa
{
	private: 
		int codigoRegistro;
		float valorSalario;
	public:
		TProfessor(){
			tipo_da_pessoa = TIPO_PROFESSOR;
		}
		~TProfessor();
		void Set_codigoRegistro(int codigo){
			codigoRegistro = codigo;
		}
		int Get_codigoRegistro(){
			return codigoRegistro;
		}
		void Set_valorSalario(float valor){
			valorSalario = valor;
		}
		float Get_valorSalario(){
			return valorSalario;
		}
		
	protected:
};

#endif
