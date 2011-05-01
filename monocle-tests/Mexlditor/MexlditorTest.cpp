
#include "MexlditorTest.h"

namespace MexlditorTest
{
	Text::Text(const std::string& text, FontAsset* font)
		: Entity(), font(font), text(text)
	{
	}

	void Text::Render()
	{
		Graphics::PushMatrix();
		Graphics::Translate(position);
		Graphics::SetBlend(BLEND_ALPHA);
		Graphics::SetColor(Color::white);
		Graphics::BindFont(font);

		Graphics::RenderText(*font, text, 0, 0);
		Graphics::PopMatrix();
	}

	/// WALL
	Wall::Wall(Vector2 pos, float w, float h)
		: Entity()
	{
		position = pos;
		AddTag("Wall");
		SetCollider(new RectangleCollider(w, h));
		this->width = w;
		this->height = h;
		canvas.CreateCanvas(w*2,h*2);

		// allocate a texture name
		glGenTextures( 1, &texture );

		// select our current texture
		glBindTexture( GL_TEXTURE_2D, texture );

		// select modulate to mix texture with color for shading
		glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

		// when texture area is small, bilinear filter the closest mipmap
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
						 GL_LINEAR_MIPMAP_NEAREST );
		// when texture area is large, bilinear filter the original
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

		// the texture wraps over at the edges (repeat)
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

		// build our texture mipmaps
		gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,
			GL_RGBA, GL_UNSIGNED_BYTE, &canvas.buffer[0] );

		Graphics::BindTexture(NULL);
	}

	void Wall::Render()
	{
		static float rot = 0;
		rot += 10;
		Graphics::PushMatrix();
		Graphics::Translate(position);
		//Graphics::Rotate(rot,0,0,1);
		
		canvas.Rand();
		
		glBindTexture(GL_TEXTURE_2D,texture);

		// build our texture mipmaps
		gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGBA, GL_UNSIGNED_BYTE, &canvas.buffer[0] );

		Graphics::SetColor( Color(1,1,1,1) );
		Graphics::RenderQuad(width, height);
		Graphics::BindTexture(NULL);
		Graphics::PopMatrix();
	}

	EditorScene::EditorScene()
	{

	}

	void EditorScene::Begin()
	{
		Scene::Begin();

		//set screen size
		//Graphics::Set2D(160, 120);
		//Graphics::SetCameraPosition(Vector2(80, 60));
		//GetCamera()->position = Vector2(80, 60);

		/*FontAsset* font = Assets::RequestFont("Pong/LiberationSans-Regular.ttf", 25.0f);
        scoreText = new Text("Some text is here", font);
        scoreText->position = Vector2(50, 50);
        Add(scoreText);*/

		Add(new Wall(Vector2(200.0f, 200.0), 100.0f, 100.0f));
		//Add(new Wall(Vector2(600.0f, 400.0), 100.0f, 10.0f));
		//Add(new Wall(Vector2(200.0f, 400.0), 20.0f, 150.0f));
	}

	void EditorScene::Update()
	{
		Scene::Update();

		static double lastTime = Monocle::timeSinceStart;
		static int fps = 0;
		static int frame = 0;
		
		
		if(Monocle::timeSinceStart - lastTime >= 1)
		{
			std::cout<<"\nFPS["<<frame<<"]";
			fps = frame;
			frame = 0;
			lastTime = Monocle::timeSinceStart;
		}

		frame++;

		///TESTEDITOR
		if (Input::IsKeyPressed(KEY_S) && Input::IsKeyHeld(KEY_LCTRL))
		{
			Debug::Log("save level...");
		}
	}
	
	void EditorScene::End()
	{
		Scene::End();
	}
}
