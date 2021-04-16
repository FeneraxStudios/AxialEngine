// Copyright Fenerax Studios. All Rights Reserved.

#include "AxialEngine.h"

class EditorApplication : public Axial::Application
{

};

int main(int argc, char** argv)
{
	EditorApplication* editor = new EditorApplication();
	return editor->Execute();
}