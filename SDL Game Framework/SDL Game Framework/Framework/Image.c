#include "stdafx.h"
#include "Image.h"
#include "App.h"
#include "Input.h"
bool Image_Init(void)
{
	int32 imageFlag = IMG_INIT_PNG | IMG_INIT_JPG;
	int32 imageLibResult = IMG_Init(imageFlag);
	if (imageFlag != (imageFlag & imageLibResult))
	{
		return false;
	}

	return true;
}

void Image_Cleanup(void)
{
	IMG_Quit();
}

void Image_LoadImage(Image* image, const char* filename)
{
	LogInfo("Image Loading... %s", filename);
	
	static char path[MAX_PATH];

	sprintf_s(path, sizeof(path), "%s/%s", IMAGE_DIRECTORY, filename);
	image->Texture = IMG_LoadTexture(g_App.Renderer, path);
	SDL_QueryTexture(image->Texture, NULL, NULL, &image->Width, &image->Height);
	image->ScaleX = image->ScaleY = 1.0f;

	SDL_SetTextureBlendMode(image->Texture, SDL_BLENDMODE_BLEND);
}

void Image_FreeImage(Image* image)
{
	SDL_DestroyTexture(image->Texture);
	image->Texture = NULL;
}

void Image_SetAlphaValue(Image* image, uint8 alpha)
{
	SDL_SetTextureAlphaMod(image->Texture, alpha);
}

int32 Count;

void Image_Choice(Image* image)
{
	for (int32 i = 0; i < 3; i++)
	{
		Image_SetAlphaValue(image, 50);
		if (Count == i)
		{
			Image_SetAlphaValue(image, 200);
		}

		
	}

}