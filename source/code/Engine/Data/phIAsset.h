#pragma once

#include <string>

// Interface for all assets in the engine.
// Useful for grouping multiple assets together.
class phIAsset
{
public:

	enum EAssetType
	{
		ASSET_TYPE_MESH,
		ASSET_TYPE_MODEL,
		ASSET_TYPE_TEXTURE,
	};

	phIAsset();

	virtual EAssetType GetAssetType() = 0;

	virtual std::string& GetAssetName() { return m_assetName; }

private:

	std::string m_assetName;

};