#pragma once
#include <vector>
#include <iomanip>
#include <functional>
#include <iostream>
#include <sstream>
#include <map>

namespace CppCLRWinformsProjekt {
	namespace otherClass {
		using std::string;
		using std::vector;
		using std::map;

		class userAccountManager {
		public:
			vector<string> users;
			map<string, int> userWallet;

		public:
			userAccountManager() {
				users = {};
				userWallet = {};
			}
			userAccountManager(map<string, int> userWallet) {
				for (map<string, int>::iterator it = userWallet.begin(); it != userWallet.end(); ++it) {
					users.push_back(it->first);
				}
				this->userWallet = userWallet;
			}
			bool userExist(string targetUser) {
				for (vector<string>::iterator it = users.begin(); it != users.end(); ++it) {
					if (targetUser == it[0]) {
						return true;
					}
				}
				return false;
			}
			void appendUser(string userName, int money) {
				userWallet[userName] = money;
			}
		};

		class globalConditionManager {
		public:
			map<string, int> globalCondition;

		public:
			globalConditionManager() {
				this->globalCondition = {};
			}
			bool conditionExist(string type) {
				for (map<string, int>::iterator it = globalCondition.begin(); it != globalCondition.end(); ++it) {
					if (it->first == type) {
						return true;
					}
				}
				return false;
			}
			void appendCondition(string type) {
				globalCondition[type] = 0;
			}
		};

		userAccountManager* accountManager = new userAccountManager();

		globalConditionManager* conditionManager = new globalConditionManager();

		struct condition {
		public:
			string type;
			int target;

			condition(string type, int target) {
				this->type = type;
				this->target = target;
			}
		};

		class conditionChecklist {
		public:
			vector<condition> conditions;

			conditionChecklist() {
				conditions = {};
			}

			virtual bool isSatisfied() {
				for (vector<condition>::iterator it = conditions.begin(); it != conditions.end(); ++it)
				{
					condition con = it[0];
					if (conditionManager->globalCondition[con.type] != con.target) {
						return false;
					}
				}
				return true;
			}

			void appendCondition(condition condition) {
				conditions.push_back(condition);
			}
		};

		class smartContract {
		public:
			string sender;
			string receiver;
			int amount;

			conditionChecklist* conditions;

			smartContract() {}
			smartContract(string sender, string receiver, int amount, conditionChecklist* conditions) {
				this->sender = sender;
				this->receiver = receiver;
				this->amount = amount;
				this->conditions = conditions;
			}

			void activateContract() {
				if (this->conditions->isSatisfied()) {
					accountManager->userWallet[sender] -= amount;
					accountManager->userWallet[receiver] += amount;
				}
			}
		};

		//¼Û°ÇÈñ°¡ ¸¸µë
		class Block {

		public:
			string data;
			int hash;
			smartContract contract;
			
			Block(string data, int previousHash) {
				this->data = data;
				this->hash = createOwnHash(previousHash);
			}
			Block(string data, int previousHash, smartContract contract) {
				this->data = data;
				this->hash = createOwnHash(previousHash);
				this->contract = contract;
			}

			int createOwnHash(int previousHash) {
				string datahash = int_to_string(previousHash) + data;
				int localHash = makeHash(datahash);
				return localHash;
			}
			string int_to_string(int input) {
				std::stringstream stringStraemer;
				string output;
				stringStraemer << input;
				stringStraemer >> output;

				return output;
			}
			int makeHash(std::string input) {
				std::hash<string> str_hash;
				int output = str_hash(input);

				return output;
			}
		};

		

		Block* initialBlock = new Block("initial data", 123);
		vector<Block*> blockChain = { initialBlock };
		//smartContract* myContract = new smartContract("bob", "elisha", 500, myCondition);
		
		

		void notifyAllConditionToBlock() {
			for (vector<Block*>::iterator it = blockChain.begin(); it != blockChain.end(); ++it) {
				Block* blo = it[0];
				blo->contract.activateContract();
			
			}
		}
		
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
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::ListBox^ listBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ bob_wallet;
	private: System::Windows::Forms::TextBox^ bob_son_wallet;
	private: System::Windows::Forms::Button^ button2;
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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->bob_wallet = (gcnew System::Windows::Forms::TextBox());
			this->bob_son_wallet = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
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
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 12;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->listBox1->Location = System::Drawing::Point(429, 35);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(285, 76);
			this->listBox1->TabIndex = 6;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 12;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->listBox2->Location = System::Drawing::Point(429, 143);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(285, 76);
			this->listBox2->TabIndex = 7;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox2_SelectedIndexChanged);
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 12;
			this->listBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			this->listBox3->Location = System::Drawing::Point(429, 252);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(285, 76);
			this->listBox3->TabIndex = 8;
			this->listBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox3_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(427, 20);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 12);
			this->label3->TabIndex = 9;
			this->label3->Text = L"A";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(427, 128);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 12);
			this->label4->TabIndex = 10;
			this->label4->Text = L"B";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(427, 237);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(14, 12);
			this->label5->TabIndex = 11;
			this->label5->Text = L"C";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(112, 361);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(26, 12);
			this->label6->TabIndex = 12;
			this->label6->Text = L"bob";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(429, 360);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(62, 12);
			this->label7->TabIndex = 13;
			this->label7->Text = L"bob\'s son";
			// 
			// bob_wallet
			// 
			this->bob_wallet->Location = System::Drawing::Point(114, 377);
			this->bob_wallet->Name = L"bob_wallet";
			this->bob_wallet->Size = System::Drawing::Size(113, 21);
			this->bob_wallet->TabIndex = 14;
			// 
			// bob_son_wallet
			// 
			this->bob_son_wallet->Location = System::Drawing::Point(429, 376);
			this->bob_son_wallet->Name = L"bob_son_wallet";
			this->bob_son_wallet->Size = System::Drawing::Size(111, 21);
			this->bob_son_wallet->TabIndex = 15;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(277, 361);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 36);
			this->button2->TabIndex = 16;
			this->button2->Text = L"trade";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(719, 438);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->bob_son_wallet);
			this->Controls->Add(this->bob_wallet);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
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

			initialProjectSetting();

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

		void initialProjectSetting() {
			accountManager->appendUser("bob", 500);
			accountManager->appendUser("bob's son", 0);

			conditionManager->appendCondition("a");
			conditionManager->appendCondition("b");
			conditionManager->appendCondition("c");
		}

		void updateWalletInterface() {
			string bob_money = int_to_string(accountManager->userWallet["bob"]);
			
			string bob_son_money = int_to_string(accountManager->userWallet["bob's son"]);
			String^ interfaceMoney = "";
			stdString(bob_money, interfaceMoney);
			MessageBox::Show(interfaceMoney);
			bob_wallet->Text = interfaceMoney;

			stdString(bob_son_money, interfaceMoney);
			MessageBox::Show(interfaceMoney);
			bob_son_wallet->Text = interfaceMoney;
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
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		updateWalletInterface();
	}


private: System::Void listBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	string selectedItem;
	MarshalString(listBox2->SelectedItem->ToString(), selectedItem);
	conditionManager->globalCondition["B"] = std::stoi(selectedItem);
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	string selectedItem;
	MarshalString(listBox1->SelectedItem->ToString(), selectedItem);
	conditionManager->globalCondition["A"] = std::stoi(selectedItem);
}
private: System::Void listBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	string selectedItem;
	MarshalString(listBox3->SelectedItem->ToString(), selectedItem);
	conditionManager->globalCondition["C"] = std::stoi(selectedItem);
}

};


}