//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <iostream>
#include <string>
using namespace EncryptionApp;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}

Platform::String ^ convertFromString(const std::wstring & input)
{
	std::wstring w_str = std::wstring(input.begin(), input.end());
	const wchar_t* w_chars = w_str.c_str();

	return (ref new Platform::String(w_chars));
}

void EncryptionApp::MainPage::EncryptRadio_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//encrypt radio button
	Encrypting = true;
}


void EncryptionApp::MainPage::DecryptRadio_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//decrypt radio button
	Encrypting = false;
}
std::wstring encryptDecrypt(std::wstring &toEncrypt) {
	char key[3] = { 'K', 'C', 'Q' }; //Any chars will work, in an array of any size
	std::wstring output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

	return output;
}
std::wstring encryptDecrypt(std::wstring &toEncrypt, std::wstring &key) {
	//char key[3] = { 'K', 'C', 'Q' }; //Any chars will work, in an array of any size
	//wchar_t key[size];
	std::wstring output = toEncrypt;
	
	if (key.empty()){
		key = L"1234";
	}

	for (unsigned int i = 0; i < toEncrypt.size(); i++){
		int modulusQuotient = (key.length()/sizeof(char));
		output[i] = toEncrypt[i] ^ key[i % modulusQuotient];
	}
	
	return output;
}
void EncryptionApp::MainPage::EncryptButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Execute Button
	if (Encrypting) {
		std::wstring toEncrypt = InputBox->Text->Data();
		std::wstring key = KeyBox->Text->Data();
		std::wstring Encrypted = encryptDecrypt(toEncrypt,key);
		ResultBox->Text = convertFromString(Encrypted);
	}
	else if (!Encrypting) {
		std::wstring Encrypted = InputBox->Text->Data();
		std::wstring key = KeyBox->Text->Data();
		std::wstring Decrypted = encryptDecrypt(Encrypted,key);
		ResultBox->Text = convertFromString(Decrypted);
	}
	else {
		ResultBox->Text = "Error";
	}
}
