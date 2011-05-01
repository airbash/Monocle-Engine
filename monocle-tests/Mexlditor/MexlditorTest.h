#include <gl/glew.h>
#include <Monocle/Monocle.h>
#include "Mexlditor.h"

using namespace Monocle;

namespace MexlditorTest
{
	class Text: public Entity
	{
	public:
		Text(const std::string& text, FontAsset* font);

		void Render();

		void SetFont(FontAsset* font) { this->font = font; }
		void SetText(const std::string& text) { this->text = text; }

	protected:
		FontAsset* font;
		std::string text;
	};

	class Wall : public Entity
	{
	public:
		Wall(Vector2 p, float w, float h);
		//void Update();
		void Render();

		//temporary, replace base class with Sprite eventually
		float width, height;
		MexCanvas canvas;
		GLuint texture;
	};

	class EditorScene : public Scene
	{
		public:
		EditorScene();
		void Begin();
		void Update();
		void End();


		Text *scoreText;
	};
}