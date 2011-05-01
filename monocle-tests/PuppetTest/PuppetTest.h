#include <Monocle/Monocle.h>
#include <Monocle/Puppet/PuppetEditor.h>

using namespace Monocle;

namespace PuppetTest
{
	class TestScene : public Scene
	{
	public:
		void Begin();
		void End();
        
        void Update();

	protected:
		PuppetEditor *puppetEditor;
	};
}
