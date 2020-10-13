#include "DXUT.h"
#include "RenderManager.h"

RenderManager::RenderManager()
{
	Device->CreateVertexBuffer(sizeof(VerTex)*4,D3DUSAGE_WRITEONLY,VerTex::FVF,D3DPOOL_DEFAULT,&vb,NULL);

	VerTex * pVerTices = nullptr;
	vb->Lock(0,0,(void**)&pVerTices,0);
	pVerTices[0].pos = Vec3(-0.5f,0.5f,0.f);
	pVerTices[1].pos = Vec3(0.5f, 0.5f, 0.f);
	pVerTices[2].pos = Vec3(-0.5f, -0.5f, 0.f);
	pVerTices[3].pos = Vec3(0.5f, -0.5f, 0.f);

	pVerTices[0].uv = Vec2(0.f,0.f);
	pVerTices[1].uv = Vec2(1.f, 0.f);
	pVerTices[2].uv = Vec2(0.f,1.f);
	pVerTices[3].uv = Vec2(1.f, 1.f);
	vb->Unlock();
	Device->CreateIndexBuffer(sizeof(WORD)*6,D3DUSAGE_WRITEONLY,D3DFMT_INDEX16,D3DPOOL_DEFAULT,&ib,NULL);
	
	WORD idx[] = { 1,2,0,1,3,2 };
	void * pIndices = NULL;

	ib->Lock(0,0,&pIndices,0);
	memcpy(pIndices,idx,sizeof(WORD)*6);
	ib->Unlock();
	
	Device->SetStreamSource(0,vb,0,sizeof(VerTex));
	Device->SetFVF(VerTex::FVF);
	Device->SetIndices(ib);

	Device->SetRenderState(D3DRS_LIGHTING, FALSE);
	Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);

	D3DXMatrixOrthoLH(&matProj, 1980, 1080, 0, 100);
	Device->SetTransform(D3DTS_PROJECTION, &matProj);
	
	
	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &D3DXVECTOR3(0.f, 0.f, -100.f), &D3DXVECTOR3(0.f, 0.f, 0.f), &D3DXVECTOR3(0.f, 1.f, 0.f));
	Device->SetTransform(D3DTS_VIEW, &matView);
}

RenderManager::~RenderManager()
{
	ib->Release();
	vb->Release();
}

void RenderManager::Render(Texture * textureptr, Vec2 pos, Vec2 scale ,float rot)
{
	D3DXMATRIXA16 matP, matS, matR, matW;
	D3DXMatrixTranslation(&matP, pos.x, pos.y, -10);
	D3DXMatrixScaling(&matS, (textureptr->info.Width * scale.x)*0.2,(textureptr->info.Height *scale.y)*0.2, 1);
	D3DXMatrixRotationZ(&matR, rot);
	matW = matS * matR * matP;
	Device->SetTransform(D3DTS_WORLD, &matW);
	Device->SetTexture(0, textureptr->texturePtr);
	Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);

}
