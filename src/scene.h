#pragma once
struct Scene
{

	// Private data.
	private:
		static Scene* currentScene;


	// Public members.
	public:

		// To be implemented.
		virtual void Initialize();
		virtual void DrawBackground2D();
		virtual void DrawForeground2D();
		virtual void Draw3D();
		virtual void Update();
		virtual void Cleanup();

		// To execute.
		static void ChangeScene(Scene* newScene);
		static void DoDrawBackground2D();
		static void DoDrawForeground2D();
		static void DoDraw3D();
		static void DoUpdate();

};

