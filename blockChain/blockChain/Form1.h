#pragma once
#include <vector>
#include <iomanip>
#include <functional>
#include <iostream>
#include <sstream>
#include <vcclr.h>

namespace CppCLRWinformsProjekt {
	namespace otherClass {
		

		//¼Û°ÇÈñ°¡ ¸¸µë
		class Block {

		public:
			std::string data;
			int hash;
			Block(std::string data, int previouesHash) {
				this->data = data;
				this->hash = createOwnHash();
			}
			int createOwnHash() {
				std::string datahash = int_to_string(hash) + data;
				int localHash = makeHash(datahash);
				return localHash;
			}
			std::string int_to_string(int input) {
				std::stringstream stringStraemer;
				std::string output;
				stringStraemer << input;
				stringStraemer >> output;

				return output;
			}
			int makeHash(std::string input) {
				std::hash<std::string> str_hash;
				int output = str_hash(input);

				return output;
			}
		};

		Block *initialBlock = new Block("initial data", 123);
		std::vector<Block*> blockChain = {initialBlock};
	}

	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	using namespace otherClass;

	/// <summary>
	/// Zusammenfassung f? Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzuf?en.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::TextBox^ nameInput;
	private: System::Windows::Forms::TextBox^ dataInput;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f? die Designerunterst?zung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge?dert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->nameInput = (gcnew System::Windows::Forms::TextBox());
			this->dataInput = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 220);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(360, 53);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ºí·Ï »ý¼º";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3
			});
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(13, 13);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(362, 141);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"name";
			this->columnHeader1->Width = 76;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"data";
			this->columnHeader2->Width = 63;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"hash";
			this->columnHeader3->Width = 234;
			// 
			// nameInput
			// 
			this->nameInput->Location = System::Drawing::Point(114, 160);
			this->nameInput->Name = L"nameInput";
			this->nameInput->Size = System::Drawing::Size(261, 21);
			this->nameInput->TabIndex = 2;
			// 
			// dataInput
			// 
			this->dataInput->Location = System::Drawing::Point(114, 187);
			this->dataInput->Name = L"dataInput";
			this->dataInput->Size = System::Drawing::Size(261, 21);
			this->dataInput->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 187);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 12);
			this->label1->TabIndex = 4;
			this->label1->Text = L"data input";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 160);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 12);
			this->label2->TabIndex = 5;
			this->label2->Text = L"name input";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(750, 362);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataInput);
			this->Controls->Add(this->nameInput);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		int createHash(std::string input) {
			std::hash<std::string> str_hash;
			int output = str_hash(input);

			return output;
		}

		std::string int_to_string(int input) {
			std::stringstream stringStraemer;
			std::string output;
			stringStraemer << input;
			stringStraemer >> output;

			return output;
		}

		// System::string -> std::string
		void MarshalString(String^ input, std::string& output) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(input)).ToPointer();
			output = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		// std::string -> System::string
		void stdString(std::string input, String^& output) {
			std::string str = input;
			output = gcnew String(str.data());
		}

		void clearInputbox(){
			dataInput->Clear();
			nameInput->Clear();
		}
		
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int chainSize = blockChain.size();
		int latestBlockHash = blockChain[chainSize - 1]->hash;
		std::string data_of_block;
		MarshalString(dataInput->Text, data_of_block);

		Block* newBlock = new Block(data_of_block, latestBlockHash);
		blockChain.push_back(newBlock);

		ListViewItem^ blockInfo = gcnew ListViewItem(nameInput->Text);
		blockInfo->SubItems->Add(dataInput->Text);
		String^ dataHash;
		stdString(int_to_string(newBlock->hash), dataHash);
		blockInfo->SubItems->Add(dataHash);

		listView1->Items->Add(blockInfo);

		clearInputbox();
	}

};


}