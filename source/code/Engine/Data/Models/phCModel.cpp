#include "phCModel.h"
#include "Systems/phServiceLocators.h"
#include "Systems/phCModelSystem.h"

phCModel::phCModel()
	: m_matrix( pm::mat4( 1 ) )
{
	Init();
}

phCModel::phCModel( const char* filePath )
	: phIAsset( filePath )
	  , m_matrix( pm::mat4( 1 ) )
{
	phCMesh* pMesh = newp phCMesh( filePath );
	pMesh->m_pParent = this;
	m_meshes.push_back( pMesh );
	Init();
}

void phCModel::Init()
{
	phCModelSystemLocator::GetService()->AddModel( this );
}

phCModel::~phCModel()
{
	for( phCMesh* pMesh : m_meshes )
	{
		delete pMesh;
	}
	phCModelSystemLocator::GetService()->RemoveModel( this );
}

void phCModel::Update()
{
	for( phCMesh* mesh : m_meshes )
	{
		mesh->Update();
	}
}
