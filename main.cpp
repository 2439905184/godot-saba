#include <iostream>
#include <utility>
#include <string>
#include <memory>

int main()
{
	//loadStaticLib("libSaba.a");
	// Load model.
	std::shared_ptr<saba::MMDModel> mmdModel;
	std::string mmdDataPath = "kizunaai/kizunaai.pmx";	// Set MMD data path(default toon texture path).
	std::string ext = saba::PathUtil::GetExt(modelPath);
	if (ext == "pmd")
	{
		auto pmdModel = std::make_unique<saba::PMDModel>();
	if (!pmdModel->Load(modelPath, mmdDataPath))
	{
		std::cout << "Load PMDModel Fail.\n";
		return false;
	}
	mmdModel = std::move(pmdModel);
	}
	else if (ext == "pmx")
	{
		auto pmxModel = std::make_unique<saba::PMXModel>();
		if (!pmxModel->Load(modelPath, mmdDataPath))
		{
			std::cout << "Load PMXModel Fail.\n";
			return false;
		}
		mmdModel = std::move(pmxModel);
	}
	else
	{
		std::cout << "Unsupported Model Ext : " << ext << "\n";
		//return false;
	}
	std::cout << "Load Model Success.\n";
	std::cout << mmdModel ;
	return 0;
}