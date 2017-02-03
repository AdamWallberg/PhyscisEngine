#pragma once

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

	phIAsset(const char* assetName = "")
		: m_assetName(assetName)
	{
	}

	virtual EAssetType GetAssetType() = 0;

	virtual const char* GetAssetName() { return m_assetName; }

private:

	const char* m_assetName;

};