//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace EncryptionApp
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		bool Encrypting = true;
		void EncryptRadio_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void DecryptRadio_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void EncryptButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
